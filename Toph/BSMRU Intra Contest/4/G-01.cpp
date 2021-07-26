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

ll aa[100005];
ll mp[100];
vector < pll > v1, v2;

ll lcm(ll x, ll y)
{
	return (x * y) / __gcd(x,y);
}

ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}


ll findMinX(vector < pll > num, ll k, ll modulo)
{
    // Compute product of all numbers
    ll prod = 1;
    for (ll i = 0; i < k; i++)
        prod *= num[i].first;

    // Initialize result
    ll result = 0;

    // Apply above formula
    for (ll i = 0; i < k; i++)
    {
        ll pp = prod / num[i].first;
        result += num[i].second * inv(pp, num[i].first) * pp;
    }

    return result % modulo;
}

ll solve()
{
	ll modulo = v1.front().first;

	for(auto it: v1) modulo = lcm(modulo,it.first);

	ll ret = findMinX(v2,v2.size(),modulo);

	return ret %= modulo;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
		slld(aa[i]);
    }

    memset(mp,-1,sizeof mp);

	bool no = 0;

    for(i = 1; i <= n; i++)
    {
		slld(input);

		if(mp[input] != -1)
		{
			if(mp[input] != aa[i]) no = 1;
		}
		else
		{
			mp[input] = aa[i];

			v1.push_back({input,aa[i]});
 		}

 		if(input <= mp[input]) no = 1;
    }

    if(no) printf("Infinity Stones are just a myth\n");
    else
    {
		for(auto it: v1)
		{
			bool g = 1;

			for(auto jt: v2) if(__gcd(jt.first,it.first) != 1) g = 0;

			if(g) v2.push_back(it);
		}

		ans = solve();

		printf("%lld\n", ans);
    }


}



