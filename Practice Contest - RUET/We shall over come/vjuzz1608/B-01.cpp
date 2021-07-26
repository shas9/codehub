#include <bits/stdc++.h>`

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

vector < ll > combination[92];
ll col_final = 0;;

bool chessboard[8][8];

bool check(ll row, ll col);

void solve(ll col)
{
    ll i, j, k, l, m, n, o;
    ll row;
    if(col < 0)
    {
        return;
    }

    if(col == 8)
    {
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                for(k = 0; k < 8; k++)
                {
                    if(chessboard[k][j] == true)
                    {
                        combination[col_final][i] = k;
                        break;
                    }
                }
            }
        }
        col_final++;

        for(i = 0; i < 8; i++)
        {
            if(chessboard[i][0] == true)
            {
                chessboard[i][0] == false;
                if(i < 7)
                {
                    chessboard[i + 1][0] == true;
                    solve(1);
                }
                else
                {
                    return;
                }
            }
        }
    }

    for(row = 1; row < 8; row++)
    {
        if(check(row, col) == true)
        {
            chessboard[row][col] = true;
        }
        else
        {
            i = col - 1;

            for(j = 0; j < 8; j++)
            {
                chessboard[j][i] = false;
            }

            solve(i);
        }
    }

    if(col == 0)
    {
        if(row == 8)
        {
            return;
        }
    }
}

bool check(ll row, ll col)
{
    ll i, j, k, l, m , n, o;

    for(i = row - 1, j = col - 1; i > 0 && j > 0; i--, j--)
    {
        if(chessboard[i][j] == true)
        {
            return false;
        }

    }

    for(i = col - 1; i > 0; i--)
    {
        if(chessboard[row][i] == true)
        {
            return false;
        }
    }

    for(i = row + 1, j = col - 1; i < 8 && j > 0; i++, j--)
    {
        if(chessboard[i][j] == true)
        {
            return false;
        }

    }


    return true;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll count_move;
    ll min_move;
    ll input;

    for(i = 0; i < 92; i++)
    {
        for(j = 0; j < 8; j++)
        {
            cout << combination[i][j] << " ";
        }
        cout << endl;
    }

    vector < ll > queens;
    chessboard[0][0] = true;
    solve(1);



    testcase = 0;

    while(scanlld(input) != EOF)
    {
        testcase++;
        count_move = 0;
        min_move = 20;

        queens.clear();

        queens.pb(input);

        for(i = 1; i <= 7; i++)
        {
            scanlld(input);
            queens.pb(input);
        }

        for(i = 0; i < 92; i++)
        {
            count_move = 0;
            for(j = 0; j < 8; j++)
            {
                if(queens[j] != combination[i][j])
                {
                    count_move++;
                }
            }
            if(min_move > count_move)
            {
                min_move = count_move;
            }
        }

        printf("Case %lld: %lld\n", testcase, min_move);
    }


}


