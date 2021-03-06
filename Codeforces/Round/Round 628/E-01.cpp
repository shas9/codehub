#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int
#define ull unsigned long long
#define pll pair < int, int >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e8
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

vector < pll > edge;
vector < ll > divv[1000006], graph[1000006];
vector < ll > prime;

ll dist[1000006];
ll vis[1000006];
ll arr[100006];

ll n;

void precalc()
{
    prime.push_back(1);

    for(ll i = 2; i <= 1000000; i++)
    {
        if(vis[i] == 0)
        {
            for(ll j = i; j <= 1000000; j += i)
            {
                vis[j] = i;
            }

            prime.push_back(i);
        }

        divv[i] = divv[i / vis[i]];

        vector < ll > :: iterator it = find(divv[i].begin(),divv[i].end(),vis[i]);

        if(it != divv[i].end())
        {
            divv[i].erase(it);
        }
        else
        {
            divv[i].push_back(vis[i]);
        }
    }
}

ll bfs(ll pp)
{
    if(graph[pp].size() == 0) return mxlld;

    queue < pll > qq;

    for(ll i = 0; i < prime.size(); i++) dist[prime[i]] = 0;

    for(ll i = 0; i < graph[pp].size(); i++)
    {
        qq.push(make_pair(graph[pp][i], pp ^ edge[graph[pp][i]].first ^ edge[graph[pp][i]].second));
        dist[pp ^ edge[graph[pp][i]].first ^ edge[graph[pp][i]].second] = 1;

//        cout << "Pushed: " << graph[pp][i] << endl;
    }

    ll ret = mxlld;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();

//        cout << top.first << " " << top.second << endl;
//        if(edge[top.first].second == top.second)
//        {
//            swap(edge[top.first].first, edge[top.first].second);
//        }

        for(ll i = 0; i < graph[top.second].size(); i++)
        {
            ll xx = graph[top.second][i];

            if(xx == top.first) continue;

            ll nn = top.second ^ edge[xx].first ^ edge[xx].second;

//            cout << xx << " ~~ " << dist[xx] << endl;
//            cout << top.first << " ~ " << dist[top.first] << endl;

//            cout << xx << " " << nn << " ~ " << dist[nn] << endl;
//
//            cout << dist[nn] << " ~~ " << dist[edge[top.first].second] << endl;

            if(dist[nn] == 0 && nn != pp)
            {
                dist[nn] = dist[top.second] + 1;
                qq.push(make_pair(xx,nn));
            }
            else
            {
                ret = min(ret,dist[nn] + dist[top.second] + 1);

            }
        }
    }

//    cout << pp << " = " << ret << endl;

    return ret;

}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    precalc();

//    cout << prime.size() << endl;

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    edge.push_back(make_pair(0,0));

    for(i = 1; i <= n; i++)
    {
        if(divv[arr[i]].size() == 0)
        {
            cout << 1 << endl;
            return 0;
        }

        if(divv[arr[i]].size() == 1) divv[arr[i]].push_back(1);

        edge.push_back(make_pair(divv[arr[i]][0],divv[arr[i]][1]));

        graph[edge[i].first].push_back(i);
        graph[edge[i].second].push_back(i);



    }

    ans = mxlld;

    for(i = 0; prime[i] * prime[i] <= 1000000; i++)
    {
        ans = min(ans,bfs(prime[i]));
    }

    if(ans == mxlld)
        cout << -1 << endl;
    else cout << ans << endl;




}


