
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

map < string, ll > mp;
string str;
ll dp[100005];
bool on;

ll solve(ll pos)
{
//    cout << pos << endl;
    ll &ret = dp[pos];

    if(ret != -1) return ret;

    if(pos == str.size()) return 1;

    string s = "";

    ret = 0;

    for(ll i = pos, j = 1; i < str.size(), j <= 5; i++, j++)
    {
        s += str[i];

        ll f = mp[s];

        if(f)
        {
            ret += f * solve(i + 1);
        }
    }

    if(ret > 1) on = 1;

    ret %= 128;

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        mp.clear();

        cin >> n >> m;

        for(ll i = 0; i <= n; i++) dp[i] = -1;

        for(ll i = 1; i <= m; i++)
        {
            string a, b;
            cin >> a >> b;

            mp[b]++;
        }

        cin >> str;

        on = 0;
        ll ans = solve(0);

        if(on) cout << "puppymousecat " << ans << "\n";
        else
        {
            if(ans) cout << "happymorsecode\n";
            else cout << "nonono\n";
        }
    }


}

