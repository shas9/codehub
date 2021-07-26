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

bool dp[101][200003];
bool vis[101][200003];
vector < ll > v;

bool solve(ll pos, ll sum, ll tsum)
{
    if(pos == v.size())
    {
        ll xsum = tsum - sum;

        if(xsum == sum) return 1;

        return 0;
    }

    if(vis[pos][sum]) return dp[pos][sum];

    vis[pos][sum] = 1;

    return dp[pos][sum] = solve(pos + 1, sum, tsum) | solve(pos + 1, sum + v[pos], tsum);
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        v.resize(n);
        for(auto &it: v) cin >> it;

        ll sum = accumulate(v.begin(), v.end(), 0);

        memset(vis,0,sizeof vis);

        if(sum & 1 || !solve(0,0,sum))
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";

            ll num = 0;
            ll last = 30;

            for(ll idx = 0; idx < v.size(); idx++)
            {
                for(ll i = 0; ;i++)
                {
                    if(check(v[idx],i))
                    {
                        if(i < last)
                        {
                            last = i;
                            num = idx;
                        }
                        break;
                    }
                }
            }

            cout << num + 1 << "\n";
        }
    }


}

