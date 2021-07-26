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

ll arr[105];

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll n;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n)
    {
        ll xx, yy;
        xx = yy = 0;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            if(arr[i] == 0) continue;

            if(arr[i] % 2) xx++;
            else yy++;
        }

        xx = ((n + 1) / 2) - xx;
        yy = (n / 2) - yy;

        for(i = 1; i <= n; i++)
        {
            if(arr[i] != 0)
            {
                for(j = i - 1; j >= 1; j--)
                {
                    if(arr[j] != 0) break;

                    if(arr[i] % 2)
                    {
                        if(xx)
                        {
                            arr[j] = 1;
                            xx--;
                        }
                        else
                        {
                            arr[j] = 2;
                            yy--;
                        }
                    }
                    else
                    {
                        if(yy)
                        {
                            arr[j] = 2;
                            yy--;
                        }
                        else
                        {
                            arr[j] = 1;
                            xx--;
                        }
                    }
                }
            }
        }

        ans = 0;

        for(i = 1; i <n; i++)
        {
            if((arr[i] + arr[i + 1]) % 2) ans++;
        }

        cout << ans << endl;
    }


}


