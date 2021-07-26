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

#define maxn 400005
using namespace std;

vector < ll > graph[maxn];
ll degree[maxn];
ll dist[maxn];
queue < ll > qq;

void dfs(ll node, ll par)
{
    ll sz = graph[node].size();

    for(ll i = 0; i < sz; i++)
    {
        ll top = graph[node][i];

        if(top == par) continue;
        printf("%lld %lld\n", node, top);

        dfs(top,node);
    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);
    slld(k);

    if(m >= n)
    {
        cout << "NO" << endl;
        return 0;
    }

    for(i = 2; i <= m + 1; i++)
    {
        graph[i - 1].push_back(i);

        dist[i] = min(abs(i - 1), abs(m + 1 - i));

        if(dist[i] >= 1)
        {
            qq.push(i);
            degree[i] = 2;

            if(k == 1)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    ll curr = m + 1;

    while(curr < n && !qq.empty())
    {
        ll top = qq.front();
        qq.pop();


        for(i = degree[top]; i < k; i++)
        {
            ++curr;

            graph[top].pb(curr);

            degree[curr] = 1;
            dist[curr] = dist[top] - 1;

            if(dist[curr] >= 1)
            {
                qq.push(curr);
            }

            if(curr == n) break;

        }
    }

    if(curr < n)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    dfs(1,-1);



}


