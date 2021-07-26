// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

string s, p;

vector < ll > g[30];

bool solve(ll idx)
{
	ll now = -1;

//	for(ll i = idx; i < p.size(); i++) cout << p[i];
//	cout << endl;

	for(ll i = idx; i < p.size(); i++)
	{
		ll c = p[i] - 'a';

		auto it = upper_bound(g[c].begin(),g[c].end(),now);

		if(it == g[c].end()) return 0;

		now = *it;
	}

	return 1;
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
		cin >> s >> p;

		ll sz = p.size();

		ll idx = 0;

		bool yes = 0;

		for(i = 0; i < 26; i++) g[i].clear();

		for(i = 0; i < s.size(); i++) g[s[i] - 'a'].pb(i);

		for(i = 0; i <= sz; i++)
		{
			if(solve(idx))
			{
				yes = 1;
				break;
			}

			p += p[idx];
			idx++;
		}

		if(yes) cout << "Ekka is not a Liar!\n";
		else cout << "Ekka is a Liar!\n";
    }


}



