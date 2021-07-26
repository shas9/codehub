// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

bool dp[101][101][10001];
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    dp[1][1][0] = 1;

    for(ll i = 1; i <= 100; i++)
    {
        for(ll j = 1; j <= 100; j++)
        {
            if(i == 1 && j == 1) continue;

            for(ll k = 0; k + i <= 10000; k++)
            {
                if(dp[i][j - 1][k])
                {
                    dp[i][j][k + i] = 1;
                }
            }

            for(ll k = 0; k + j <= 10000; k++)
            {
                if(dp[i - 1][j][k])
                {
                    dp[i][j][k + j] = 1;
                }
            }
        }
    }

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m >> k;

        if(dp[n][m][k]) cout << "YES\n";
        else cout << "NO\n";
    }


}

