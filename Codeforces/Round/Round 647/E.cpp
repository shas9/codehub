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

vector < ll > vec;
map < ll, ll > mp;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
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
		slld(m);

		mp.clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);
			mp[input]++;
		}

		if(m == 1)
		{
			if(n & 1) cout << 1 << '\n';
			else cout << 0 << '\n';

			continue;
		}


		for(auto &it: mp)
		{
			if(it.first <= 1) continue;

			ll x = (it.second / it.first);

			it.second -= (x * it.first);

			if(x) mp[it.first + 1] += x;
		}

		vec.clear();

		for(auto it: mp) vec.push_back(it.first);

		ll sum1 = 0, sum2 = 0;

		for(ll i = 0; i + 1 < vec.size(); i++)
		{
			sum1 = (sum1 + power(m,vec[i],mod)) % mod;
		}
		sum2 = power(m,vec.back(),mod) % mod;

		ans = (sum2 - sum1 + mod) % mod;

		cout << ans << '\n';
    }


}


