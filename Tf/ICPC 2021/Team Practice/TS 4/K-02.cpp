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

map < ll, ll > mp;
ll dp[20][20][20];
ll m;

ll solve(ll pos, ll nz, ll z)
{
	ll &ret = dp[pos][nz][z];

	if(ret != -1) return ret;

	if(pos == m)
	{
		assert(nz + z == 1);
		return ret = nz;
	}

	ret = 0;

	if(nz) ret += nz * solve(pos + 1, nz - 1 + mp[pos + 1], z);
	if(z) ret += z * solve(pos + 1, nz + mp[pos + 1], z - 1);

	return ret;
}

map < ll, ll > fact;

int main()
{
    ll i, j, k, l, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fact[0] = 1;

	for(ll i = 1; i <= 20; i++) fact[i] = fact[i - 1] * i;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;
		mp.clear();
		m = 1;
		memset(dp,-1,sizeof dp);

		while(n)
		{
			m++;
			mp[n % m]++;
			n /= m;
		}

		m--;

		ans = solve(1,mp[1],mp[0]);

		for(ll i = 0; i <= m; i++) ans /= fact[mp[i]];

		cout << ans - 1 << "\n";
    }


}

