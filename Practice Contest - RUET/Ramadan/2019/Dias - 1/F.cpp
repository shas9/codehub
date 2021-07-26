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

#define maxn 100005
using namespace std;

vector < ll > freq[maxn];
vector < pll > graph[maxn];

ll cond[maxn];
ll col[maxn];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        memset(col,-1,sizeof col);

        cin >> m;

        for(i = 1; i <= n; i++) freq[i].clear();
        for(i = 1; i <= m; i++) graph[i].clear();

        for(i = 1; i <= n; i++) slld(cond[i]);

        for(i = 1; i <= m; i++)
        {
            slld(k);

            for(j = 1; j <= k; j++)
            {
                slld(input);

                freq[input].pb(i);
            }
        }

        for(i = 1; i <= n; i++)
        {
            graph[freq[i][0]].pb(make_pair(freq[i][1],cond[i]));

            graph[freq[i][1]].pb(make_pair(freq[i][0],cond[i]));
        }

        queue < ll > q;

        bool chk = 0;

        for(i = 1; i <= m; i++)
        {
            if(chk) break;

            if(col[i] == -1)
            {
                col[i] = 0;

                while(!q.empty()) q.pop();

                q.push(i);

                while(!q.empty())
                {
                    ll ad = q.front();
                    q.pop();

                    ll sz = graph[ad].size();

                    ll _col = col[ad];

                    for(j = 0; j < sz; j++)
                    {
                        pll temp = graph[ad][j];

                        if(col[temp.first] == -1)
                        {
                            if(temp.second == 0)
                            {
                                col[temp.first] = _col ^ 1;
                            }
                            else
                            {
                                col[temp.first] = _col;
                            }

                            q.push(temp.first);
                        }
                        else
                        {
                            if(temp.second == 0 && (col[temp.first] == _col)) chk = 1;

                            if(temp.second == 1 && (col[temp.first] != _col)) chk = 1;
                        }
                    }

                }
            }
        }

        if(chk) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


}


