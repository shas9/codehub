 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll mod = 998244353;

ll ncr[1001][1001];

ll nCr(ll n, ll r)
{
	if(r == 0) return 1;
	if(r == 1) return n;
	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}

ll power(ll x, ll y)
{
    p = mod;
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

const ll mns = 1e10;


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        string s;

        vector < ll > v(n);

        ll mnsrgt = 0;

        for(ll i = 1; i <= n; i++)
        {
            cin >> s;

            if(s == "-") v.push_back(mns), mnsrgt++;
            else
            {
                cin >> in;
                v.push_back(n);
            }
        }

        ans = 0;

        memset(ncr,-1,sizeof ncr);

        for(ll i = 0; i < n; i++)
        {
            if(v[i] == mns)
            {
                mnsrgt--;
                continue;
            }

            ll lesseq = 0;

            ans += v[i] * pow(2,i);

            for(ll j = 0; j < i; j++) if(v[j] <= v[i]) lesseq++;


        }
    }


}

