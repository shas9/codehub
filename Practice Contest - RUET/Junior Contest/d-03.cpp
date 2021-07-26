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

ll arr[1000006];
bool dp[1003][1003];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(n);
    slld(m);

    for(ll cs = 1; cs <= n; cs++)
    {
        slld(arr[cs]);

        arr[cs] %= m;
    }

    if(n >= m)
    {
        cout << "YES" << endl;
        return 0;
    }

    memset(dp,false,sizeof(dp));

    for(i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            if(dp[i-1][j]|| dp[i-1][(j+arr[i]) % m])
            {
                dp[i][j] = true;
            }
        }
    }

    if(dp[n][m] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


}

