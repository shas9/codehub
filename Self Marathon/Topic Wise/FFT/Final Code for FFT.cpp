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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll mod = 786433, root = 1000, pw = 262144, g = 10;

ll mul(ll a, ll b)
{
	return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b)
{
	return ((a % mod) + (b % mod)) % mod;
}

ll eval(vector < ll > &poly, ll x)
{
	ll ret = 0;
	ll now_x = 1;

	for(auto it: poly)
	{
		ret = add(ret,mul(it,now_x));
		now_x = mul(now_x,x);
	}

	return ret;
}

ll power(ll x, ll y, ll p = mod)
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

vector < ll > even(vector < ll > &a)
{
	vector < ll > ret;

	for(ll i = 0; i < a.size(); i += 2) ret.push_back(a[i]);

	return ret;
}

vector < ll > odd(vector < ll > &a)
{
	vector < ll > ret;

	for(ll i = 1; i < a.size(); i += 2) ret.push_back(a[i]);

	return ret;
}

vector < ll > ntt(vector < ll > a, vector < ll > b)
{
	vector < ll > ret;

	if(b.size() <= 2)
	{
		for(auto it: b)
		{
			ret.push_back(eval(a,it));
		}

		return ret;
	}

	ret.resize(b.size());

	vector < ll > halfb;

	for(ll i = 0; i < (b.size() / 2); i++)
	{
		halfb.push_back(mul(b[i],b[i]));
	}

	vector < ll > ev = ntt(even(a),halfb);
	vector < ll > od = ntt(odd(a), halfb);

	for(ll i = 0; i < b.size(); i++)
	{
		ll idx = i;

		if(i >= halfb.size()) idx = idx - halfb.size();

		ret[i] = add(ev[idx], mul(od[idx], b[i]));
	}

	return ret;

}


vector < ll > npoly;
vector < ll > poly;
vector < ll > proot;
vector < ll > ans;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input-1.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		poly.resize(n + 1);
		proot.resize(pw);
		ans.resize(mod);
		npoly.resize(n + 1);

		for(ll i = 0; i <= n; i++) cin >> poly[i];

		for(ll i = 0; i < pw; i++)
		{
			proot[i] = power(root,i);
		}

		for(ll i = 0; i < 3; i++)
		{
			for(ll j = 0; j <= n; j++) npoly[j] = mul(poly[j], power(g, i * j));

			vector < ll > c = ntt(npoly,proot);

			assert(c.size() == proot.size());

			for(ll j = 0; j < proot.size(); j++)
			{
				ans[mul(proot[j], power(g,i))] = c[j];
			}
		}

		ans[0] = poly[0];

//		for(ll i = 0; i < 1000; i++) cout << ans[i] << " ";
//		cout << endl;
		slld(m);

		for(ll i = 1; i <= m; i++)
		{
			slld(input);

			cout << ans[input] << '\n';
		}

    }


}


