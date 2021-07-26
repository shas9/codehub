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

namespace NTT {
    ll N;
    vector<ll> perm;
    vector<ll>wp[2][30];
    const ll mod = 786433, root = 1000, inv = 710149, pw = 262144;

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
};

vector < ll > poly;
vector < ll > p_root;
ll ans[1000000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		poly.resize(n + 1);

		for(ll i = 0; i <= n; i++) cin >> poly[i];

		p_root.resize(NTT :: pw);

		for(ll i = 0; i < NTT :: pw; i++)
		{
			p_root[i] = NTT :: power(NTT :: root, i);

//			cout << p_root[i] << " ";
		}

		ll g = 1;

		for(ll i = 0; i < 3; i++) // dividing polynomial llo three parts
		{
			vector < ll > npol(n + 1);

			for(ll j = 0; j <= n; j++) npol[i] = (poly[i] * NTT :: power(g,j)) % NTT :: mod;

			vector < ll > tans = NTT :: multiply(npol, p_root);


			for(ll j = 0; j < p_root.size(); j++)
			{
				ll idx = (p_root[j] * g) % NTT :: mod;

//				cout << p_root[j] << " " << g  << " " << idx << endl;

				ans[idx] = tans[j];
			}


			g *= 10;
		}

		ans[0] = poly[0];

		slld(m);

		for(ll i = 1; i <= m; i++)
		{
			slld(input);

			printf("%lld\n", ans[input]);
		}
    }


}


