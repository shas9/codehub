 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

ll dp[102][12][12];
ll dp2[32][12][12][50];
const ll mod = 1000000007;

ll solve(ll x, ll y, ll z)
{
	ll &ret = dp[x][y][z];

	if(ret != -1) return ret;

	if(x == 0 && y == 0 && z == 0) return ret = 1;

	ret = 0;

	if(x) ret += (solve(x - 1, y, z));
	if(x && y) ret += solve(x - 1, y - 1, z);
	if(x && y >= 2) ret += solve(x - 1, y - 2, z);
	if(x && z) ret += solve(x - 1, y, z - 1);
	if(x && z >= 2) ret += solve(x - 1, y, z - 2);

	return ret %= mod;
}


ll power(ll x, ll y, ll p)
{
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


ll nCr(ll n, ll k)
{
    if(k > n) assert(0);

    ll ret = 1;

    for(ll i = (n - k + 1); i <= n; i++) ret = (ret * i) % mod;

    for(ll i = 2; i <= k; i++) ret = (ret * power(i, mod - 2, mod)) % mod;

    return ret;
}


ll n;

ll solve1(ll x, ll y, ll z, ll t)
{
	ll &ret = dp2[x][y][z][t];

	if(ret != -1) return ret;

	if(y == 0 && z == 0)
	{
		if(x == 0) return ret = 1;

		return ret = nCr((n - 30 + x + t - 1), t - 1);
	}

	ret = 0;

	if(x && y) ret += solve1(x - 1, y - 1, z, t + 1);
	if(x && y >= 2) ret += solve1(x - 1, y - 2, z, t + 1);
	if(x && z) ret += solve1(x - 1, y, z - 1, t + 1);
	if(x && z >= 2) ret += solve1(x - 1, y, z - 2, t + 1);

	return ret %= mod;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n >> m >> k)
    {
		memset(dp,-1,sizeof dp);
		memset(dp2,-1,sizeof dp2);

//		ans = solve(min(100LL, n), m, k);
//
//		cout << ans << "\n";


		if(n <= 100) ans = solve(n,m,k);
		else ans = solve1(min(30LL, n), m, k, 1);

		cout << ans << "\n";
    }


}



