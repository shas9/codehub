 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > dv[200005];
ll dp[200005][25];
ll ncr[200005][30];
const ll mod = 998244353;

ll nCr(ll n, ll r)
{
    if(r == 0) return 1;
	if(r == 1) return n;
	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}

void sieve()
{
//    ll cnt = 0;
    for(ll i = 1; i <= 2e5; i++)
    {
        for(ll j = i + i; j <= 2e5; j += i)
        {
            dv[j].push_back(i);
//            cnt++;
        }
    }

//    cout << cnt << "\n";

    return;
}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();
    memset(ncr,-1,sizeof ncr);

    while(cin >> n >> m)
    {
        memset(dp,0,sizeof dp);

        for(ll i = 1; i <= m; i++) dp[i][0] = 1;

        for(ll i = 2; i <= m; i++)
        {
            for(auto it: dv[i])
            {
                for(ll j = 0; j < 20; j++)
                {
                    dp[i][j + 1] += dp[it][j];
                }
            }
        }

        ans = 0;

        for(ll i = 1; i <= m; i++)
        {
            for(ll j = 0; j < min(n,20LL); j++)
            {
//                cout << i << " & " << j << " : " << dp[i][j] << "\n";
                ans = (ans + dp[i][j] * nCr(n - 1, j)) % mod;
            }
        }

        cout << ans << "\n";
    }


}

