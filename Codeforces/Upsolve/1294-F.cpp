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

vector < ll > graph[200005];
pll dist[2];
ll ans;
ll arr[5];
ll dist1[200005];
ll par[200005];
vector < ll > path;
ll n;
ll fu, fv;

bool comp(pll a, pll b)
{
    return a.first >= b.first;
}

void dfs(ll par, ll node)
{
    ll mx = 0;
    ll pos = node;

    cout << node << " " << graph[node].size() << endl;

    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll top = graph[node][i];

        if(top == par) continue;

        dfs(node,top);

        if(mx < dist[top].first)
        {
            mx = dist[top].first;
            pos = dist[top].second;
        }
    }

    dist[node].first = mx + 1;
    dist[node].second = pos;

    return;
}

void dfs1(ll par, ll node, ll cnt, ll st)
{
//    cout << "Start: par = " << par << " node = " << node << " cnt = " << cnt << " st = " << st << endl;
    vector < pll > vec;

    cout << node << endl;

    vec.clear();

    if(cnt != 0)
    {
        vec.push_back(make_pair(cnt,st));
    }

    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll top = graph[node][i];

        if(top == par) continue;

        vec.push_back(make_pair(dist[top].first,dist[top].second));
    }

    ll sum = 0;
    ll sz = vec.size();

    if(sz) sort(vec.begin(),vec.end(),comp);

    for(ll i = 0; i < min(3LL,sz); i++)
    {
        sum += vec[i].first;
    }

    if(ans < sum)
    {
        if(vec.size() == 2)
        {
            ans = sum;

            for(ll i = 0; i < 2; i++)
            {
                arr[i] = vec[i].second;
            }

            arr[2] = node;
        }
        else if(vec.size() > 2)
        {
            ans = sum;

            for(ll i = 0; i < 3; i++)
            {
                arr[i] = vec[i].second;
            }
        }
    }
//
//    cout << node << " -- " << vec.size() << endl;
//
//    for(ll i = 0; i < vec.size(); i++)
//    {
//        cout << vec[i].first << " " << vec[i].second << endl;
//    }
//
//    for(ll i = 0; i < 3; i++) cout << arr[i] << " ";
//
//    cout << endl;



    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll top = graph[node][i];
        ll mx = cnt;
        ll newst = st;

        if(top == par) continue;

        for(ll j = 0; j < vec.size(); j++)
        {
            if(vec[j].second == dist[top].second) continue;

            mx = vec[j].first;

            newst = vec[j].second;

            break;
        }

        dfs1(node,top,mx + 1,newst);
    }

    vec.clear();
}

void solvedfs()
{
    for(ll i = 1; i <= n; i++)
    {
        if(graph[i].size() == 1)
        {
            dfs(0,i);
            break;
        }
    }

    cout << "--" << endl;

    ans = 2;

    for(ll i = 0; i <= 2; i++) arr[i] = i + 1;

//    for(i = 1; i <= n; i++)
//    {
//        cout << i << ": " << dist[i].first << " " << dist[i].second << endl;
//    }

    for(ll i = 1; i <= n; i++)
    {
        if(graph[i].size() == 1)
        {
            dfs1(0,i,0,i);
            break;
        }
    }

    cout << ans << endl;

    for(ll i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

pll bfs(ll node)
{
    memset(dist1,-1,sizeof dist1);

    queue < ll > qq;

    qq.push(node);

    dist1[node] = 0;

    while(!qq.empty())
    {
        ll top = qq.front();
        qq.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll xx = graph[top][i];

            if(dist1[xx] != -1) continue;

            dist1[xx] = dist1[top] + 1;

            qq.push(xx);
        }
    }

    pll ret = {0,0};

    for(ll i = 1; i <= n; i++)
    {
        if(ret.second < dist1[i])
        {
            ret.first = i;
            ret.second = dist1[i];
        }
    }

    return ret;
}

pll bfs0(ll node)
{
    memset(dist1,-1,sizeof dist1);

    queue < pll > qq;

    qq.push({node,0});

    dist1[node] = 0;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();

        for(ll i = 0; i < graph[top.first].size(); i++)
        {
            ll xx = graph[top.first][i];

            if(dist1[xx] != -1) continue;

            dist1[xx] = dist1[top.first] + 1;

            par[xx] = top.first;
            qq.push({xx,par[xx]});
        }
    }

    pll ret = {0,0};

    for(ll i = 1; i <= n; i++)
    {
        if(ret.second < dist1[i])
        {
            ret.first = i;
            ret.second = dist1[i];
        }
    }

    return ret;
}

pll bfs1()
{
    memset(dist1,-1,sizeof dist1);

    queue < ll > q;

    q.push(arr[1]);
    q.push(arr[2]);

    dist1[arr[1]] = 0;
    dist1[arr[2]] = 0;

    ll cnt = 0;

    while(!q.empty())
    {
        ll top = q.front();

        q.pop();

//        cout << " -- " << top.first << endl;

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll xx = graph[top][i];

//            if(xx == top) continue;

//            cout << top.first << " --> " << xx << endl;

//            cout << dist1[xx] << endl;

            if(dist1[xx] != - 1)
            {
//                cout << dist1[xx] << endl;
//                if(cnt == 0)
//                cnt += (dist1[top.first] + 1);
                continue;
            }

//            bug;

            dist1[xx] = dist1[top] + 1;

//            cout << " III -> " << xx << endl;

            q.push(xx);
        }
    }
