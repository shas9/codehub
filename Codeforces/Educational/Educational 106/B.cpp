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

string s;

map < pair < string, bool > , bool > dp[2];

bool solve(string ss, ll pos, bool took)
{
    if(dp[took].find({ss, pos}) != dp[took].end()) return dp[took][{ss, pos}];

    bool &ret = dp[took][{ss,pos}];

    if(ss.size() > s.size())
    {
        for(ll i = 1; i < ss.size(); i++)
        {
            if(ss[i] == '0' && ss[i - 1] == '1') return ret = 0;
        }

        return ret = 1;
    }

    if(took)
    {
        if(ss.back() == '1' && s[pos] == '0') return ret = 0;

        return ret = solve(ss + s[pos], pos + 1, 0);
    }

    if(ss.back() <= s[pos]) ret = solve(ss + s[pos], pos + 1, 0);

    if(ret) return 1;

    return ret = solve(ss, pos + 1, 1);

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

        dp[0].clear();
        dp[1].clear();

        if(solve("0", 0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }


}


