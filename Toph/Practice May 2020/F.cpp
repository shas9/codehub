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
bool flag;

void dfs(ll node, ll par, ll sum)
{
	if(arr[node] == 0 && sum) arr[node] = sum;

	if(sum && sum != arr[node])
	{
//		bug;
		flag = 1;
		return;
	}

	sum = arr[node];
	ll tot = 0;
	ll no = 0;

	for(auto it: g[node])
	{
		if(it == par) continue;

		tot += arr[it];

		if(arr[it] == 0) no++;
	}

//	cout << node << " " << sum << " " << tot << " " << no << endl;
	if(sum)
	{
		if(tot > sum) flag = 1;
		if(tot == sum && no) flag = 1;
		if(sum - tot < no)
		{
	//		cout << node << " " << sum << " " << tot << " " << no << endl;

//			bug;
			flag = 1;
		}
	}

	if(sum - tot == no && no)
	{
		for(auto it: g[node]) if(it != par && arr[it] == 0) arr[it] = 1;
	}

//	cout << flag << endl;

	for(auto it: g[node])
	{
		if(it == par) continue;

		ll x = arr[it];

		if(no == 1 && x == 0) dfs(it,node,sum - tot);
		else dfs(it,node,0);

		if(arr[it] && !x) no--, tot += arr[it];
	}

	if(no > 1)
	{
//		bug;
		flag = 1;
	}

	if(no == 0 && g[node].size() > 1)
	{
		ll sum = 0;

		for(auto it: g[node])
		{
			if(it == par) continue;

			sum += arr[it];
		}


		if(arr[node] > 0)
		{
			if(arr[node] != sum)
			{
				flag = 1;
//				cout << node << ": " << arr[node] << " " << sum << endl;
			}
		}
		else arr[node] = sum;

//		cout << node << ": " << sum << " && " << arr[node] << endl;
	}

	if(no == 1)
	{
		for(auto it: g[node])
		{
			if(it == par) continue;

			if(arr[it] == 0) dfs(it,node,sum - tot);
		}
	}

	if(arr[node] == 0) flag = 1;
}

void dfs1(ll node, ll par)
{
	cout << node << " " << par << endl;

	for(auto it: g[node])
	{
		if(it != par) dfs1(it,node);
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		flag = 0;
		for(i = 1; i <= n; i++) g[i].clear();

		for(i = 2; i <= n; i++)
		{
			slld(input);

			g[i].pb(input);
			g[input].pb(i);
		}

//		dfs1(1,0);

		for(i = 1; i <= n; i++) slld(arr[i]);

		dfs(1,0,0);
//		for(i = 1; i <= n; i++) if(arr[i] <= 0) flag = 1;

//		cout << flag << endl;

		if(flag) printf("impossible\n");
		else
		{
//			printf("Yes\n");
			for(i = 1; i <= n; i++) printf("%lld\n", arr[i]);
		}
    }


}


