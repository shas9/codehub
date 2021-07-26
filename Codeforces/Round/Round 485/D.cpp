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
#define maxn 100005

using namespace std;

vector < ll > graph[maxn];
vector < pair < ll, ll > > arr;
ll store[maxn][110];

queue < ll > q;

void bfs(ll n)
{
    while(!q.empty())
    {
        ll top = q.front();
        q.pop();
        ll sz = graph[top].size();

        for(ll i = 0; i < sz; i++)
        {
            ll j = graph[top][i];

            if(store[j][n] != 0) continue;

            store[j][n] = store[top][n] + 1;

            q.push(j);
        }
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    ll s;
    cin >> n >> m >> s >> k;

    for(i = 1; i <= n; i++)
    {
        slld(input);

        arr.pb(make_pair(input,i));
    }

    sort(arr.begin(),arr.end());

    for(i = 1; i <= m; i++)
    {
        ll u, v;
        slld(u);
        slld(v);

        graph[u].pb(v);
        graph[v].pb(u);
    }
    j = 0;
    for(i = 1; i <= s; i++)
    {
        while(!q.empty()) q.pop();

        while(arr[j].first == i)
        {
            q.push(arr[j].second);

            store[arr[j].second][i] = 1;

            j++;

            if(j == n) break;
        }

        bfs(i);
    }

    for(i = 1; i <= n; i++)
    {
        ll sum = 0;
        sort(store[i] + 1, store[i] + 1 + s);
        for(j = 1; j <= k; j++)
        {
            sum += store[i][j];
        }

        cout << sum - k << " ";
    }

    cout << endl;

}


