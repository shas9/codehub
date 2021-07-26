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

ll mat[200][200];
bool check[200];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            slld(mat[i][j]);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            if(mat[i][j] == 1) check[i] = 1;
            if(mat[i][j] == 2) check[j] = 1;
            if(mat[i][j] == 3)
            {
                check[i] = check[j] = 1;
            }
        }

    ans = 0;

    for(i = 1; i <= n; i++) if(!check[i]) ans++;

    cout << ans << endl;

    for(i = 1; i <= n; i++)
        if(!check[i]) cout << i << " ";

}


