// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

double dp[101][101][101];
bool vis[101][101][101];

double solve(ll r, ll s, ll p)
{
//	cout << r << " " << s << " " << p << endl;
    if(vis[r][s][p]) return dp[r][s][p];

    if((!r && !s) || (!r && !p) || (!p && !s)) return 1;

//	bug;

    ll rs = r * s;
    ll sp = s * p;
    ll pr = p * r;
    ll tot = rs + sp + pr;

    vis[r][s][p] = 1;

    if(s) dp[r][s][p] += (rs * solve(r, s - 1, p));
    if(r) dp[r][s][p] += (pr * solve(r - 1, s, p));
    if(p) dp[r][s][p] += (sp * solve(r, s, p - 1));

//	cout << dp[r][s][p] << " " << dp[r][s][p] / (tot * 1.0) << endl;
    return dp[r][s][p] = dp[r][s][p] / (tot * 1.0);

}

ll r, s, p;

bool solve1(ll rr, ll ss, ll pp)
{
    cout << rr << " " << ss << " " << pp << endl;

    if(rr > r || ss > s || pp > p) return 0;
    if(rr == r && ss == s && pp == p) return 1;

    bug;

    if(vis[rr][ss][pp]) return dp[rr][ss][pp];

    vis[rr][ss][pp] = 1;

    ll rs = rr * ss;
    ll sp = ss * pp;
    ll pr = pp * rr;
    ll tot = (rs + sp + pr);

    cout << rs << " " << sp << " " << pr << " = " << tot << endl;

    dp[rr][ss][pp] += ((rs + rr) * solve(rr,ss + 1,pp)) / ((tot + rr) + 1.0);
    dp[rr][ss][pp] += ((sp + ss) * solve(rr,ss,pp + 1)) / ((tot + ss) + 1.0);
    dp[rr][ss][pp] += ((pr + pp) * solve(rr + 1,ss,pp)) / ((tot + pp) + 1.0);

    return dp[rr][ss][pp];
}

bool solve2()
{
    dp[r][s][p] = 1;

    for(int pp = p; pp >= 0; pp--)
    {
        for(int ss = s; ss >= 0; ss--)
        {
            for(int rr = r; rr >= 0; rr--)
            {
//				cout << rr << " " << ss << " " << pp << endl;

                if(!rr && !pp) continue;
                if(!ss && !pp) continue;
                if(!ss && !rr) continue;

//				bug;

                ll rs = rr * ss;
                ll sp = ss * pp;
                ll pr = pp * rr;
                ll tot = rs + sp + pr;

//                cout << rr << " " << ss << " " << pp << " " << tot << " " << rs << " " << sp << " " << pr << endl;

                if(rr) dp[rr - 1][ss][pp] += dp[rr][ss][pp] * (pr / (tot * 1.0));
                if(ss) dp[rr][ss - 1][pp] += dp[rr][ss][pp] * (rs / (tot * 1.0));
                if(pp) dp[rr][ss][pp - 1] += dp[rr][ss][pp] * (sp / (tot * 1.0));
            }
        }
    }

//    for(int pp = p; pp >= 0; pp--)
//    {
//        for(int ss = s; ss >= 0; ss--)
//        {
//            for(int rr = r; rr >= 0; rr--)
//            {
//                cout << dp[rr][ss][pp] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    cin >> r >> s >> p;

    {
//        memset(dp,0,sizeof dp);

        double pr = 0, ps = 0, pp = 0;

        solve2();

        for(i = 1; i <= r; i++) pr += dp[i][0][0];
        for(i = 1; i <= s; i++) ps += dp[0][i][0];
        for(i = 1; i <= p; i++) pp += dp[0][0][i];


        printf("%.10lf %.10lf %.10lf\n", (double)pr, (double)ps, (double)pp);
    }


}



