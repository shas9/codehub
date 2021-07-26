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

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll ww[25][25];
ll vis[25];

bool solve(ll n, ll k)
{
	queue < ll > qq;

	memset(vis,0,sizeof vis);

	for(ll i = 1; i <= k; i++)
	{
		qq.push(i);

		vis[i] = i;
	}

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		for(ll i = 1; i <= n; i++)
		{
			if(ww[top][i] == 0) continue;

			if(vis[i] != 0)
			{
				if(vis[i] != vis[top]) return 1;
			}
			else
			{
				vis[i] = vis[top];
				qq.push(i);
			}
		}
	}

	return 0;


}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(k);

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				slld(ww[i][j]);

				if(i <= k && j <= k)
				{
					ans += ww[i][j];
					ww[i][j] = 0;
				}
			}
		}

		ans /= 2;

//		cout << ans << endl;
		while(solve(n,k))
		{
			ll mn = mxlld;
			ll pi, pj;

			for(i = k + 1; i <= n; i++)
			{
				for(j = 1; j <= k; j++)
				{
					if(ww[i][j]==0) continue;

					mn = min(mn,ww[i][j]);

					if(mn == ww[i][j])
					{
						pi = i;
						pj = j;
					}
				}
			}

			for(i = 1; i <= k; i++)
			{
				for(j = k + 1; j <= n; j++)
				{
					if(ww[i][j]==0) continue;

					mn = min(mn,ww[i][j]);

					if(mn == ww[i][j])
					{
						pi = i;
						pj = j;
					}
				}
			}

			ans += mn;

			ww[pi][pj] = 0;
			ww[pj][pi] = 0;
		}

		printf("%lld\n", ans);
    }


}



