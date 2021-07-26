// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

pll dp[100][100];
pll arr[100];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        ll sum = 0;

        for(ll i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second, sum += arr[i].first * arr[i].second;

        for(ll i = 0; i < 70; j++) dp[0][i] = {1,sum};

        ans = 0;

        for(ll i = 1; i <= m; i++)
        {
            for(ll ii = 0; ii < i; ii++)
            {
                for(ll jj = 1; jj < 65; jj++)
                {
                    __int128 gun = dp[ii][jj].first;
                    __int128 sum = dp[ii][jj].second;

                    for(ll j = 1; j <= 65; j++)
                    {
                        gun *= arr[i].first;
                        if()
                    }
                }

            }


        }


    }

}
