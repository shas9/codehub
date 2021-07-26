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

vector < ll > g[25];
ll arr[200005];

bool vis[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 0; i <= 23; i++) g[i].clear();

		ans = 0;

		for(i = 1; i <= n; i++) slld(arr[i]);

		sort(arr + 1, arr + 1 + n);
		reverse(arr + 1, arr + 1 + n);

		for(i = 1; i <= n; i++)
		{
			for(j = 0; j <= 22; j++)
			{
				if(check(arr[i],j)) g[j].push_back(i);
			}
		}

		memset(vis,0,sizeof vis);

		for(i = 22; i >= 0; i--)
		{
			for(auto it: g[i])
			{
				if(vis[it]) continue;
				vis[it] = 1;

				for(j = 0; j < i; j++)
				{
					if(check(arr[it],j) == 0)
					{
						while(!g[j].empty())
						{
							ll idx = g[j].back();

							g[j].pop_back();

							if(vis[idx]) continue;

							arr[idx] -= (1 << j);
							arr[it] += (1 << j);

							break;
						}
					}
				}
			}
		}

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			ans += arr[i] * arr[i];
		}

		printf("%lld\n", ans);
    }


}



