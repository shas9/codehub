 // Lights will guide you home

#include <bits/stdc++.h>

#define ll long long

using namespace std;

map < ll, ll > dp[20][2][2];

string rgt;
ll k;

ll solve(ll pos, bool issmall, bool start, ll prod)
{
    if(dp[pos][issmall][start].find(prod) != dp[pos][issmall][start].end()) return dp[pos][issmall][start][prod];

    if(rgt.size() == pos)
    {
        return dp[pos][issmall][start][prod] = start && prod <= k && prod != -1;
    }

    ll &ret = dp[pos][issmall][start][prod];

    ll hi = 9;

    if(issmall == 0) hi = rgt[pos] - '0';

    for(ll i = 0; i <= hi; i++)
    {
        bool newsmall = issmall;
        if(i < hi) newsmall = 1;

        if(i == 0)
        {
            if(start) ret += solve(pos + 1, newsmall, start, 0);
            else ret += solve(pos + 1, newsmall, 0,1);
        }
        else
        {
            if(prod == -1)
            {
                ret += solve(pos + 1, newsmall, 1, prod);
            }
            else
            {
                if(prod * i > k) ret += solve(pos + 1, newsmall, 1, -1);
                else ret += solve(pos + 1, newsmall, 1, prod * i);
            }
        }
    }

    return ret;

}

int main()
{
    while(cin >> rgt >> k)
    {
        for(ll i = 0; i <= 19; i++) for(ll j = 0; j < 2; j++) for(ll m = 0; m < 2; m++) dp[i][j][m].clear();

        ll ans = solve(0,0,0,1);

        cout << ans << "\n";
    }
}
