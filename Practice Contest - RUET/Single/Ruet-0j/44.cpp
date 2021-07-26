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

using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll a, b;

    ll node, edges;

    vector < ll > graph[110];

    for(i = 1; i <= testcase; i++)
    {
        slld(node);
        slld(edges);

        for(j = 1; j <= node; j++)
        {
            graph[j].clear();
        }

        for(j = 1; j <= edges; j++)
        {
            slld(a);
            slld(b);

            graph[a].pb(b);
            graph[b].pb(a);
        }

        slld(k);
        tag = 0;

        for(j = 1; j <= k; j++)
        {
            slld(input);

            if(graph[input].size())
            {
                sort(graph[input].begin(), graph[input].end());
            }
            else
            {
                tag = 1;
            }

            {
                l = graph[input].size();

                for(m = 0; m < l; m++)
                {
                    cout << graph[input][m];
                    if(m != l - 1)
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }

    }


}


