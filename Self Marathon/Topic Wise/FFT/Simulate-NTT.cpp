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
    int N;
    vector<int> perm;
    vector<int>wp[2][30];
    const int mod = 786433, root = 1000, inv = 710149, pw = 262144;



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
            for (int idx = 0, len = 2; len <= N; idx++, len <<= 1, printf("\n")) {
                int factor = b ? inv : root;
                for (int i = len; i < pw; i <<= 1)
                {
                    factor = (factor*1LL*factor)%mod;
                    cout << factor << ' ';
                }

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

    vector<int> multiply(vector<int> a) {
        int n = 1;
        while (n < a.size())  n<<=1;
        a.resize(n);

        fft(a);

        for (int i=0; i<n; i++)
        {
			cout << i << " & " << a[i] << endl;
        }

        fft(a, true);

        cout << endl << endl;
        for (int i=0; i<n; i++)
        {
			cout << i << " | " << a[i] << endl;
        }
        return a;
    }
};

vector < int > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	set < ll > st;

	for(ll i = 0; i <= 100; i++)
	{
		cout << NTT :: power(10, i) << ' ' << NTT :: power(NTT:: root, i) << endl;

		st.insert(NTT :: power(10, i));
	}

	cout <<endl << st.size() << " " << (1 << 18) << endl;

    while(cin >> n)
    {
		vec.clear();

		vec.resize(n + 1);

		for(ll i = 0; i <= n; i++) cin >> vec[i];

		NTT :: multiply(vec);
    }


}


