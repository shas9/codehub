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

vector < ll > graph[300005];
ll n, x, y;
bool vis[300005];

//ll bfs(ll st)
//{
//    queue < ll > q;
//    for(ll i = 1; i <= n; i++) vis[i] = 0;
//
//    q.push(st);
//
//    vis[st] = 1;
//    ll cnt = 0;
//
//    while(!q.empty())
//    {
//        ll top = q.front();
//        q.pop();
//
//        ll sz = graph[top].size();
//
//        for(ll i = 0; i < sz; i++)
//        {
//            ll u = graph[top][i];
//
//            if(vis[u] == 1 || u == y) continue;
//
//            cnt++;
//
//            vis[u] = 1;
//            q.push(u);
//        }
//    }
//
//    return cnt;
//}

ll bfs0(ll st)
{
    queue < ll > q;
    for(ll i = 1; i <= n; i++) vis[i] = 0;

    q.push(st);

    vis[st] = 1;
    ll cnt = 0;
    vis[y] = 1;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        ll sz = graph[top].size();

        for(ll i = 0; i < sz; i++)
        {
            ll u = graph[top][i];

            if(vis[u] == 1 || u == x) continue;

            cnt++;

            vis[u] = 1;
            q.push(u);
        }
    }

    return cnt;
}
int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(x);
    slld(y);

    ll cnt = 0;

    for(i = 1; i <= n - 1; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        graph[u].pb(v);
        graph[v].pb(u);
    }

    cnt = n * (n - 1);
    cnt /= 2;

    //cout << cnt << endl;


    ll sz = graph[y].size();
    ans = 1;

    for(i = 0; i < sz; i++)
    {
        ll u = graph[y][i];

        if(u == 0) continue;

        ans *= bfs0(u);
    }

    if(ans > 1)
    cnt += ans;

    cout << cnt << endl;


}


