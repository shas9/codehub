// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

vector < pll > pnt;

ll solve(ll x, ll y)
{
    ll ret = 0;

    for(auto it: pnt)
    {
        ret += abs(x - it.first) + abs(y - it.second);
    }

    return ret;
}

pll solvex()
{
    ll lo = 0;
    ll hi = 1e10;
    ll ret1 = hi;

//    for(ll i = 0; i < 10; i++)
//    {
//		cout << " + " << solve(i,1) << endl;
//    }

    while(lo <= hi)
    {
        ll mid1 = lo + (hi - lo) / 3;
        ll mid2 = hi - (hi - lo) / 3;

        ll ans1 = solve(mid1, 0);
        ll ans2 = solve(mid2, 0);

        if(ans1 <= ans2)
        {
            ret1 = mid1;
            hi = mid2 - 1;
        }
        else
        {
            ret1 = mid2;
            lo = mid1 + 1;
        }
    }

    lo = 0;
    hi = 1e10;
    ll ret2 = hi;

    while(lo <= hi)
    {
        ll mid1 = lo + (hi - lo) / 3;
        ll mid2 = hi - (hi - lo) / 3;

        ll ans1 = solve(mid1, 0);
        ll ans2 = solve(mid2, 0);

        if(ans1 < ans2)
        {
            ret2 = mid1;
            hi = mid2 - 1;
        }
        else
        {
            ret2 = mid2;
            lo = mid1 + 1;
        }
    }

    return {ret1, ret2};
}

pll solvey()
{
    ll lo = 0;
    ll hi = 1e10;
    ll ret1 = hi;

    while(lo <= hi)
    {
        ll mid1 = lo + (hi - lo) / 3;
        ll mid2 = hi - (hi - lo) / 3;

        ll ans1 = solve(0, mid1);
        ll ans2 = solve(0, mid2);

        if(ans1 <= ans2)
        {
            ret1 = mid1;
            hi = mid2 - 1;
        }
        else
        {
            ret1 = mid2;
            lo = mid1 + 1;
        }
    }

    lo = 0;
    hi = 1e10;
    ll ret2 = hi;

    while(lo <= hi)
    {
        ll mid1 = lo + (hi - lo) / 3;
        ll mid2 = hi - (hi - lo) / 3;

        ll ans1 = solve(0, mid1);
        ll ans2 = solve(0, mid2);

        if(ans1 < ans2)
        {
            ret2 = mid1;
            hi = mid2 - 1;
        }
        else
        {
            ret2 = mid2;
            lo = mid1 + 1;
        }
    }

    return {ret1, ret2};
}

ll calc1()
{
    pll xx = solvex();
    pll yy = solvey();

//    cout << xx.first << " + " << xx.second << endl;
//    cout << yy.first << " - " << yy.second << endl;

    return (xx.second - xx.first + 1) * (yy.second - yy.first + 1);

}

ll calc()
{
    ll mnx = mxlld;
    ll mxx = mnlld;

    ll mny = mxlld;
    ll mxy = mnlld;

    for(auto it: pnt)
    {
        mnx = min(mnx, it.first);
        mxx = max(mxx, it.first);

        mny = min(mny, it.second);
        mxy = max(mxy, it.second);
    }

    return (mxx - mnx + 1) * (mxy - mny + 1);
}

bool cmp(pll a, pll b)
{
    return a.second < b.second;
}

ll calc2()
{
    sort(pnt.begin(), pnt.end());

    ll x1 = pnt.front().second;
    ll x2 = pnt.back().second;

    sort(pnt.begin(), pnt.end(), cmp);

    ll y1 = pnt.front().first;
    ll y2 = pnt.back().first;

    return (abs(x1 - x2) + 1) * (abs(y1 -y2) + 1);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        pnt.resize(n);

        for(auto &it: pnt) cin >> it.first >> it.second;

        ans = calc1();

        cout << ans << "\n";
    }


}



