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

string s;

bool solve(ll k)
{
	ll n = s.size();

	for(ll i = 0; i + k < n; i++)
	{
		if(s[i] == '?' && s[i + k] == '?') continue;

		if(s[i] == '?') s[i] = s[i + k];
		else if(s[i + k] == '?') s[i + k] = s[i];

		if(s[i] != s[i + k]) return 0;
	}

	ll o = 0, z = 0;

	for(ll i = 0; i < k; i++)
	{
		o += s[i] == '1';
		z += s[i] == '0';
	}

	for(ll i = k; i <= n; i++)
	{
		if(o > (k / 2) || z > (k / 2)) return 0;

		o -= s[i - k] == '1';
		z -= s[i - k] == '0';

		if(i == n) break;

		o += s[i] == '1';
		z += s[i] == '0';
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
		cin >> n >> k >> s;

		if(solve(k)) cout << "YES\n";
		else cout << "NO\n";
	}


}



