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


vector < ll > v1, v2;

bool solve(ll n = v1.size())
{
	if(n & 1)
	{
		if(v1[n / 2] != v2[n / 2]) return 0;
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	return v1 == v2;
}

multiset < pll > mt1, mt2;

bool solve1(ll n = v1.size())
{
	if(n & 1)
	{
		if(v1[n / 2] != v2[n / 2]) return 0;
	}

	mt1.clear();
	mt2.clear();

	for(ll i = n / 2 - 1, j = n / 2 + 1; i >= 0; i--, j++)
	{
		ll x = v1[i];
		ll y = v1[j];

		if(x > y) swap(x,y);

		mt1.insert({x,y});
	}

	for(ll i = n / 2 - 1, j = n / 2 + 1; i >= 0; i--, j++)
	{
		ll x = v2[i];
		ll y = v2[j];

		if(x > y) swap(x,y);

		mt2.insert({x,y});
	}

//	for(auto it: mt1) cout << it.first << " " << it.second << endl;
//	bug;
//	for(auto it: mt2) cout << it.first << " " << it.second << endl;


	return (mt1 == mt2);
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
		v1.clear();
		v2.clear();

		bool on = 0;

		slld(n);

		if(!(n & 1)) n++, on = 1;


		v1.resize(n);
		v2.resize(n);

		for(i = 0; i < n; i++)
		{
			if(i == (n / 2) && on) v1[i] = -1;
			else cin >> v1[i];
		}

		for(i = 0; i < n; i++)
		{
			if(i == (n / 2) && on) v2[i] = -1;
			else cin >> v2[i];
		}

		if(solve1()) printf("Yes\n");
		else printf("No\n");
    }


}



