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

pll arr[100005];

vector < vector < ll > > vec;

ll bs(ll idx, ll k)
{
	ll lo = 0;
	ll hi = vec[idx].size() - 1;

	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(vec[idx][mid] <= k)
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret + 1;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		if(n == 0 && m == 0) exit(0);

		for(i = 1; i <= n; i++)
		{
			slld(arr[i].first);
			slld(arr[i].second);
		}

		vec.clear();

		vec.push_back({});

		for(i = 1; i <= n; i++)
		{
			vec.push_back({});

			for(j = 1; j <= n; j++)
			{
				ll dx = (arr[i].first - arr[j].first);
				ll dy = (arr[i].second - arr[j].second);

				ll dist = dx * dx + dy * dy;

				vec.back().push_back(dist);
			}

			sort(vec.back().begin(),vec.back().end());
		}

		for(i = 1; i <= m; i++)
		{
			slld(k);

			k = k * k;

			ans = 0;

			for(j = 1; j <= n; j++)
			{
				ans += bs(j,k);
			}

			double ret = (ans / (1.0 * n));

			printf("%.2f\n", ret);
		}

		printf("\n");
    }


}



