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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll mx = 100005;

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll n, k;
ll ans[mx];
vector < pll > g[mx];
vector < pll > qq[mx];
vector < ll > pnt;
ll tree[mx];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

void dfs(ll node, ll par)
{
	sz[node] = 1;

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			dfs(it.first,node);
			sz[node] += sz[it.first];
		}
	}
}

void calc(ll node, ll par, ll d)
{
	for(auto it: qq[node])
	{
		ll need = it.first - d;
		ll idx = lower_bound(pnt.begin(),pnt.end(), need + 1) - pnt.begin();

		if(idx) ans[it.second] += query(idx);
	}

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
			calc(it.first,node, d + it.second);
	}
}

void update1(ll node, ll par, ll d)
{
	pnt.push_back(d);

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			update1(it.first,node,d + it.second);
		}
	}
}

void update2(ll node, ll par, ll d)
{
//	cout << node << " " << par << " " << d << endl;
	ll idx = lower_bound(pnt.begin(),pnt.end(), d) - pnt.begin();

//	cout << idx + 1 << " " << pnt.size() << endl;
	update(idx + 1, 1, pnt.size());

	for(auto it: g[node])
	{
//		cout << it.first << endl;
		if(it.first != par && done[it.first] == false)
		{
			update2(it.first,node,d + it.second);
		}
	}
}

void rem(ll node, ll par, ll d)
{
	ll idx = lower_bound(pnt.begin(),pnt.end(), d) - pnt.begin();

	update(idx + 1, -1, pnt.size());

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			rem(it.first,node,d + it.second);
		}
	}
}

ll decompose(ll cen)
{
	dfs(cen,-1);

	ll target = sz[cen] / 2;
	ll p = -1;
	bool ok = false;

	while(!ok)
	{
		ok = true;

		for(auto it: g[cen])
		{
			if(it.first != p && done[it.first] == false && sz[it.first] > target)
			{
				ok = false;
				p = cen;
				cen = it.first;
				break;
			}
		}
	}

	done[cen] = true;

	pnt.clear();
	update1(cen,-1,0);

	sort(pnt.begin(),pnt.end());
	pnt.erase(unique(pnt.begin(),pnt.end()), pnt.end());

//	cout << cen << ": ";
//
//	for(auto it: pnt) cout << it << ", ";
//	cout << endl;

	update2(cen,-1,0);

	for(auto it: qq[cen])
	{
		ll need = it.first;
		ll idx = lower_bound(pnt.begin(),pnt.end(), need + 1) - pnt.begin();

		if(idx) ans[it.second] += query(idx);
	}

	for(auto it: g[cen])
	{
		if(done[it.first] == false)
		{
			rem(it.first,cen, it.second);

	//			cout << "Tree: ";
	//
	//			for(ll i = 1; i <= pnt.size(); i++) cout << query(i) << " ";
	//			cout << endl;

			calc(it.first,cen, it.second);
			update2(it.first,cen, it.second);
		}
	}

	rem(cen,-1,0);

	for(auto it: g[cen])
	{
		if(done[it.first] == false)
		{
			cenpar[decompose(it.first)] = cen;
		}
	}

	return cen;
}

int main()
{
    ll i, j, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;

    cin >> n >> m;

    for(ll i = 1; i < n; i++)
    {
		ll u, v, w;

		cin >> u >> v >> w;

		g[u].pb({v,w});
		g[v].pb({u,w});
	}

	for(ll i = 1; i <= m; i++)
	{
		ll v, l;

		cin >> v >> l;

		qq[v].push_back({l,i});
	}

	decompose(1);

	for(ll i = 1; i <= m; i++)
	{
		cout << ans[i] << "\n";
	}

}



