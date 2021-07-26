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

string ass(string a, string b)
{
	for(int i = 0; i < min(a.size(), b.size()); i++)
	{
		if(a[i] < b[i]) return a;
		if(b[i] < a[i]) return b;
	}

	if(a.size() < b.size()) return a;
	return b;
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
		string str;
		ll rat = 0;

		ll mxrat = -1000000000;
		string out = "";

		slld(n);

		for(ll i = 1; i <= n; i++)
		{
			cin >> str >> rat;

			if(rat > mxrat) out = str;
			else if(rat == mxrat)
			{
				out = ass(out,str);
			}

			mxrat = max(rat,mxrat);
		}

		cout << out << '\n';

    }


}






