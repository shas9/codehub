#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector <ll> graph[20009];
bool visit[20009];
bool visited[20009];
ll cnt[20009];

int main()

{
    ll t, caseno = 0;
    scanf("%lld", &t);

    while(t--)
    {
        ll n;
        scanf("%lld", &n);
       // memeset(visit, 0, sizeof(visit));
        for(ll i = 1; i < n; i++)
        {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

//        queue <ll> q;
//

        ll mx =0;
        ll k;
        for(ll x=1; x<=n; x++)
        {
            for(ll i=0;i<graph[x].size();i++)
            {
                ll tmp=graph[x][i];
                if(graph[tmp].size()==1)
                {
                    cnt[x]++;
                    if(mx<cnt[x]){
                        k=x;
                        mx=cnt[x];
                        //cout << x << " rhekhfrih " << mx << endl;
                    }
                }
            }
        }
        //cout << " ejfgejgfej " << cnt[k] << endl;
        ll ans=n-cnt[k]-1;
        ans=ans*cnt[k];
        //cout << ans << endl;
        ans=ans+(cnt[k]* (cnt[k]-1) ) /2;
        printf("Case #%lld: %lld\n",++caseno,ans);

        for(ll i = 1; i <= n; i++)
            graph[i].clear();
        memset(cnt, 0, sizeof(cnt));
    }

}
