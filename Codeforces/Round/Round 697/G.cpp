 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

vector < ll > dv[200005];
ll arr[200005];
vector < ll > dvv[200005];

void calc()
{
//	ll ret = 0;
	for(ll i = 1; i <= 200000; i++)
	{
		for(ll j = 1; j * j <= i; j++)
		{
			if(i % j == 0)
			{
				dvv[i].push_back(j);

				if(i / j != j)
				{
					dvv[i].push_back(i / j);
				}
			}
		}

//		ret = max(ret, (int)dvv[i].size());

	}
}

ll dp[200005];
ll dvp[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	calc();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		for(ll i = 1; i <= 200000; i++) dv[i].clear(), dp[i] = 1, dvp[i] = 0;

		cin >> n;

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		sort(arr + 1, arr + 1 + n);

		ll cnt = 0;

		for(ll i = 1; i <= n; i++)
		{
			for(auto it: dvv[arr[i]])
			{
				dp[i] = max(dvp[it] + 1, dp[i]);
			}

			dvp[arr[i]] = max(dvp[arr[i]], dp[i]);
		}

		ans = 1;

		for(ll i = 1; i <= n; i++)
		{
			ans = max(ans, dp[i]);
		}

		cout << n - ans << "\n";
    }


}


