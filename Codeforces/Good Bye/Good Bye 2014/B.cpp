#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LL long long
#define sl(n) scanf("%lld", &n)


char grid[5][120];

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, ts, i, j, k, x, y, z, q, m, n;

    while(sl(n) != EOF)
    {
        sl(k);

        for (i = 1; i <= 4; i++)
        {
            for (j = 1; j <= n; j++)
                grid[i][j] = '.';
        }

        if (k&1)
        {
            if (k < n-2)
            {
                ll l = n/2 + 1;
                ll r = l;

                grid[2][l] = '#';
                k--;

                l--;
                r++;

                while(k)
                {
                    grid[2][l] = grid[2][r] = '#';
                    l--;
                    r++;
                    k -= 2;
                }
            }
            else
            {
                for (i = 2; i < n; i++)
                    grid[2][i] = '#';

                k -= n-2;

                ll l = 2, r = n-1;

                while (l < r && k)
                {
                    grid[3][l] = grid[3][r] = '#';
                    l++;
                    r--;
                    k -= 2;
                }
            }
        }
        else
        {
            for (i = 2; i < n && k; i++)
            {
                for (j = 2; j <= 3 && k; j++)
                {
                    grid[j][i] = '#';
                    k--;
                }
            }
        }

        printf("YES\n");

        for (i = 1; i <= 4; i++)
        {
            for (j = 1; j <= n; j++)
                printf("%c", grid[i][j]);
            printf("\n");
        }
    }

    return 0;
}
