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

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

ll degree[100005];
vector < ll > graph[100005];
ll dist[100005];
ll fndmn(ll n)
{
    memset(dist,-1,sizeof dist);

    queue < pll > q;

    for(ll i = 1; i <= n; i++)
    {
        if(degree[i] == 1)
        {
            q.push({i,i});
            dist[i] = 0;
        }
    }

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        for(ll it:graph[top.first])
        {
            if(it == top.second) continue;

            if(dist[it] == -1)
            {
                dist[it] = dist[top.first] + 1;
                q.push(make_pair(it,top.first));
            }
            else
            {
                if((dist[it] + dist[top.first] + 1) % 2) return 3;
            }

        }

    }

    return 1;
}

map < pll, bool > mp;

ll fndmx(ll n)
{
	memset(dist,-1,sizeof dist);

    queue < pll > q;
    mp.clear();

    for(ll i = 1; i <= n; i++)
    {
        if(degree[i] == 1)
        {
            q.push({i,i});
            dist[i] = 0;
        }
    }

    ll ans = 0;

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        for(ll it:graph[top.first])
        {
            if(it == top.second) continue;

            if(dist[it] == -1)
            {
                dist[it] = dist[top.first] + 1;
//                cout << it << endl;
                ans++;
                mp[{it,top.first}] = 1;
                q.push(make_pair(it,top.first));
            }
            else
            {
                if((dist[it] + dist[top.first] + 1) > 2)
                {
					if(mp.find({it,top.first}) != mp.end() || mp.find({top.first,it}) != mp.end()) continue;
					mp[{it,top.first}] = 1;
					ans++;
//					cout << it << endl;
                }
            }

        }

    }

    return ans;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            degree[i] = 0;
            graph[i].clear();
        }

        for(i = 1; i < n; i++)
        {
            ll u, v;
            slld(u);
            slld(v);

            graph[u].pb(v);
            graph[v].pb(u);

            degree[u]++;
            degree[v]++;
        }

        ll ans1 = fndmn(n);
        ll ans2 = fndmx(n);

        printf("%lld %lld\n", ans1, ans2);
    }


}



