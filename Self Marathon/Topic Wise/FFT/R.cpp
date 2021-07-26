// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug prllf("BUG\n")

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

namespace ntt {
    ll N;
    vector<ll> perm;
    vector<ll>wp[2][30];
    const ll mod = 998244353, root = 15311432, inv = 469870224, pw = 1<<23;

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

    vector < ll > solve(vector < ll > vec, ll p)
    {
		ll sz = vec.size() * p;

		ll n = 1;

		while(n < sz) n += n;

		vec.resize(n);

		fft(vec);

		for(auto &it: vec)
		{
			it = power(it,p);
		}

		fft(vec,1);

		return vec;
    }
};

using namespace ntt;

vector < ll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		vec.resize(n);

		for(ll i = 0; i < n; i++) slld(vec[i]);

		ll cnt = 0;
		ans = 1;

		for(ll i = 0; i < n; i++)
		{
			if(vec[i] == vec[(i + 1) % n]) ans = (ans * 1LL * k) % mod;
			else cnt++;
		}

		ll tmp = 0;

		if(cnt)
		{
			vector < ll > p = {1,k - 2, 1};

			p = ntt :: solve(p,cnt);

			for(ll i = cnt + 1; i < p.size(); i++) tmp = (tmp + p[i]) % mod;
		}

		ans = (ans * 1LL * tmp ) % mod;

		printf("%lld\n", ans);

    }


}


