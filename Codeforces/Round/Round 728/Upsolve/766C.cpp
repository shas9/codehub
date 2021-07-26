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

vector < ll > v(26);
string s;
ll dp[1003];

const ll mod = (1e9 + 7);

ll solve1(ll pos)
{
    ll &ret = dp[pos];

    if(ret != -1) return ret;

    if(pos == s.size()) return ret = 1;

    set < ll > st;
    ll cnt = 0;

    ret = 0;

    for(ll i = pos; i < s.size(); i++)
    {
        ll x = s[i] - 'a';

        st.insert(x);

        cnt++;

        for(auto it: st)
        {
//            cout << it << " ++ " << v[it] << " " << cnt << "\n";
            if(v[it] < cnt) return ret %= mod;
        }

//        cout << pos << " " << i << " " << cnt << "\n";

        ret = ret + solve1(i + 1);
    }

    return ret %= mod;
}

ll solve2(ll pos)
{
    ll &ret = dp[pos];

    if(ret != -1) return ret;

    if(pos == s.size()) return ret = 0;

    set < ll > st;

    ret = 0;
    ll cnt = 0;

    for(ll i = pos; i < s.size(); i++)
    {
        ll x = s[i] - 'a';

        st.insert(x);

        for(auto it: st)
        {
            if(v[it] <= cnt) return ret = max(ret, cnt);
        }

        cnt++;

        ret = max(ret, solve2(i + 1));
    }

    return ret = max(ret, cnt);
}

ll solve3(ll pos)
{
    ll &ret = dp[pos];

    if(ret != -1) return ret;

    if(pos == s.size()) return ret = 0;

    set < ll > st;

    ll cnt = 0;

    ret = mxlld;

    for(ll i = pos; i < s.size(); i++)
    {
        ll x = s[i] - 'a';

        st.insert(x);

        cnt++;

        for(auto it: st)
        {
            if(v[it] < cnt) return ret;
        }

        ret = min(ret, solve3(i + 1) + 1);
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

    while(cin >> n)
    {
        cin >> s;

        for(auto &it: v) cin >> it;

        memset(dp,-1,sizeof dp);
        cout << solve1(0) << "\n";

        memset(dp,-1,sizeof dp);
        cout << solve2(0) << "\n";

        memset(dp,-1,sizeof dp);
        cout << solve3(0) << "\n";
    }


}
