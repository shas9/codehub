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

string s, t, x;

bool div()
{
//	cout << x << " " << s << "\n";
	if(x.size() % s.size()) return 0;

	for(ll i = 0; i < x.size(); i++)
	{
		ll pos = i % s.size();

		if(x[i] != s[pos]) return 0;
	}

	return 1;
}
string solve()
{
	if(t.size() < s.size()) swap(s,t);

	ll cnt = 20;

	x = "";

	while(cnt--)
	{
		x += t;

		if(div()) return x;
	}

	return "-1";
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
		cin >> s >> t;

		cout << solve() << "\n";
    }


}



