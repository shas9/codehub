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

ll dp[5003][5003];
vector < ll > v;
set < ll > st;

ll solve(ll pos, ll booked)
{
    ll &ret = dp[pos][booked];
    if(ret != -1) return ret;
    if(pos == v.size()) return ret = 0;
    if(v[pos] == 0) return ret = solve(pos + 1, booked);

    auto it = st.lower_bound(pos);
    auto jt = st.upper_bound(pos);
    auto kt = st.lower_bound(booked);

    ret = 1e10;

    if(it != st.begin())
    {
        it--;
        if(*it >= booked) ret = min(ret, abs(*it - pos) + solve(pos + 1, *it + 1));
    }

    if(kt != st.end()) ret = min(ret, abs(*kt - pos) + solve(pos + 1, *kt + 1));


    if(jt == st.end()) return ret;
    if(*jt < booked) return ret;

    ret = min(ret, abs(*jt - pos) + solve(pos + 1, *jt + 1));

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
        memset(dp,-1,sizeof dp);

        v.resize(n);

        for(auto &it: v) cin >> it;

        ans = 0;

//        for(ll i = 0; i < n; i++)
//        {
//            if(v[i] != 1) continue;
//
//            ll lft = 0;
//            ll rgt = 0;
//            ll pos = i - 1;
//
//            while(pos >= 0)
//            {
//                lft++;
//                if(v[pos] == 0) break;
//                pos--;
//            }
//
//            if(pos < 0) lft = mxlld;
//
//            pos = i + 1;
//
//            while(pos < n)
//            {
//                rgt++;
//                if(v[pos] == 0) break;
//                pos++;
//            }
//
//            if(pos >= n) rgt = mxlld;
//
//            if(lft <= rgt) ans += lft, v[i - lft] = -1;
//            else
//            {
//                ll x = 0;
//
//                for(ll j = i; j < n; j++) x -= (v[j] == 1);
//                for(ll j = i + rgt; j < n; j++) x += (v[j] == 0);
//
//                if(x >= 0) ans += rgt, v[i + rgt] = -1;
//                else ans += lft, v[i - lft] = -1;
//            }
//        }

        st.clear();

        for(ll i = 0; i < n; i++) if(v[i] == 0) st.insert(i);

        ans = solve(0,0);

        reverse(v.begin(), v.end());

        memset(dp,-1,sizeof dp);

        st.clear();

        for(ll i = 0; i < n; i++) if(v[i] == 0) st.insert(i);

        ans = min(ans, solve(0,0));


        assert(ans >= (n - st.size()));

        cout << ans << "\n";
    }


}

