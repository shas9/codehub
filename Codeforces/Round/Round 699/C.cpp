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

map < ll, ll > mp;
vector < ll > g[100005];
ll a[100005];
ll b[100005];
ll c[100005];
vector < ll > seq;
vector < ll > extra;
bool solve(ll n, ll m)
{
	extra.clear();
	seq.clear();

	for(ll i = 1; i <= m; i++)
	{
		if(!g[c[i]].empty())
		{
			while(!extra.empty())
			{
				seq[extra.back()] = g[c[i]].back();
				extra.pop_back();
			}

			seq.push_back(g[c[i]].back());
			g[c[i]].pop_back();
		}
		else if(mp.find(c[i]) == mp.end())
		{
			extra.push_back(seq.size());
			seq.push_back(-1);
		}
		else
		{
			while(!extra.empty())
			{
				seq[extra.back()] = mp[c[i]];
				extra.pop_back();
			}

			seq.push_back(mp[c[i]]);
		}
	}

	for(ll i = 1; i <= n; i++) if(!g[i].empty()) return 0;

	if(extra.size()) return 0;

	return 1;
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
		cin >> n >> m;

		mp.clear();

		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();

			cin >> a[i];
		}

		for(ll i = 1; i <= n; i++)
		{
			cin >> b[i];

			if(b[i] != a[i]) g[b[i]].pb(i);

			mp[b[i]] = i;
		}

		for(ll i = 1; i <= m; i++) cin >> c[i];

		if(solve(n,m))
		{
			cout << "Yes\n";

			for(auto it: seq) cout << it << " ";
			cout << "\n";
		}
		else
		{
			cout << "No\n";
		}

    }


}



