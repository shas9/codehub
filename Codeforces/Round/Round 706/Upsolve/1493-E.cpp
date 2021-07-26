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

string s, t;

const ll mod = (1e9 + 7);
bool diff()
{
	ll base = 1;

	ll ss = 0, tt = 0;

	for(ll i = t.size() - 1; i >= 0; i--)
	{
		if(t[i] == '1') tt = (tt + base) % mod;
		if(s[i] == '1') ss = (ss + base) % mod;

		base = (base * 2) % mod;
	}

	if(ss >= tt) tt += mod;

	return abs(tt - ss) != 1;
}

bool diff2()
{
	if(t.back() == s.back()) return 1;

	for(ll i = 0; i < t.size(); i++)
	{
		if(t[i] == s[i]) continue;

		for(ll j = i + 1; j < t.size(); j++) if(t[i] == '1') return 1;
		for(ll j = i + 1; j < t.size(); j++) if(s[i] == '0') return 1;

		return 0;
	}

	assert(0);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;

    while(cin >> n >> s >> t)
    {
		if(s == t) cout << s << "\n";
		else if(s.front() == '0')
		{
			for(ll i = 1; i <= n; i++) cout << 1;
			cout << "\n";
		}
		else if(t.back() == '1') cout << t << "\n";
		else
		{
			if(diff())
			{
				t.back() = '1';
			}

			cout << t << "\n";
		}
    }


}


