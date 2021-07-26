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

ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

    freopen("rtecase1.txt", "w", stdout);

    srand (time(NULL));

    n = rand() % 200001;
    q = rand() % 200001;

    if(n == 0) n++;
    if(q == 0) q++;

    n = 200000;
    q = 200000;

    cout << n << " " << q << endl;

    for(i = 1; i <= n; i++)
    {
        arr[i] = rand() % 100001;
        cout << arr[i] << " ";
    }

    cout << endl;

    for(i = 1; i <= q; i++)
    {
        ll xx = rand() % 2;

        xx++;

        ll yy = rand() % n;


        if(yy <= 0) yy = 1;

        yy = 1;

        if(xx == 1)
        {
            if(arr[yy] == 0)
            {
                xx = 2;
            }
        }

        if(xx == 2)
        {
            if(arr[yy] == 100000)
            {
                xx = 1;
            }
        }

        if(xx == 1)
        {
            arr[yy]--;
        }
        else
        {
            arr[yy]++;
        }

        cout << xx << " " << yy << endl;
    }


}


