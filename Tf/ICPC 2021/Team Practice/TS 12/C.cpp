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

set < ll > st[2];
vector < ll > dp[100005];
map < ll, ll > mp[2];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(ll i = 1; i <= n; i++)
        {
            cin >> m;

            st[i % 2].clear();
            dp[i].assign(m + 3, -1);
            mp[i % 2].clear();

            if(i == 1)
            {
                for(ll j = 1; j <= m; j++)
                {
                    cin >> in;
                    st[i % 2].insert(-in);
                    mp[i % 2][-in] = j;
                }
            }
            else
            {
                bool op = (i % 2) ^ 1;

                for(ll j = 1; j <= m; j++)
                {
                    cin >> in;

                    auto it = st[op].lower_bound(-in);

                    if(it == st[op].end()) continue;

                    st[op ^ 1].insert(-in);

                    mp[op ^ 1][-in] = j;

                    dp[i][j] = mp[op][*it];
                }
            }
        }

        if(st[n % 2].size() == 0) cout << "No\n";
        else
        {
            cout << "Yes\n";

            ll num = *st[n % 2].begin();
            ll idx = mp[n % 2][num];

            vector < ll > v;

            for(ll i = n; i >= 1; i--)
            {
                v.push_back(idx);

                idx = dp[i][idx];
            }

            reverse(v.begin(), v.end());
            for(auto it: v)
            {
                cout << it << " ";
            }

            cout << "\n";
        }

    }


}

