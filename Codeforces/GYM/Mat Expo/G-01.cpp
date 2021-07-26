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


#define REP(i,n) for(int i = 0; i < (n); i++)

const ll s = 15;
const ll mod = 1000000007;

struct Matrix {
	vector<vector<int>> a = vector<vector<int>>(s, vector<int>(s));
	Matrix operator *(const Matrix& other) {
		Matrix product;
		REP(i,s)REP(j,s)REP(k,s) {
			product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long k) {
	Matrix product;
	REP(i,s) product.a[i][i] = 1;
	while(k > 0) {
		if(k % 2) {
			product = product * a;
		}
		a = a * a;
		k /= 2;
	}
	return product;
}

/*

ndp[1] = dp[2] // na1 = a2;
ndp[2] = dp[3] // na2 = a3;
ndp[n - 1] = c[n - 1] * dp[0] + c[n - 2] * dp[1];

for(i = 1; i <= n; i++)
{
	ndp[i]
}

ndp[n - 1] = ( .... ) + p * np[n] + q * np[n + 1] + r * np[n + 2];

np[n] = dp[n];
np[n + 1] = dp[n + 1] + dp[n];
np[n + 2] = dp[n + 2] + 2 * dp[n + 1] + dp[n];
*/

ll arr[100];
ll crr[100];
ll dp[100];
ll mat[100][100];
int main()
{
    ll i, j, k, l, m, n, o, r, q, p;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n >> k)
    {
		for(ll i = 0; i < n; i++) cin >> arr[i];
		for(ll i = 0; i < n; i++) cin >> crr[i];
		cin >> p >> q >> r;

		memset(dp,0,sizeof dp);

		if(k < n)
		{
			cout << arr[k] << endl;
			continue;
		}

		for(ll i = 0; i < n - 1; i++) mat[i][i + 1] = 1;

		for(ll i = 0; i < n - 1; i++) mat[n - 1][i] = crr[n - i - 1];

		mat[n][n] = 1;

		mat[n + 1][n] = 1;
		mat[n + 1][n + 1] = 1;

		mat[n + 2][n + 2] = 1;
		mat[n + 2][n + 1] = 2;
		mat[n + 2][n] = 1;

		mat[n - 1][n] = p;
		mat[n - 1][n + 1] = q;
		mat[n - 1][n + 2] = r;

		Matrix single;

		for(ll i = 0; i < n + 3; i++)
		{
			for(ll j = 0; j < n + 3; j++)
			{
				single.a[i][j] = mat[i][j];
			}
		}

		Matrix res = expo_power(single,k);


		for(ll i = 0; cout << endl && i < n + 3; i++)
			for(ll j = 0; j < n + 3 && cout << " "; j++) cout << res.a[i][j];

		arr[n] = 1;
		arr[n + 1] = n;
		arr[n + 2] = n * n;

		for(ll i = 0; i < n + 3; i++)
			for(ll j = 0; j < n + 3; j++)
				dp[i] = (dp[i] + arr[j] * res.a[i][j]) % mod;

		cout << dp[n - 1] << endl;
    }


}



