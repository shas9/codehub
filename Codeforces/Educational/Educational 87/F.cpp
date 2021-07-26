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

struct id
{
	ll i, a, b;
} arr[100];

bool comp(id a, id b)
{
	if(a.b == b.b) return a.a < b.a;
	return a.b < b.b;
}

ll dp[100][100];
ll pp[100][100];

vector < ll > aa, bb;

ll n, k;

void solve()
{
	dp[0][0] = 0;

	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < n; j++)
		{
			if(dp[i][j] < 0) continue;

			if(dp[i + 1][j] < dp[i][j] + (arr[i].b * (k - 1)))
			{
				dp[i + 1][j] = dp[i][j] + (arr[i].b * (k - 1));
				pp[i + 1][j] = j;
 			}

 			if(dp[i + 1][j + 1] < dp[i][j] + (arr[i].b * j) + arr[i].a)
			{
				dp[i + 1][j + 1] = dp[i][j] + (arr[i].b * j) + arr[i].a;
				pp[i + 1][j + 1] = j;
			}

		}
	}

//	for(ll i = 1; i <= n; i++)
//	{
//		for(ll j = 1; j <= n; j++)
//		{
//			cout << i << " " << j << ": " <<  dp[i][j] << " " << pp[i][j] << endl;
//		}
//	}

	ll now = k;

	for(ll i = n; i >= 1; i--)
	{
		if(pp[i][now] == now)
		{
			bb.push_back(arr[i - 1].i + 1);
		}
		else
		{
			aa.push_back(arr[i - 1].i + 1);
		}

//		cout << now << endl;
		now = pp[i][now];
	}

	reverse(aa.begin(),aa.end());
	reverse(bb.begin(),bb.end());
}
int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(k);

		for(i = 0; i < n; i++)
		{
			slld(arr[i].a);
			slld(arr[i].b);
			arr[i].i = i;
		}

		sort(arr, arr + n, comp);

//		for(i = 0; i < n; i++) cout << arr[i].i << " " << arr[i].a << " " << arr[i].b << endl;

		for(i = 0; i <= n + 10; i++) for(j = 0; j <= n + 10; j++) dp[i][j] = -1, pp[i][j] = 0;

		aa.clear();
		bb.clear();

//		cout << aa.size() << endl;
		solve();

//		cout << aa.size() << endl;
		cout << aa.size() + (bb.size() * 2) << "\n";

		for(i = 0; i + 1 < aa.size(); i++) cout << aa[i] << " ";
		for(auto it: bb) cout << it << " " << -it << " ";
		cout << aa.back() << "\n";
    }


}



