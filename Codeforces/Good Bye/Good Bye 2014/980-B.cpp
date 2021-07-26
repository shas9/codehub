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

char grid[500][500];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n >> k;

    for(i = 1; i <= 4; i++)
        for(j = 1; j <= n; j++)
            grid[i][j] = '.';

    if(k % 2 == 0)
    {
        for(i = 2; i <= n; i++)
        {
            if(k == 0) break;

            for(j = 2; j <= 3 && k; j++)
            {
                grid[j][i] = '#';
                k--;
            }
        }
    }
    else
    {
        if(k < (n - 2))
        {
            ll lft = (n / 2) + 1;
            ll rgt = lft;

            grid[2][lft] = '#';
            k--;

            while(k)
            {
                lft--;
                rgt++;

                grid[2][lft] = grid[2][rgt] = '#';

                k -= 2;
            }
        }
        else
        {
            ll lft = 2;
            ll rgt = n - 1;

            for(i = 2; i <= n - 1; i++)
            {
                grid[2][i] = '#';
            }

            k -= (n - 2);

            while(k)
            {
                grid[3][lft] = grid[3][rgt] = '#';

                k -= 2;

                lft++;
                rgt--;
            }
        }
    }

    cout << "YES" << endl;

    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << grid[i][j];
        }

        cout << endl;
    }

}


