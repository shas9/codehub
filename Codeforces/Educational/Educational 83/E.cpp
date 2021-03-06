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

ll arr[1003];
ll dp[505][505];
ll ans[505];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
            ans[i] = i;
        }

        memset(dp,-1,sizeof dp);

        for(ll sz = 1; sz <= n; sz++)
        {
            for(i = 1; i <= n; i++)
            {
                j = i + sz - 1;

                if(i == j) dp[i][j] = arr[i];

                for(k = i; k < j; k++)
                {
                    if(dp[i][k] != -1 && dp[i][k] == dp[k + 1][j])
                    {
                        dp[i][j] = dp[i][k] + 1;
                    }
                }
            }
        }

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                if(dp[j][i] == -1) continue;

                ans[i] = min(ans[i], ans[j - 1] + 1);
            }
        }

        cout << ans[n] << endl;
    }


}


