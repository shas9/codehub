// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

typedef complex<double> CD;
const double PI = acos(-1);

struct FFT
{
    int N;
    vector<int> perm;

    void precalculate() {
        perm.resize(N);
        perm[0] = 0;

        for (int k=1; k<N; k<<=1) {
            for (int i=0; i<k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }
    }

    void fft(vector<CD> &v, bool invert = false) {
        if (v.size() != perm.size()) {
            N = v.size();
            assert(N && (N&(N-1)) == 0);
            precalculate();
        }

        for (int i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);

        for (int len = 2; len <= N; len <<= 1) {
            double angle = 2 * PI / len;
            if (invert) angle = -angle;
            CD factor = polar(1.0, angle);

            for (int i=0; i<N; i+=len) {
                CD w(1);
                for (int j=0; j<len/2; j++) {
                    CD x = v[i+j], y = w * v[i+j+len/2];
                    v[i+j] = x+y;
                    v[i+j+len/2] = x-y;
                    w *= factor;
                }
            }
        }
        if (invert)
            for (CD &x : v) x/=N;
    }

    vector<ll> multiply(vector<ll> a, vector<ll> b) {
        vector<CD> fa(a.begin(), a.end()), fb(b.begin(), b.end());

        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;
        fa.resize(n);
        fb.resize(n);

        fft(fa);
        fft(fb);
        for (int i=0; i<n; i++) fa[i] *= fb[i];
        fft(fa, true);

        vector<ll> ans(n);
        for (int i=0; i<n; i++)
            ans[i] = round(fa[i].real());
        return ans;
    }
};

vector < ll > v1, v2, v3;
string s;
bool on[1123456];

vector < ll > dv[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	for(ll i = 1; i <= 500000; i++)
	{
		for(ll j = i; j <= 500000; j += i)
		{
			dv[j].push_back(i);
		}
	}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> s;

		for(ll i = 0; i <= n; i++) on[i] = 1;

		v1.resize(n);
		v2.resize(n);

		fill(v1.begin(),v1.end(),0);
		fill(v2.begin(),v2.end(),0);

		for(ll i = 0; i < n; i++)
		{
			if(s[i] == 'V') v1[i] = 1;
			else if(s[i] == 'K') v2[n - i - 1] = 1;
		}

		FFT fft;

//		for(auto it: v1) cout << it << " ";
//		cout << endl;
//
//		for(auto it: v2) cout << it << " ";
//		cout << endl;

		v3 = fft.multiply(v1,v2);

//		cout << v3.size() << endl;

		for(ll i = 1; i <= n; i++)
		{
			if(v3[i + n - 1])
			{
//				cout << i << " ++ " << i + n - 1 << " " << v3[i + n - 1] << endl;
				on[i] = 0;
			}
		}

		fill(v1.begin(),v1.end(),0);
		fill(v2.begin(),v2.end(),0);

		for(ll i = 0; i < n; i++)
		{
			if(s[i] == 'K') v1[i] = 1;
			else if(s[i] == 'V') v2[n - i - 1] = 1;
		}


		v3 = fft.multiply(v1,v2);

		for(ll i = 1; i <= n; i++)
		{
			if(v3[i + n - 1])
			{
//				cout << i << " -- " << i + n - 1 << " " << v3[i + n - 1] << endl;
 				on[i] = 0;
			}
		}

		ll cnt = 0;

		for(ll i = 1; i <= n; i++)
		{
			if(on[i] == false)
			{
				for(auto it: dv[i]) on[it] = false;
			}
		}

		for(ll i = 1; i <= n; i++) cnt += on[i];

		cout << cnt << '\n';

		for(ll i = 1; i <= n; i++)
		{
			if(on[i]) printf("%d ", i);
		}

		printf("\n");
    }


}


