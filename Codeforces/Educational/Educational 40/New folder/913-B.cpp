
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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

vector < ll > graph[1005];

ll dfs(ll ind)
{
    ll sz = graph[ind].size();

    //cout << sz << endl;
    ll ans = 0;
    for(ll i = 0; i < sz; i++)
    {
        ll y = graph[ind][i];

        if(graph[y].size() == 0)
        {
            ans++;
        }
        else
        {
            bool c = dfs(y);

            if(c == 0)
            {
                return 0;
            }
        }
    }

    if(ans >= 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    //testcase--;

    for(ll cs = 2; cs <= testcase; cs++)
    {
        slld(n);

        graph[n].push_back(cs);
    }

    ans = dfs(1);

    if(ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


}

