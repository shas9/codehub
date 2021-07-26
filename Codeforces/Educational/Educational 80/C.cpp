#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll ncr[2000][2000];

ll nCr(ll n, ll r)
{
    if(r > n) return 0;

    ll &ret = ncr[n][r];

    if(ret != -1) return ret;

    if(r > n) ret =0;
    else if(r == n) ret = 1;
    else if(r == 1) ret = n;
    else ret = (nCr(n-1,r) + nCr(n-1,r-1)) % mod;

//    cout << n << " " << r << " " << ret << endl;

    return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(ncr,-1,sizeof ncr);
    while(cin >> n >> m)
    {

        cout << nCr(n + (2*m) - 1, 2*m) << endl;
    }


}



