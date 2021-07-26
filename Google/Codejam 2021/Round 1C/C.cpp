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

ll dp[(1 << 20)];
ll e;

ll bnot(ll x)
{
    if(x == 0) return 1;

    ll ret = 0;

    bool on = 0;

    for(ll i = 20; i >= 0; i--)
    {
        if(check(x,i)) on = 1;

        if(on && check(x,i) == 0) ret = Set(ret, i);
    }

    return ret;
}

ll solve(ll s)
{
    for(ll i = 0; i < (1 << 20); i++) dp[i] = mxlld;

    queue < ll > q;
    q.push(s);
    dp[s] = 0;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

//        cout << top << " ";

        ll x = bnot(top);
        ll y = top * 2;

//        cout << x << " " << y << "\n";

        if(dp[x] > dp[top] + 1)
        {
            dp[x] = dp[top] + 1;
            q.push(x);
        }

        if(y < (1 << 20))
        {
            if(dp[y] > dp[top] + 1)
            {
                dp[y] = dp[top] + 1;
                q.push(y);
            }
        }
    }

    return dp[e];
}

string s;

ll conv()
{
    ll ret = 0;

    reverse(s.begin(), s.end());

    for(ll i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') ret = Set(ret, i);
    }

    return ret;
}


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
        cin >> s;

        n = conv();

        cin >> s;

        e = conv();

        ans = solve(n);

        cout << "Case #" << cs << ": ";

        if(ans >= 1e10) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }


}


