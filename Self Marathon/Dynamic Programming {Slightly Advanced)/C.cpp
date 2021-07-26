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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[101][101];
pll arr[101];
ll nxt[101];
ll n, m;

ll solve(ll pos, ll rem)
{
	if(rem == 0) return 0;
	if(pos > n) return 0;

	ll &ret = dp[pos][rem];

	if(ret != -1) return ret;

	ret = 0;

	ret = max(solve(pos + 1, rem), solve(pos + nxt[pos], rem - 1) + nxt[pos]);

	return ret;
}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		memset(dp,-1,sizeof dp);

		slld(n);
		slld(m);
		slld(k);

		for(i = 1; i <= n; i++) slld(arr[i].second), slld(arr[i].first);

		sort(arr + 1, arr + 1 + n);

		for(i = 1; i <= n; i++)
		{
			ll cnt = 0;

			for(j = i; j <= n; j++)
			{
				if(arr[i].first + m >= arr[j].first) cnt++;
				else break;
			}

//			cout << i << " " << cnt << endl;
			nxt[i] = cnt;
		}

		ans = solve(1,k);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



