// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

//#define bug prllf("BUG\n")

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


namespace ntt {
    ll N;
    vector<ll> perm;
    vector<ll>wp[2][30];
    const ll mod = 998244353, root = 15311432, inv = 469870224, pw = 1<<23;

    vector < ll > res[5][5];
    vector < ll > vec;

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
        while (n < a.size()+ b.size())  n<<=1;
        a.resize(n);
        b.resize(n);

        fft(a);
        fft(b);
        for (ll i=0; i<n; i++) a[i] = (a[i] * 1LL * b[i])%mod;
        fft(a, true);
        return a;
    }


    ll solve(string &s, string &t)
    {
		ll sz = s.size() + t.size();
		ll n = 1;

		while(n < sz) n += n;

		vec.resize(n);

		for(ll i = 0; i < 5; i++)
		{
			for(ll j = 0; j < s.size(); j++)
			{
				if(s[j] == (i + 'A')) vec[j] = 1;
				else vec[j] = 0;
			}

			for(ll j = s.size(); j < n; j++)
			{
				vec[j] = 0;
			}

			fft(vec);

			for(ll j = 0; j < 5; j++)
			{
				res[i][j] = vec;
			}
		}

		reverse(t.begin(),t.end());

		for(ll i = 0; i < 5; i++)
		{
			for(ll j = 0; j < t.size(); j++)
			{
				if(t[j] == (i + 'a')) vec[j] = 1;
				else vec[j] = 0;
			}

			for(ll j = t.size(); j < n; j++)
			{
				vec[j] = 0;
			}

			fft(vec);

			for(ll j = 0; j < 5; j++)
			{
				assert(res[j][i].size() == n);
				for(ll k = 0; k < n; k++)
				{
					res[j][i][k] = (res[j][i][k] * 1LL * vec[k]) % mod;
				}

				fft(res[j][i],1);
			}
		}

		ll ans = 0;

		vector < ll > perp;

		perp.resize(5);
		iota(perp.begin(),perp.end(),0);

		while(next_permutation(perp.begin(),perp.end()))
		{
			for(ll j = t.size(); j < n; j++)
			{
				ll tmp = 0;

				for(ll i = 0; i < 5; i++)
				{
					tmp = ((tmp * 1LL)+ res[i][perp[i]][j]) % mod;
				}

				ans = max(ans,tmp);
			}
		}

//		cout << ans << " " << abs(mod - ans) <<  endl;

		return t.size() - ans;
    }
};

using namespace ntt;

string s, t;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> s >> t)
    {
		s += s;

		ans = ntt :: solve(s,t);

		cout << ans << '\n';
    }

    return 0;

}


