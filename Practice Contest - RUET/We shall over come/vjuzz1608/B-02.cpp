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
ll col_final = 0;

bool chessboard[8][8];

bool check(ll row, ll col);

void solve(ll col)
{
    //cout << col << endl;
    ll i, j, k, l, m, n , o, p;
    if(col < 0 || col_final == 92)
    {
        return;
    }

    if(col == 8)
    {
            for(j = 0; j < 8; j++)
            {
                for(k = 0; k < 8; k++)
                {
                    if(chessboard[k][j] == true)
                    {
                        break;
                    }
                }
                combination[col_final].pb(k);
            }
            col_final++;

        for(i = 0; i < 8; i++)
        {
            if(chessboard[i][7] == true)
            {
                break;
            }
        }

        chessboard[i][7] = false;
        if(i == 7)
        {
            chessboard[i][7] = false;
            solve(6);
            return;
        }
        else
        {
            for(j = i + 1; j < 8; j++)
            {
                if(check(j,7) == true)
                {
                    chessboard[j][7] = true;
                    break;
                }
            }

            if(j == 8)
            {
                solve(6);
                return;
            }
            else
            {
                solve(8);
                return;
            }
        }
    }
    for(i = 0; i < 8; i++)
    {
        if(chessboard[i][col] == true)
        {
            break;
        }
    }

    if(i == 8)
    {
        for(i = 0; i < 8; i++)
        {
            if(check(i,col) == true)
            {
                chessboard[i][col] = true;
                break;
            }
        }

        if(i == 8)
        {
            solve(col - 1);
            return;
        }
        else
        {
            solve(col + 1);
            return ;
        }
    }
    else
    {
        chessboard[i][col] == false;

        for(j = i + 1; j < 8; j++)
        {
            if(check(j,col) == true)
            {
                chessboard[j][col] = true;
                break;
            }
        }
        if(j == 8)
        {
            solve(col - 1);
            return;
        }
        else
        {
            solve(col + 1);
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

    vector < ll > queens;
    chessboard[0][0] = true;

        for(j = 0; j < 8; j++)
        {
            for(k = 0; k < 8; k++)
            {
                chessboard[j][k] = false;
            }
        }

    solve(0);



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

        for(i = 0; i < col_final; i++)
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



