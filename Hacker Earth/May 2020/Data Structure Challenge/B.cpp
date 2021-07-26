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

ll cond[100005];
vector < ll > graph[100005];
ll vis[100005];
ll onff[100005];
ll col[100005];

void process(ll st)
{
	queue < ll > qq;

	qq.push(st);
	vis[st] = st;
	col[st] = 0;

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		for(auto it: graph[top])
		{
			if(cond[it] == -1 && cond[top] == -1) continue;

			if(vis[it] == -1)
			{
				if(cond[it] == 1 && cond[top] == 1)
				{
					col[it] = col[top] ^ 1;
					vis[it] = st;
					qq.push(it);
				}
				else
				{
					col[it] = col[top];
					vis[it] = st;
					qq.push(it);
				}
			}
			else
			{
				if(cond[it] == 1 && cond[top] == 1)
				{
					if(col[it] == col[top]) onff[st] = 0;
				}
				else
				{
					if(col[it] != col[top]) onff[st] = 0;
				}
			}
		}
	}

	if(onff[st] == -1) onff[st] = 1;
}

bool solve(ll a, ll b, ll c)
{
	if(onff[vis[a]] == 0 || onff[vis[b]] == 0) return 0;

	if(vis[a] != vis[b]) return 1;

	if(col[a] == col[b])
	{
		return (c == 0);
	}

	return c;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		for(i = 1; i <= n; i++)
		{
			graph[i].clear();

			vis[i] = cond[i] = col[i] = onff[i] = -1;
		}

		for(i = 1; i <= n; i++) slld(cond[i]);

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);
		}

		for(i = 1; i <= n; i++)
		{
			if(vis[i] == -1) process(i);
		}

		for(i = 1; i <= k; i++)
		{
			ll a, b, c, d;

			slld(a);
			slld(b);
			slld(c);
			slld(d);

			if(solve(a,b,abs(c-d))) printf("YES\n");
			else printf("NO\n");
		}
    }


}



