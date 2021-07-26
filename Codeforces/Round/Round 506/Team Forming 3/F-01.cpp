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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[100005];
ll nexx[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m)
    {
        memset(arr,-1,sizeof arr);
        flag = 0;


        for(i = 1; i <= m; i++)
        {
            slld(l);
            slld(r);
            slld(q);

            if(flag) continue;
            bool on = 0;

            for(j = l; j <= r; j++)
            {
                if(arr[j] != -1)
                {
                    if(arr[j] == q) on = 1;

                    if((arr[j] & q) != q)
                    {
                        if((arr[j] & q) != arr[j])
                        {
                            flag = 1;
                            break;
                        }
                        else arr[j] = max(arr[j],q);
                    }
                    else
                    {
                        j = nexx[j];
                    }
                }
                else
                {
                    nexx[j] = r;
                    arr[j] = q;
                    on = 1;
                }
            }

            if(on == 0) flag = 1;
        }

        if(flag)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for(i = 1; i <= n; i++)
        {
            arr[i] = max(arr[i],0LL);
            cout << arr[i] << " ";
        }

        cout << endl;
    }


}



