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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009

using namespace std;

ll school[100000+5];
vector < pair<ll,ll> > graph[100000+10];
ll ans;

bool visit[100005];
ll dist[100005];
ll n;

void bfs()
{
  memset(visit,false,sizeof(visit));

  queue < ll > q;

  q.push(0);

  visit[0] = 1;
  dist[0] = 0;

  pair < ll, ll > x;

  ll total = 0;

  while(!q.empty())
  {
      ll top = q.front();
      q.pop();

      for(ll i = 0; i < graph[top].size(); i++)
      {
          x = graph[top][i];

          ll v = x.first;
          ll cost = x.second;

          if(visit[v] == false)
          {
              visit[v] = true;
              dist[v] = dist[top] + cost;
              total += cost;

              q.push(v);
          }
      }
  }

  total *= 2;
  ans = (total - dist[0]) + school[0];

  for(ll i = 1; i < n; i++)
  {
      ll res = (total -dist[i]) + school[i];

      ans = min(ans,res);
  }
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag;

    ll u, v, w;

    slld(m);

    n = m + 1;
    ans = 0;
    for(i = 0; i < n; i++)
    {
        slld(school[i]);
    }

    for(i = 0; i < m; i++)
    {
        slld(u);
        slld(v);
        slld(w);

        pair <ll, ll> x;

        x.first = v;
        x.second = w;

        graph[u].pb(x);

        x.first = u;
        x.second = w;

        graph[v].pb(x);
    }

    bfs();

    cout << ans << endl;

}

