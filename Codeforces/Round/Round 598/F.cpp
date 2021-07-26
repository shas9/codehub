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

ll freq[2][27];
string s, t;

bool solve(ll len)
{
	memset(freq,0,sizeof freq);

	ll invs, invt;
	invs = invt = 0;

	for(auto it: s)
	{
		freq[0][it - 'a']++;

		for(ll i = (it - 'a') + 1; i < 26; i++)
		{
			invs += freq[0][i];
		}
	}

	for(auto it: t)
	{
		freq[1][it - 'a']++;

		for(ll i = (it - 'a') + 1; i < 26; i++)
		{
			invt += freq[1][i];
		}
	}

	bool one = 0;

	for(ll i = 0; i < 26; i++)
	{
		if(freq[0][i] != freq[1][i]) return 0;

		if(freq[0][i] > 1) one = 1;
	}

	if(one) return 1;

	return invs % 2 == invt % 2;
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
		slld(n);
		cin >> s >> t;

		if(solve(n)) printf("YES\n");
		else printf("NO\n");
    }


}



