// God put a smile upon your face <3

#include <bits/stdc++.h>

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

vector < vector < ll > > cyc;
map < ll, ll > mp;
map < ll, bool > start;
map < ll, bool > vis;
ll arr[300005];
ll side[300005];
vector < ll > v;

bool cycle(ll node)
{
    if(node == 0) return 1;

    if(mp.find(node) != mp.end()) return 0;

    mp[node] = cyc.size() - 1;

    cyc.back().push_back(node);

    return cycle(side[node]);
}

void build(ll idx)
{
	vis[idx] = 1;

	for(auto it: cyc[idx])
	{
		if(arr[it] != 0)
		{
			if(vis.find(mp[arr[it]]) == vis.end())
			{
//				cout << mp[arr[it]] << " " << arr[it] << " " << it << endl;
				build(mp[arr[it]]);
			}
		}
	}

	for(auto it: cyc[idx]) v.push_back(it);

	return;
}

bool isvalid(ll n)
{
	map < ll, bool > ase;

	for(auto it: v)
	{
		if(arr[it] != 0)
		{
			if(ase.find(arr[it]) == ase.end()) return 0;
		}

		ase[it] = 1;
	}

	return 1;
}

bool solve(ll n)
{
    for(ll i = 1; i <= n; i++)
    {
        if(start.find(i) == start.end())
        {
            cyc.push_back({});

            if(cycle(i) == 0) return 0;
        }
    }

//	cout << cyc.size() << endl;

//    for(auto it: cyc)
//    {
//		for(auto jt: it) cout << jt << " - ";
//
//		cout << endl;
//    }

    v.clear();

    for(ll i = 0; i < cyc.size(); i++)
    {
		if(vis.find(i) == vis.end()) build(i);
    }

    return isvalid(n);
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
        cyc.clear();
        mp.clear();
        start.clear();
        vis.clear();

        memset(side, 0, sizeof side);

        for(ll i = 1; i <= n; i++) slld(arr[i]);

        for(ll i = 1; i <= m; i++)
        {
            ll u, v;
            cin >> u >> v;

            start[v] = 1;

            side[u] = v;
        }

        if(solve(n) == 0) cout << 0 << "\n";
        else
        {
            for(auto it: v) cout << it << " ";
            cout << "\n";
        }
    }


}


