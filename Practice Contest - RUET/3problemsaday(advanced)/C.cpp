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

const ll tot_nodes = 5e5 + 5;

ll val[tot_nodes];
vector < int > g[tot_nodes];
ll cnt[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];
ll depth[tot_nodes];
ll subtree[tot_nodes];
long long ans, valid;
ll n, m;

stack < pll > st1;
stack < ll > st;
bool vis[tot_nodes];
bool vis2[tot_nodes];

void big_dsu()
{
	memset(vis,0,sizeof vis);

	st1.push({1,0});

	while(!st1.empty())
	{
		ll node = st1.top().first;
		ll d = st1.top().second;

		if(vis[node])
		{
			st1.pop();

			depth[node] = d;

			subtree[node] = 1;
			ll mx = 0;
			ll bigc = -1;

			for(auto it: g[node])
			{
				if(subtree[it] > mx)
				{
					bigc = it;
					mx = subtree[it];
				}

				subtree[node] += subtree[it];
			}

			bigchild[node] = bigc;
			continue;
		}

		vis[node] = 1;

		for(auto it: g[node])
		{
			st1.push({it, d + 1});
		}

	}
}

void add(ll node)
{
	st.push(node);

	while(!st.empty())
	{
		ll nnode = st.top();

		if(vis2[nnode])
		{
			st.pop();

			cnt[depth[nnode]]++;

			if(cnt[depth[nnode]] == val[depth[nnode]]) valid++;

			continue;
		}

		vis2[nnode] = 1;

		for(auto it: g[nnode])
		{
			if(big[it] == 1) continue;

			st.push(it);
		}
	}
}

void rem(ll node)
{
	st.push(node);

	while(!st.empty())
	{
		ll nnode = st.top();

		if(vis2[nnode] == 0)
		{
			st.pop();

			if(cnt[depth[nnode]] == val[depth[nnode]]) valid--;

			cnt[depth[nnode]]--;

			continue;
		}

		vis2[nnode] = 0;

		for(auto it: g[nnode])
		{
			if(big[it] == 1) continue;

			st.push(it);
		}
	}
}

void dfs()
{
	memset(vis,0,sizeof vis);

	st1.push({1,1});

	while(!st1.empty())
	{
		pll top = st1.top();

		if(vis[top.first])
		{
			st1.pop();

			if(bigchild[top.first] != -1)
			{
				big[bigchild[top.first]] = 1;
			}

			add(top.first);

			ans += valid;

			if(bigchild[top.first] != -1)
			{
				big[bigchild[top.first]] = 0;
			}

			if(top.second == 0) rem(top.first);

			continue;
		}

		vis[top.first] = 1;

		if(bigchild[top.first] != -1)
		{
			st1.push({bigchild[top.first], 1});
		}

		for(auto it: g[top.first])
		{
			if(it != bigchild[top.first])
			{
				st1.push({it,0});
			}
		}
	}
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	slld(n);
	slld(m);

    for(ll i = 2; i <= n; i++)
    {
		slld(input);

		input++;

		g[input].pb(i);
    }

    ans = 0;
    valid = 0;

    for(ll i = 0; i <= m; i++)
    {
		slld(val[i]);

		if(val[i] == 0) ans += n;
    }

    big_dsu();


    dfs();

    cout << ans << '\n';

    return 0;
}
