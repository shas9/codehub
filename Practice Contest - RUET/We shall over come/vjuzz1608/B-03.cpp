#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")




using namespace std;

ll combination[100][8];
ll solution = 0;
ll check[8];

bool row[8] = {0};
bool leftd[15] = {0};
bool rightd[15] = {0};

void solve(ll col)
{
    ll i, j, k, l, m, n;
    ll r, ld, rd;

    if(col == 8)
    {
        for(i = 0; i < 8; i++)
        {
            combination[solution][i] = check[i] + 1;
        }

        solution++;
        return;
    }

    for(r = 0; r < 8; r++)
    {
        ld = col - r + 7;
        rd = col + r;

        if(row[r] == false && leftd[ld] == false && rightd[rd] == false)
        {
            row[r] = 1;
            leftd[ld] = 1;
            rightd[rd] = 1;

            check[col] = r;

            solve(col + 1);

            row[r] = 0;
            leftd[ld] = 0;
            rightd[rd] = 0;

        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll input;
    ll moved, min_move;

    vector < ll > queens;

    ll tcase = 0;

    solve(0);

    while(scanlld(input) != EOF)
    {
        tcase++;
        queens.clear();
        queens.pb(input);

        for(i = 1; i < 8; i++)
        {
            scanlld(input);
            queens.pb(input);
        }

        min_move = 100000;
        for(i = 0; i < solution; i++)
        {
            moved = 0;
            for(j = 0; j < 8; j++)
            {
                if(queens[j] != combination[i][j])
                {
                    moved++;
                }
            }

            if(moved < min_move)
            {
                min_move = moved;
            }
        }

        printf("Case %lld: %lld\n", tcase, min_move);
    }


}

