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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    bool vis[1005];

    memset(vis,false,sizeof(vis));

    vector < ll > graph[1005];

    for(i = 0; i <= 1001; i++)
    {
        graph[i].clear();
    }

    for(ll cs = 2; cs <= testcase; cs++)
    {
        slld(n);

        graph[n].pb(cs);
    }

    tag = 1;

    for(i = 1; i <= testcase; i++)
    {
        ans = 0;

        for(j = 0; j < graph[i].size(); j++)
        {
            ll temp = graph[i][j];
            if(graph[temp].size() == 0)
            {
                ans++;
            }

            if(ans == 3)
            {
                break;
            }
        }

        if(ans > 0 && ans < 3)
        {
            tag = 0;

            cout << "No" << endl;

            break;
        }
    }

    if(tag == 1)
    {
        cout << "Yes" << endl;
    }


}


