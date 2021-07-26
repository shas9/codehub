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

//#define mod 958585860497

//#define base 2001487

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
    int N;
    vector<int> perm;
    vector<int>wp[2][30];
    const int mod = 998244353, root = 15311432, inv = 469870224, pw = 1<<23;

    int power(int a, int p) {
        if (p==0)   return 1;
        int ans = power(a, p/2);
        ans = (ans * 1LL * ans)%mod;
        if (p%2)    ans = (ans * 1LL * a)%mod;
        return ans;
    }

    void precalculate() {
        perm.resize(N);
        perm[0] = 0;

        for (int k=1; k<N; k<<=1) {
            for (int i=0; i<k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }

        for (int b=0; b<2; b++) {
            for (int idx = 0, len = 2; len <= N; idx++, len <<= 1) {
                int factor = b ? inv : root;
                for (int i = len; i < pw; i <<= 1)
                    factor = (factor*1LL*factor)%mod;

                wp[b][idx].resize(N);
                wp[b][idx][0] = 1;
                for (int i = 1; i < len; i++) {
                    wp[b][idx][i] = (wp[b][idx][i-1]*1LL*factor)%mod;
                }
            }
        }
    }

    void fft(vector<int> &v, bool invert = false) {
        if (v.size() != perm.size()) {
            N = v.size();
            assert(N && (N&(N-1)) == 0);
            precalculate();
        }

        for (int i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);

        for (int idx = 0, len = 2; len <= N; idx++, len <<= 1) {
            for (int i=0; i<N; i+=len) {
                for (int j=0; j<len/2; j++) {
                    int x = v[i+j];
                    int y = (wp[invert][idx][j]*1LL*v[i+j+len/2])%mod;
                    v[i+j] = (x+y>=mod ? x+y-mod : x+y);
                    v[i+j+len/2] = (x-y>=0 ? x-y : x-y+mod);
                }
            }
        }
        if (invert) {
            int n1 = power(N, mod-2);
            for (int &x : v) x = (x*1LL*n1)%mod;
        }
    }

    vector<int> multiply(vector<int> a, vector<int> b) {
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;
        a.resize(n);
        b.resize(n);

        fft(a);
        fft(b);
        for (int i=0; i<n; i++) a[i] = (a[i] * 1LL * b[i])%mod;
        fft(a, true);
        return a;
    }
};

void test()
{
	ll now = 2000;
	ll log = 0;
	ll dd = 1;

	ll comp = 0;

	for(ll i = 1; i <= 1000; i++)
	{
		while(dd < now) dd += dd, log++;

		comp += (now * log);

		now += 1000;
	}

	cout << comp << endl;
}

void check()
{
	ll n = 1;
	ll lg = 0;

	while(n < 998244353) n += n, lg++;

	cout << n << " " << lg << endl;
}
vector < ll > a;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	check();

    while(cin >> n >> k)
    {
		a.clear();
		a.resize(1000 * k);

		for(ll i = 1; i <= n; i++)
		{
			slld(input);

			a[input] = 1;
		}

		NTT fft(998244353, 15311432, 469870224, 1<<23);

		a = fft.multiply(a,k);

//		for(ll i = 0; i < 1000; i++)
//		{
//			cout << i << ": " << a[i] << endl;
//		}

		cout << '\n';


    }

}



