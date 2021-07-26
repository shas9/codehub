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

#define eps 1e-9

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

double dp[100005];
bool vis[100005];
double p[100005];
ll money[100005];
ll lastsafe[100005];
ll n, m;

double calc(double res, ll w)
{
    double lo = 0, hi = 1e12, ret = 0;
    ll cnt = 200;

    while(cnt--) {
        double mid = (lo+hi) / 2;

        double hap = log(1+mid/w);

        if(abs(hap-res) <= eps)
            ret = mid;

        if(hap < res)
            lo = mid;
        else
            hi = mid;
    }

    return ret;
}

double solve(ll pos)
{
    double &ret = dp[pos];

    if(vis[pos]) return ret;

    if(pos > n)
    {
        return ret = 0;
    }

    vis[pos] = 1;
    ret = 0;

    ret = p[pos] * solve(pos + 1);
    ret = max(ret, p[pos] * log(1 + (money[pos] / (m * 1.0))));
    ret = max(ret, ret + (1 - p[pos]) * log(1 + (lastsafe[pos] / (m * 1.0))));

    return ret;
}

int main()
{
    ll i, j, k, l, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        memset(vis,0,sizeof vis);

        ll last = -1;

        for(ll i = 1; i <= n; i++)
        {
            string s;
            cin >> s >> p[i] >> money[i];

            if(last != -1) lastsafe[i] = last;
            if(s.front() == 's') last = money[i];

//            cout << last << "\n";
        }

       double ans = solve(1);

       cout << "$" << setprecision(2) << fixed << calc(ans,m) << "\n";


    }


}


