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

ll ag[200005];
struct node{
	ll d, l, r;
} arr[200005];

bool comp(node a, node b)
{
	if(a.l == b.l) return a.r < b.r;

	return a.l < b.l;
}

bool comp1(ll a, ll b)
{
	return a > b;
}

ll n, m, k, t;

bool solve(ll pos)
{
	ll mxag = ag[pos];

	ll cost = 0;

	ll mxr = 0;

	for(ll i = 1; i <= k; i++)
	{
		if(arr[i].d > mxag)
		{
			if(arr[i].l <= mxr)
			{
				cost += max(0LL, arr[i].r - mxr);
				mxr = max(mxr,arr[i].r);
			}
			else
			{
				cost += (arr[i].r - arr[i].l + 1);
				mxr = arr[i].r;
			}
		}
	}

	return (cost * 2) + n + 1  <= t;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> m >> n >> k >> t)
    {
		for(i = 1; i <= m; i++) slld(ag[i]);

		for(i = 1; i <= k; i++)
		{
			slld(arr[i].l);
			slld(arr[i].r);
			slld(arr[i].d);
		}

		sort(ag + 1, ag + 1 + m, comp1);
		sort(arr + 1, arr + 1 + k, comp);

		ans = 0;

		ll lo = 1;
		ll hi = m;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid))
			{
				ans = mid;
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}

		printf("%lld\n", ans);

    }


}


