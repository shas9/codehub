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

struct city
{
	ll xx, yy;
	ll id, pw, cn;
} arr[2003];

bool comp(city a, city b)
{
	if(a.pw == b.pw) return a.cn > b.cn;

	return a.pw < b.pw;
}

pll vis[2003];
bool vis2[2003];

vector < ll > ps;
vector < pll > wc;
ll taka;
ll n;

void dfs(ll node)
{
	for(ll i = 1; i <= n; i++)
	{
		if(i == node) continue;

		ll dist = abs(arr[node].xx - arr[i].xx) + abs(arr[i].yy - arr[node].yy);
		ll cost = (dist * (arr[node].cn + arr[i].cn));

		if(vis[i].second > cost)
		{
			vis[i].second = cost;
			vis[i].first = node;
		}
	}

}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++)
		{
			slld(arr[i].xx);
			slld(arr[i].yy);
		}
		for(i = 1; i <= n; i++)
		{
			slld(arr[i].pw);
			arr[i].id = i;
		}

		for(i = 1; i <= n; i++)
		{
			slld(arr[i].cn);
		}

		sort(arr + 1, arr + 1 + n, comp);

		ps.clear();
		wc.clear();
		memset(vis2,0,sizeof vis2);
		taka = 0;

		for(i = 1; i <= n; i++)
		{
			vis[i] = {0,arr[i].pw};
		}

		for(i = 1; i <= n; i++)
		{
			dfs(i);
		}

		for(i = 1; i <= n; i++)
		{
			taka += vis[i].second;

			if(vis[i].first) wc.push_back({arr[vis[i].first].id,arr[i].id});
			else ps.push_back(arr[i].id);
		}

		cout << taka << "\n";

		cout << ps.size() << "\n";

		for(auto it: ps) cout << it << " ";
		cout << "\n";

		cout << wc.size() << "\n";

		for(auto it: wc) cout << it.first << " " << it.second << "\n";

    }


}




