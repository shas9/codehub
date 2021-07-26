#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf(" %c", &letter)
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

char mp[150][150];
ll track[150][150];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(k);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            sc(mp[i][j]);
        }
    }

    memset(track,0,sizeof(track));

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            //if(mp[i][j] == '#') continue;

            ll cnt = 0;
            for(m = j; m <= n; m++)
            {
                if(mp[i][m] == '#')
                {
                    break;
                }
                cnt++;

                if(cnt == k) break;
            }

            if(cnt == k)
            {
                for(m = j, o = 1; o <= k; m++, o++)
                {
                    track[i][m] += 1;
                }
            }
        }
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            ll cnt = 0;
            for(m = j; m <= n; m++)
            {
                if(mp[m][i] == '#')
                {
                    break;
                }
                cnt++;

                if(cnt == k) break;
            }

            if(cnt == k)
            {
                for(m = j, o = 1; o <= k; m++, o++)
                {
                    track[m][i] += 1;
                }
            }
        }
    }

    ll x = 1, y = 1;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(track[x][y] < track[i][j])
            {
                x = i;
                y = j;
            }
        }
    }

    cout << x << " " << y << endl;
}


