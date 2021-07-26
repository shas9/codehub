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

vector < pll > vec;

ll solve(pll x, pll y, ll d = 0)
{
//    cout << x.first << " ++ " << x.second << "\n";
//    cout << y.first << " -- " << y.second << "\n";

    assert(d <= 5);

    ll ret = 0;

    if(x == y) return 0;

    if(x.second == y.second)
    {
        ll diff = y.first - x.first;

        ret = diff / 2;

        if((x.first + x.second) & 1 && diff & 1) ret++;

        return ret;
    }

    if((x.first - x.second) == (y.first - y.second))
    {
        if((x.first + x.second) & 1) return 0;

        return y.first - x.first;
    }

    ll diff = (y.first - y.second);
    ll diff1 = (x.first - x.second);


    ret = solve(x, {x.second + diff, x.second}, d + 1) + solve({x.second + diff, x.second}, y, d + 1);

    ret = min(ret, solve(x, {y.second + diff1, y.second}, d + 1) + solve({y.second + diff1, y.second}, y, d + 1));

    if(diff1 % 2 == 0) ret = min(ret, solve(x, {x.first + 1, x.second}, d + 1) + solve({x.first + 1, x.second}, y, d + 1));
    return ret;
}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        vec.resize(n);

        for(auto &it: vec) cin >> it.first;
        for(auto &it: vec) cin >> it.second;

        sort(vec.begin(), vec.end());

        pll now = {1,1};
        ll cost = 0;

        for(auto it: vec)
        {
//            cout << it.first << " &&& " << it.second << "\n";

            cost += solve(now, it);
            now = it;

//            cout << cost << '\n';
        }

        cout << cost << "\n";
    }

}



