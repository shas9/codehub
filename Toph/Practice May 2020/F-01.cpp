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

vector < ll > g[300005];
ll arr[300005];

void dfs(ll node, ll par)
{
	ll unknown = 0;
	ll sum = 0;

	for(auto it: g[node])
	{
		if(it != par)
		{
//			cout << node << " " << it << endl;
			sum += arr[it];
			if(arr[it] == 0) unknown++;
		}
	}

	if(arr[node])
	{
		if(unknown == 1)
		{
			for(auto it: g[node])
			{
				if(it != par && arr[it] == 0)
				{
					arr[it] = arr[node] - sum;
					break;
				}
			}
		}
		else if(unknown && (arr[node] - sum == unknown))
		{
			for(auto it: g[node])
			{
				if(it != par && arr[it] == 0) arr[it] = 1;
			}
		}
	}

	sum = 0;

	unknown = 0;

	for(auto it: g[node])
	{
		if(it != par)
		{
			dfs(it,node);
			sum += arr[it];
			if(arr[it] == 0) unknown++;
		}
	}

	if(arr[node] == 0 && unknown == 0) arr[node] = sum;
}

bool isposs(ll node, ll par)
{
	ll sum = 0;

	bool ret = 1;

	if(g[node].size() == 1 && node != 1)
	{
		return arr[node] > 0;
	}

	for(auto it: g[node])
	{
		if(it != par)
		{
			sum += arr[it];

			ret &= isposs(it,node);
		}
	}

	return ret &= (sum == arr[node] && arr[node] > 0);
}

void dfs1(ll node, ll par)
{
	ll sum = 0;

	bool no = 0;

	for(auto it: g[node])
	{
		if(it != par)
		{
			dfs1(it,node);
			sum += arr[it];
			if(arr[it] == 0) no = 1;
		}
	}

	if(no) return;

	if(arr[node] == 0)
	{
		arr[node] = sum;
	}
}

void dfs2(ll node, ll par)
{
	ll sum = 0;
	for(auto it: g[node])
	{
		if(it != par)
		{
			dfs2(it,node);
			sum += arr[it];
		}
	}

	if(arr[node] == 0)
	{
		if(sum == 0) arr[node] = 1;
		else arr[node] = sum;
	}
}

void pr(ll n)
{
	for(ll i = 1; i <= n; i++) cout << arr[i] << " ";

	cout << endl;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 2; i <= n; i++)
		{
			slld(input);
			g[input].pb(i);
			g[i].pb(input);
		}

		for(i = 1; i <= n; i++) slld(arr[i]);

		for(i = 1; i <= n; i++) if(arr[i]) break;

		if(i > n)
		{
			printf("impossible\n");
			exit(0);
		}

		dfs1(1,0);
//		pr(n);
		dfs(1,0);
//		pr(n);

		if(arr[1] == 0)
		{
			printf("impossible\n");
			exit(0);
		}
		dfs2(1,0);
//		pr(n);
		dfs(1,0);
//		pr(n);


		if(isposs(1,0) == 0) printf("impossible\n");
		else
		{
			for(i = 1; i <= n; i++) printf("%lld\n", arr[i]);
		}

    }


}


