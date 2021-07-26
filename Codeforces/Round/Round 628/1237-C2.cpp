#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct node
{
    ll x, y, z, id;
};
node arr[100005];

ll n;

bool comp(node a, node b)
{
    if(a.z != b.z) return a.z < b.z;

    if(a.y != b.y) return a.y < b.y;

    return a.x < b.x;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i].x);
        slld(arr[i].y);
        slld(arr[i].z);

        arr[i].id = i;
    }

    sort(arr + 1, arr + 1 + n, comp);

//    for(i = 1; i <= n; i++)
//    {
//        cout << arr[i].z << " " << arr[i].y << " " << arr[i].x << " = " << arr[i].id << endl;
//    }

    deque < ll > y_v;

    for(i = 1; i <= n; )
    {
        ll zz = arr[i].z;

        while(zz == arr[i].z && i <= n)
        {
            ll yy = arr[i].y;

            bool on = 0;
            ll idd = 0;

            while(yy == arr[i].y && i <= n && zz == arr[i].z)
            {
                if(on == 0)
                {
                    idd = arr[i].id;
                }
                else
                {
                    cout << idd << " " << arr[i].id << endl;
                }

                i++;
                on ^= 1;
            }

            if(on)
            {
                y_v.push_back(idd);
            }
        }

        ll sz = y_v.size();

        while(sz >= 2)
        {
            cout << y_v[sz - 1] << " " << y_v[sz - 2] << endl;
            y_v.pop_back();
            y_v.pop_back();

            sz -= 2;
        }
    }
}


