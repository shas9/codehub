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

ll arr[100005];

bool brute(ll n)
{
	set < ll > st;

	ll idx = 0;
	for(ll i = 0; i <= 10 * n; i++)
	{
		idx++;

		if(idx == n) idx -= n;

		ll dest = i + arr[idx];

		if(st.find(dest) != st.end()) return 0;

		st.insert(dest);
	}

	return 1;
}

bool solve(ll n)
{
	map < ll, bool > mp;

	for(ll i = 0; i < n; i++)
	{
		ll x = (i + (arr[i] % n) + n) % n;

		if(mp.find(x) != mp.end()) return 0;

		mp[x] = 1;
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//		freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 0; i < n; i++) slld(arr[i]);

//		if(brute(n)) printf("YES\n");
//		else printf("NO\n");

		if(solve(n)) printf("YES\n");
		else printf("NO\n");

    }


}


