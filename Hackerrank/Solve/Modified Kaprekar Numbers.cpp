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

vector < ll > vec;

bool karp(ll x)
{
	ll y = x * x;

	string str1, str2, str;

	while(y)
	{
		str += (y % 10) + '0';

		y /= 10;
	}

	reverse(str.begin(),str.end());

	ll sz = str.size() / 2;

	for(ll i = 0; i < str.size(); i++)
	{
		if(i < sz) str1 += str[i];
		else str2 += str[i];
	}


	ll a = 0, b = 0;

	for(auto it: str1)
	{
		a *= 10;
		a += (it - '0');
	}

	for(auto it: str2)
	{
		b *= 10;
		b += (it - '0');
	}

//	if( x <= 1000) cout << x << " " << str << " " << str1 << " " << str2 << endl;

	return a + b == x;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	for(ll i = 1; i <= 100000;i++)
	{
		if(karp(i)) vec.push_back(i);
	}

	slld(l);
	slld(r);

	bool on = 0;

	for(auto it: vec)
	{
		if(it > r) break;

		if(it >= l) cout << it << " ", on = 1;
	}

	if(on == 0) cout << "INVALID RANGE";

	cout << "\n";



}



