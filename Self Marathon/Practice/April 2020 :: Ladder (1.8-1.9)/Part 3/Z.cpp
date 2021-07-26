// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

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

int dp[5003][5003];
int n;
int arr[5003];

int solve(int pos, int brushed)
{
//	cout << pos << " " << brushed << endl;
	if(pos > n) return 0;

	if(brushed == n) return 0;

	brushed = min(arr[pos],brushed);

	int &ret = dp[pos][brushed];

	if(ret != -1) return ret;

	ret = 0;

	if(arr[pos] == brushed) return ret = solve(pos + 1, brushed);

	return ret = min(solve(pos + 1, brushed) + 1, solve(pos,brushed + 1) + 1);
}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
//		bug;
		for(i = 1; i <= n; i++) cin >> arr[i];

//		bug;
		memset(dp,-1,sizeof dp);

//		bug;
		int ans = solve(1,0);
//		bug;
		printf("%d\n", ans);

//		for(i = 1; i <= n; i++)
//		{
//			for(j = 1; j <= n; j++) cout << dp[i][j] << " ";
//			cout << endl;
//		}
    }


}


