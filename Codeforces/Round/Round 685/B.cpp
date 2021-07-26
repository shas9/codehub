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

vector < ll > one;
vector < ll > z;
string s;

bool solve(ll l, ll r)
{
	l--;
	r--;

	if(l)
	{
		if(s[l] == '0')
		{
			if(z[l - 1]) return 1;
		}
		else
		{
			if(one[l - 1]) return 1;
		}
	}

	if(r < (one.size() - 1))
	{
		if(s[r] == '0')
		{
			ll tot = z.back() - z[r];
			if(tot) return 1;
		}
		else
		{
			ll tot = one.back() - one[r];
			if(tot) return 1;
		}
	}

	return 0;
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
		cin >> n >> m;

		one.clear();
		z.clear();

		cin >> s;

		for(auto it: s)
		{
			if(it == '1') one.push_back(1), z.push_back(0);
			else z.push_back(1), one.push_back(0);
		}

		for(ll i = 1; i < n; i++) one[i] += one[i - 1];
		for(ll i = 1; i < n; i++) z[i] += z[i - 1];

		for(ll i = 1; i <= m; i++)
		{
			cin >> l >> r;

			if(solve(l,r)) cout << "YES\n";
			else cout << "NO\n";
		}
    }


}




