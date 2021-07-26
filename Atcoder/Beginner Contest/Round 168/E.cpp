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

#define mod 1000000007

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

map < pll, pll > vec;
ll p2[200005];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	p2[0] = 1;

	for(i = 1; i <= 200000; i++) p2[i] = (2 * p2[i - 1]) % mod;

    while(cin >> n)
    {
		vec.clear();

		for(i = 1; i <= n; i++)
		{
			ll a, b;
			slld(a);
			slld(b);

			if(a == 0 && b == 0) vec[{0,0}].first++;
			else if(a == 0) vec[{0,1}].first++;
			else if(b == 0) vec[{0,1}].second++;
			else
			{
				ll g = __gcd(a,b);

				a /= g;
				b /= g;

				if(a * b > 0) vec[{abs(a),abs(b)}].first++;
				else vec[{abs(b),abs(a)}].second++;
			}
		}

		ans = 1;

		for(auto p: vec)
		{
			if(p.first.first == 0 && p.first.second == 0) continue;

			ans = (ans * (p2[p.second.first] + p2[p.second.second] - 1)) % mod;
		}

		ans = (ans + vec[{0,0}].first - 1 + mod) % mod;

		printf("%lld\n", ans);
    }


}



