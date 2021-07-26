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

bool solve(ll n)
{
	ll odd = 0;
	ll even = 0;

	for(auto it: vec)
	{
		if(it & 1) odd++;
		else even++;
	}

	if(!(odd & 1)) return 1;

	sort(vec.begin(),vec.end());

	for(int i = 1; i < vec.size(); i++)
	{
		if(abs(vec[i] - vec[i - 1]) == 1) return 1;
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
		slld(n);

		vec.clear();

		vec.resize(n);

		for(i = 0; i < n; i++) cin >> vec[i];

		if(solve(n)) printf("YES\n");
		else printf("NO\n");
    }


}



