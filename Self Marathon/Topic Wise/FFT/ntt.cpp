struct NTT
{
    int N;
    vector<int> perm;

    int mod, root, inv, pw;

    NTT(int mod, int root, int inv, int pw) :
        mod(mod), root(root), inv(inv), pw(pw) {}

    ll power(ll a, ll p)
    {
        if (p==0)   return 1;
        ll ans = power(a, p/2, mod);
        ans = (ans * ans)%mod;
        if (p%2)    ans = (ans * a)%mod;
        return ans;
    }

    void precalculate()
    {
        perm.resize(N);
        perm[0] = 0;

        for (int k=1; k<N; k<<=1)
        {
            for (int i=0; i<k; i++)
            {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }
    }

    void fft(vector<ll> &v, bool invert = false)
    {
        if (v.size() != perm.size())
        {
            N = v.size();
            assert(N && (N&(N-1)) == 0);
            precalculate();
        }

        for (int i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);

        for (int len = 2; len <= N; len <<= 1)
        {
            ll factor = invert ? inv : root;
            for (int i = len; i < pw; i <<= 1)
                factor = (factor * factor) % mod;

            for (int i=0; i<N; i+=len)
            {
                ll w = 1;
                for (int j=0; j<len/2; j++)
                {
                    ll x = v[i+j], y = (w * v[i+j+len/2])%mod;
                    v[i+j] = (x+y)%mod;
                    v[i+j+len/2] = (x-y+mod)%mod;
                    w = (w * factor)%mod;
                }
            }
        }
        if (invert)
        {
            ll n1 = power(N, mod-2, mod);
            for (ll &x : v) x=(x*n1)%mod;
        }
    }

    vector<ll> multiply(vector<ll> a, vector<ll> b)
    {
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;
        a.resize(n);
        b.resize(n);

        fft(a);
        fft(b);
        for (int i=0; i<n; i++) a[i] = (a[i] * b[i])%mod;
        fft(a, true);
        return a;
    }
};
