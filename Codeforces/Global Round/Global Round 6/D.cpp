// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < int,int >

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

deque < pll > graph[100005];

void bfs(ll node)
{

    graph[node].push_back({0,0});

    while(!graph[node].empty())
    {
        pll top = graph[node].front();

        graph[node].pop_front();

        if(top.first == 0) return;

        if(top.first == node) continue;

        while(!graph[top.first].empty() && top.second)
        {
            ll mn = min(top.second,graph[top.first].front().second);

            top.second -= mn;
            graph[top.first].front().second -= mn;

//            cout << top.second << " " << graph[top.first].front().second << " " << mn << endl;

            graph[node].push_front({graph[top.first].front().first,mn});

            if(graph[top.first].front().second == 0) graph[top.first].pop_front();

            if(top.second == 0) break;

//            cout << "OK" << endl;
        }


        if(top.second) graph[node].push_back({top.first,top.second});
    }
}

map < pll, ll > mp;
bool vis[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	fastio;

    slld(n);
    slld(m);
    {
        for(i = 1; i <= n; i++) graph[i].clear();

        for(i = 1; i <= m; i++)
        {
            ll u, v, w;
            slld(u);
            slld(v);
            slld(w);
            graph[u].push_back({v,w});
        }

		if(n == 1000 && m == 300000) bug;

        memset(vis,0,sizeof vis);

        for(i = 1; i <= n; i++)
        {
            bfs(i);
        }

        mp.clear();

        if(n == 1000 && m == 300000) bug;

		for(i = 1; i <= n; i++)
        {
			for(auto it: graph[i])
			{
				mp[{i,it.first}] += it.second;
			}
        }

        cout << mp.size() << "\n";

        for(auto it: mp)
        {
			cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
        }

//        cout << "Done" << endl;
    }


}



