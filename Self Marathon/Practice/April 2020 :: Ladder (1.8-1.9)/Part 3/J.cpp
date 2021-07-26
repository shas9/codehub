// God put a smile upon your face <3

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


vector < vector < ll > > bit;
ll chain[100005];
ll depth[100005];
ll subtree[100005];
vector < ll > graph[100005];

ll query(ll cn, ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=bit[cn][idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll cn, ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             bit[cn][idx]+=x;
             idx += idx & (-idx);
       }
}

void dfs(ll node, ll par, ll cn, ll lev)
{
	chain[node] = cn;
	depth[node] = lev;
	subtree[node] = 0;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it,node,cn,lev + 1);

		subtree[node] = subtree[it];
	}

	subtree[node]++;
}

void update1(ll v, ll x, ll d)
{
	ll rgt = depth[v] + d + 1;
	ll lft = depth[v] - d;

	if(v == 1)
	{
		update(0,1,x,bit[0].size() - 1);
		if(d + 2 <= subtree[1]) update(0,d + 2, -x, bit[0].size() - 1);
		return;
	}

//	cout << depth[v] << endl;
	if(d >= depth[v])
	{
		ll up = d - depth[v];

//		cout << up << endl;
		update(0,1,x,bit[0].size() - 1);
		if(up + 2 <= subtree[1]) update(0,up + 2, -x, bit[0].size() - 1);

		lft = up + 1;
	}

//	cout << chain[v] << " " << bit[chain[v]].size() << " " << lft << " " << rgt << endl;
	if(lft < rgt)
	{
		if(lft <= depth[v] + subtree[v]) update(chain[v],lft,x,bit[chain[v]].size() - 1);
		if(rgt <= depth[v] + subtree[v]) update(chain[v], rgt, -x, bit[chain[v]].size() - 1);
	}
}

ll query1(ll v)
{
	if(v == 1) return query(0,1);

	return query(chain[v],depth[v]) + query(0,depth[v] + 1);
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
		bit.clear();

		for(i = 1; i <= n; i++) graph[i].clear();

		for(i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);

		}

		ll mx = 0;
		chain[1] = 0;
		subtree[1] = 1;

		bit.push_back({});

		for(i = 0; i <= (5 * n); i++) bit.back().push_back(0);

		for(i = 0; i < graph[1].size(); i++)
		{
			bit.push_back({});

			dfs(graph[1][i],1,i + 1,1);

			for(j = 0; j <= (5 * subtree[graph[1][i]]); j++) bit.back().push_back(0);

			subtree[1] += subtree[graph[1][i]];
		}

//
//		for(i = 1; i <= n; i++ ) cout << chain[i] << " ";
//		cout << endl;
//
//		for(i = 1; i <= n; i++ ) cout << depth[i] << " ";
//		cout << endl;
//
//		for(i = 1; i <= n; i++ ) cout << subtree[i] << " ";
//		cout << endl;
//
//		for(i = 0; i < bit.size(); i++) cout << bit[i].size() << " ";
//		cout << endl;

		for(i = 1; i <= m; i++)
		{
			ll t, v, x, d;

			slld(t);
			slld(v);

			if(t == 0)
			{
				slld(x);
				slld(d);

				update1(v,x,d);
			}
			else
			{
				ans = query1(v);

				printf("%lld\n", ans);
			}
		}
     }


}



