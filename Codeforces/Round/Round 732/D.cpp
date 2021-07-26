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

const ll mod = 998244353;

ll calc(ll x)
{
    ll ret = 0;

    ret = (x * (x + 1)) / 2;

    return ret %= mod;
}

ll solve(string &s)
{
    ll ret = 1;
    ll zero = 0;

    for(ll i = 0; i + 1 < s.size(); i++)
    {
        if(s[i] == '0')
        {
            zero++;
            continue;
        }


        if(s[i + 1] == '1')
        {
            ret = (ret + (ret + 1) * zero) % mod;
            i++;
        }

//        zero = 0;

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
        cin >> n;

        string s;

        cin >> s;

        ans = solve(s);
        reverse(s.begin(), s.end());
        ans += solve(s);

        cout << ans << "\n";
    }


}


