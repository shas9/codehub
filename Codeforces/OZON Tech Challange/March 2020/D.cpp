#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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

vector < ll > graph[5000];

ll dist[5000];
ll xx, yy;

ll bfs(ll st)
{
    queue < ll > q;

    q.push(st);
    memset(dist,-1,sizeof dist);

    dist[st] = 0;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll x = graph[top][i];

            if(dist[x] != -1) continue;

            dist[x] = dist[top] + 1;

            q.push(x);
        }
    }

    ll node = 0;
    ll mx = 0;

    for(ll i = 1; i <= 1000; i++)
    {
        if(mx < dist[i])
        {
            node = i;
            mx = dist[i];
        }
    }

    return node;
}

vector < ll > vec;

void dfs(ll node)
{
    bool on = 0;

    dist[node] = 0;
    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll x = graph[node][i];
        if(dist[x] != -1) continue;
        on = 1;
        dfs(x);
    }

    if(on == 0 && node != xx && node != yy)
    {
        vec.push_back(node);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i < n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    xx = bfs(i);
    yy = bfs(xx);

    cout<< "? " << xx << " " << yy << endl;

    ll lca;

    cin >> lca;

    memset(dist,-1,sizeof dist);

    dfs(lca);

    ans = lca;

    for(i = 1; i < vec.size(); i += 2)
    {
        cout << "? " << vec[i] << " " << vec[i  - 1] << endl;


        cin >> input;

        if(input != lca)
        {
            ans = input;
            break;
        }
    }

    cout << "! " << ans << endl;


}


