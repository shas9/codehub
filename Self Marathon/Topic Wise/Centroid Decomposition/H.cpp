// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

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

ll tree[mx * 2];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update1(ll idx, ll x, ll nn) //n is the size of the array, x is the number to add
{
       while(idx<=nn)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll dist[mx];
ll n, ans;
vector < pll > g[mx];
ll l, w;

struct info
{
	ll t, l, w;
};

vector < info > vec;

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

void update(ll node, ll par, ll len, ll wei)
{
//	cout << node << " " << len << " " << wei << endl;
	if(len <= l && wei <= w)
	{
		vec.pb({0, len, wei});
		vec.pb({1, l - len, w - wei});
	}

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			update(it.first,node,len + 1, wei + it.second);
		}
	}
}

bool comp(info a, info b)
{
	if(a.w != b.w) return a.w > b.w;

	return a.t > b.t;
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

	vec.clear();

	update(cen,-1,0,0);

	sort(vec.begin(),vec.end(),comp);

//	cout << cen << ": " << endl;
//
//	for(info it: vec)
//	{
//		cout << it.t << " & " << it.l << " & " << it.w << endl;
//	}

//	cout << "Ans: ";

	for(info it: vec)
	{
		if(it.t == 0) ans += query(n + 1) - (it.l == 0? 0: query(it.l));
		else update1(it.l + 1,1,n + 1);

//		if(!it.t)cout << ans << ", ";
	}

	for(info it: vec)
	{
		if(it.t == 1) update1(it.l + 1,-1,n + 1);
	}

//	cout << ans <<  " () ";
	for(auto it: g[cen])
	{
		if(done[it.first] == false)
		{
			vec.clear();

			update(it.first, cen, 1, it.second);

			sort(vec.begin(),vec.end(),comp);

			for(info it: vec)
			{
				if(it.t == 0) ans -= query(n + 1) - (it.l == 0? 0: query(it.l));
				else update1(it.l + 1,1,n + 1);
			}

			for(info it: vec)
			{
				if(it.t == 1) update1(it.l + 1,-1,n + 1);
			}
		}
	}

	ans--;
//	cout << ans << endl;

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
    ll i, j, k, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> l >> w)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 2; i <= n; i++)
		{
			ll p, w2;

			slld(p);
			slld(w2);

			g[i].pb({p,w2});
			g[p].pb({i,w2});
		}

		ans = 0;
		decompose(1);

		assert(!(ans & 1));
		printf("%lld\n", ans / 2);
    }


}