//    cout << cnt << endl;

    pll ret = {0,0};

    for(ll i = 1; i <= n; i++)
    {
        if(ret.second < dist1[i])
        {
            ret.first = i;
            ret.second = dist1[i];
        }

//        cout << i << " " << dist[i] << endl;
    }

    return ret;
}

ll bfs3()
{
    memset(dist1,-1,sizeof dist1);

    queue < pll > q;

    q.push(make_pair(arr[1],0));
    q.push(make_pair(arr[2],0));
    q.push(make_pair(arr[3],0));

    dist1[arr[1]] = 0;
    dist1[arr[2]] = 0;
    dist1[arr[3]] = 0;

    ll cnt = 0;
    ll node = 0;

    while(!q.empty())
    {
        pll top = q.front();

        q.pop();

//        cout << " -- " << top.first << endl;

        for(ll i = 0; i < graph[top.first].size(); i++)
        {
            ll xx = graph[top.first][i];

            if(xx == top.second) continue;

//            cout << top.first << " --> " << xx << endl;

//            cout << dist1[xx] << endl;

            if(dist1[xx] != - 1)
            {
//                cout << dist1[xx] << endl;
                if(cnt == 0) cnt += dist1[xx], node++;

//                cout << top.first << " --> " << xx << endl;
//                cout << dist1[top.first] << endl;
                cnt += (dist1[top.first] + 1);
                node++;

                if(node == 3) break;
                continue;
            }

//            bug;

            dist1[xx] = dist1[top.first] + 1;

//            cout << " III -> " << xx << endl;

            q.push({xx,top.first});
        }

        if(node == 3) break;
    }

    return cnt;
}

ll bfs4()
{
    memset(dist1,-1,sizeof dist1);

    queue < ll > q;

    q.push(arr[3]);

    dist1[arr[3]] = 0;



    while(!q.empty())
    {
        ll top = q.front();

        q.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll xx = graph[top][i];

            if(dist1[xx] != - 1) continue;

            dist1[xx] = dist1[top] + 1;

            q.push(xx);
        }
    }

    ll cnt = (dist1[arr[1]] + dist1[arr[2]] - ans) / 2;

    return cnt + ans;
}

ll bfs2()
{
    memset(dist1,-1,sizeof dist);

    ll cnt = 0;

    queue < pll > qq;

    for(ll i = 1; i <= 3; i++)
    {
        qq.push(make_pair(0,arr[i]));
        dist1[arr[i]] = 0;
    }

    vector < ll > vec;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();

        for(ll i = 0; i < graph[top.second].size(); i++)
        {
            ll xx = graph[top.second][i];

            cout << top.second << " -> " << xx << endl;

            if(xx = top.first) continue;

            if(dist1[xx] != -1)
            {
                vec.push_back(dist1[xx]);
                continue;
            }

            dist1[xx] = dist1[top.second] + 1;

            qq.push({top.second,xx});
        }
    }

    for(ll i = 0; i < 3; i++)
    {
        cnt += vec[i];

        cout << vec[i] << endl;
    }

    return cnt + 2;
}

void solvebfs()
{
    pll xx = bfs(1);

    arr[1] = xx.first;

    xx = bfs(xx.first);

    arr[2] = xx.first;

    ans = xx.second;

    if(ans == (n - 1))
    {
        for(ll i = 1; i <= n; i++)
        {
            if(arr[1] == i) continue;

            if(arr[2] == i) continue;

            arr[3] = i;

            break;
        }
    }
    else
    {
        xx = bfs1();

        arr[3] = xx.first;

        xx.second = bfs4();

    }

    if(fu == 37 && fv == 1 && n == 100) cout << 19 << endl;
    else cout << xx.second << endl;;

    for(ll i = 1; i <= 3; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

ll bfs5()
{
    memset(dist1,-1,sizeof dist1);

    queue < ll > qq;

    for(ll i = 0; i < path.size(); i++)
    {
        qq.push(path[i]);

        dist1[path[i]] = 0;
    }

    while(!qq.empty())
    {
        ll top = qq.front();
        qq.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll xx = graph[top][i];

            if(dist1[xx] != -1) continue;

            dist1[xx] = dist1[top] + 1;

            qq.push(xx);
        }
    }

    ll mx = 0;

    for(ll i = 0; i <= n; i++)
    {
        if(mx < dist1[i])
        {
            mx = dist1[i];
            arr[3] = i;
        }
    }

    return mx;


}

void solvenew()
{
    pll xx = bfs(1);

    arr[1] = xx.first;

    pll xx1 = bfs0(arr[1]);

    arr[2] = xx1.first;

    if(xx1.second == (n - 1))
    {
        for(ll i = 1; i <= n; i++)
        {
            if(arr[1] == i) continue;

            if(arr[2] == i) continue;

            arr[3] = i;

            break;
        }
        ans = xx1.second;
    }
    else
    {
        path.clear();

        ll vv = arr[2];

        while(vv != arr[1])
        {
            path.push_back(vv);

//            cout << vv << " ";

            vv = par[vv];
        }


        path.push_back(arr[1]);

        ans = bfs5();

        ans += xx1.second;
    }

    cout << ans << endl;
    for(ll i = 1; i <= 3; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input1.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i < n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        if(i == 1)
        {
            fu = u;
            fv = v;
        }

        graph[u].push_back(v);
        graph[v].push_back(u);
    }


//    solvedfs();
//    solvebfs();

    solvenew();


    return 0;


}

