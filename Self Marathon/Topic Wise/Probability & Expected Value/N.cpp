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

long double dp[101][101][101];
bool vis[101][101][101];
long double arr[101];
ll n;


long double solve()
{
	long double ret = arr[0];

	sort(arr, arr + n);

    for(ll i = 0; i < n; i++)
    {
		long double cnt = 0;
		long double carry = 1;

        for(ll j = i; j < n; j++)
        {
			cnt *= (1 - arr[j]);

			cnt += (arr[j] * carry);

			carry *= (1 - arr[j]);

//			cout << i << " " << ret << " " << cnt << endl;

			if(ret <= cnt) ret = cnt;
        }
    }

//    cout << ret << endl;

    return ret;
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
        memset(vis,0,sizeof vis);
        memset(dp,0,sizeof dp);

        for(i = 0; i < n; i++) cin >> arr[i];

        long double ans = solve();

        printf("%.10f\n", (double)ans);

    }


}


