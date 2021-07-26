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

vector < pll > v;

bool solve(ll a, ll b, ll n)
{
	for(auto &it: v)
	{
		ll hit = it.second / a;

		if(it.second % a == 0) hit--;

		b -= hit * it.first;
	}

	sort(v.begin(),v.end());

	for(auto it: v)
	{
		if(b <= 0) return 0;
		b -= it.first;
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
		cin >> n >> m >> k;

		v.resize(k);

		for(auto &it: v) cin >> it.first;
		for(auto &it: v) cin >> it.second;

		if(solve(n,m,k)) cout << "YES\n";
		else cout << "NO\n";
    }


}


