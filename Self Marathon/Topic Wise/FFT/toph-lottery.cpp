
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

/**
Iterative Implementation of Number Theoretic Transform
Complexity: O(N log N)
Slower than regular fft
Possible Optimizations:
1. Remove leading zeroes
2. Keep the mod const

Suggested mods (mod, root, inv, pw) :
7340033, 5, 4404020, 1<<20
13631489, 11799463,6244495, 1<<20
23068673, 177147,17187657, 1<<21
463470593, 428228038, 182429, 1<<21
415236097, 73362476, 247718523, 1<<22
918552577, 86995699, 324602258, 1<<22
998244353, 15311432, 469870224, 1<<23
167772161, 243, 114609789, 1<<25
469762049, 2187, 410692747, 1<<26
If required mod is not above, use nttdata function OFFLINE
**/

#include<bits/stdc++.h>
using namespace std;


namespace NTT {
    ll N;
    vector<ll> perm;
    vector<ll>wp[2][30];
    const ll mod = 786433, root = 1000, inv = 710149, pw = 262144;
    vector < ll > box[100005];


    ll power(ll a, ll p) {
        if (p==0)   return 1;
        ll ans = power(a, p/2);
        ans = (ans * 1LL * ans)%mod;
        if (p%2)    ans = (ans * 1LL * a)%mod;
        return ans;
    }

    void precalculate() {
        perm.resize(N);
        perm[0] = 0;

        for (ll k=1; k<N; k<<=1) {
            for (ll i=0; i<k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }

        for (ll b=0; b<2; b++) {
            for (ll idx = 0, len = 2; len <= N; idx++, len <<= 1) {
                ll factor = b ? inv : root;
                for (ll i = len; i < pw; i <<= 1)
                    factor = (factor*1LL*factor)%mod;

                wp[b][idx].resize(N);
                wp[b][idx][0] = 1;
                for (ll i = 1; i < len; i++) {
                    wp[b][idx][i] = (wp[b][idx][i-1]*1LL*factor)%mod;
                }
            }
        }
    }

    void fft(vector<ll> &v, bool invert = false) {
        if (v.size() != perm.size()) {
            N = v.size();
            assert(N && (N&(N-1)) == 0);
            precalculate();
        }

        for (ll i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);

        for (ll idx = 0, len = 2; len <= N; idx++, len <<= 1) {
            for (ll i=0; i<N; i+=len) {
                for (ll j=0; j<len/2; j++) {
                    ll x = v[i+j];
                    ll y = (wp[invert][idx][j]*1LL*v[i+j+len/2])%mod;
                    v[i+j] = (x+y>=mod ? x+y-mod : x+y);
                    v[i+j+len/2] = (x-y>=0 ? x-y : x-y+mod);
                }
            }
        }
        if (invert) {
            ll n1 = power(N, mod-2);
            for (ll &x : v) x = (x*1LL*n1)%mod;
        }
    }

    vector<ll> multiply(vector<ll> a, vector<ll> b) {
        ll n = 1;

        while(a.back() == 0 && !a.empty()) a.pop_back();
        while(b.back() == 0 && !b.empty()) b.pop_back();

        while (n < a.size()+ b.size())  n<<=1;
        a.resize(n);
        b.resize(n);

        fft(a);
        fft(b);
        for (ll i=0; i<n; i++) a[i] = (a[i] * 1LL * b[i])%mod;
        fft(a, true);
        return a;
    }

    vector < ll > solve(ll l, ll r)
    {
		if(l == r) return box[l];

		ll mid = (l + r) / 2;

		vector < ll > a = solve(l,mid);
		vector < ll > b = solve(mid + 1, r);

		return multiply(a,b);
    }
};

ll power(ll a, ll p, ll mod) {
    if (p==0)   return 1;
    ll ans = power(a, p/2, mod);
    ans = (ans * 1LL * ans)%mod;
    if (p%2)    ans = (ans * 1LL * a)%mod;
    return ans;
}


/** Find primitive root of p assuming p is prime.
if not, we must add calculation of phi(p)
Complexity : O(Ans * log (phi(n)) * log n + sqrt(p)) (if exists)
             O(p * log (phi(n)) * log n + sqrt(p))   (if does not exist)
Returns -1 if not found
*/

ll primitive_root(ll p) {
    if (p == 2) return 1;
    vector<ll> factor;
    ll phi = p-1,  n = phi;

    for (ll i=2; i*i<=n; ++i)
        if (n%i == 0) {
            factor.push_back (i);
            while (n%i==0)  n/=i;
        }

    if (n>1)  factor.push_back(n);

    for (ll res=2; res<=p; ++res) {
        bool ok = true;
        for (ll i=0; i<factor.size() && ok; ++i)
            ok &= power(res, phi/factor[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}


/**
  Generates necessary info for NTT (for offline usage :3)
  returns maximum k such that 2^k divides mod
  ntt can only be applied for arrays not larger than this size
  mod MUST BE PRIME!!!!!
  We use that fact that primes the form p=c*2^k+1,
  there always exist the 2^k-th root of unity.
  It can be shown that g^c is such a 2^k-th root
  of unity, where g is a primitive root of p.
*/


ll nttdata(ll mod, ll &root, ll &inv, ll &pw) {
    ll c = 0, n = mod-1;
    while (n%2 == 0) c++, n/=2;
    pw = (mod-1)/n;
    ll g = primitive_root(mod);
    root = power(g, n, mod);
    inv = power(root, mod-2, mod);
    return c;
}

vector < pll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);
//
//	int mod = 786433;
//	int a, b, c;
//
//	nttdata(mod,a,b,c);
//
//	cout << mod << ", " << a << ", " << b << ", " << c << ";";

    while(cin >> n)
    {
		for(i = 1; i <= n; i++)
		{
			vec.clear();
			ll degree = 0;

			slld(m);

			for(ll j = 0; j < m; j++)
			{
				ll x, y;

				slld(x);
				slld(y);

				vec.push_back({x,y});

				degree = max(degree,x);
			}

			NTT :: box[i].clear();
			NTT :: box[i].resize(degree + 1);

			for(auto it: vec)
			{
				NTT :: box[i][it.first] = it.second;
			}
		}

		vector < ll> ans = NTT :: solve(1,n);

		for(ll i = 0; i < ans.size(); i++)
		{
			if(ans[i]) cout << i << " " << ans[i] << '\n';
		}
    }

    return 0;


}


