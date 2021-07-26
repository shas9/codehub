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
//
//double dp[12][12];
//bool vis[12][12];
long double c, m, p, v;
//
//long double calc(ll x, ll y)
//{
//    long double ret = 1;
//
//    for(ll i = 0; i < x; i++)
//    {
//        ret *= c - (i * v);
//    }
//
//    for(ll i = 0; i < y; i++)
//    {
//        ret *= m - (i * v);
//    }
//
//    ret *= (p + ((x + y) / 10.0)) * (x + y + 1);
//
//    return ret;
//}


//long double solve(ll cntc, ll cntm)
//{
//    if(vis[cntc][cntm]) return dp[cntc][cntm];
//
//    vis[cntc][cntm] = 1;
//
//    long double &ret = dp[cntc][cntm];
//
//    ret = calc(cntc, cntm);
//
//    if(cntc * c < v) ret += solve(cntc + 1, cntm);
//    if(cntm * m < v) ret += solve(cntc, cntm + 1);
//
//    return ret;
//}

long double dfs(string s)
{
    long double ret = 1;

    long double tc = c, tm = m, tp = p;

    for(auto it: s)
    {
        if(it == 'C')
        {
            ret *= tc;

            if(tm > 0 && abs(tm - 0.000001) > 0.000001)
            {
                tm += (min(v,tc) / 2);
                tp += (min(v,tc) / 2);
            }
            else
            {
                tp += min(v,tc);
            }


            tc -= v;
        }
        else
        {
            ret *= tm;

            if(tc > 0 && abs(tc - 0.000001) > 0.000001)
            {
                tc += (min(v,tm) / 2);
                tp += (min(v,tm) / 2);
            }
            else
            {
                tp += min(v,tm);
            }

            tm -= v;
        }
    }

    ret *= tp;

//    cout << s << " " << ret << " " << tc << " " << tm << "\n";

    ret *= (s.size() + 1);

    if(tc > 0 && abs(tc - 0.000001) > 0.000001) ret += dfs(s + 'C');
    if(tm > 0 && abs(tm - 0.000001) > 0.000001) ret += dfs(s + 'M');

    return ret;
}

int main()
{
    ll i, j, k, l, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> c >> m >> p >> v;

//        memset(vis,0,sizeof vis);

        long double ans = dfs("");

        cout << setprecision(10) << fixed << ans << "\n";
    }


}


