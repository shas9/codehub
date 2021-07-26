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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    vector < ll > score;
    bool visited[10];

    memset(visited,false,sizeof(visited));
    score.clear();

    ll maxscore = 0;

    for(i = 1; i <= 6; i++)
    {
        scanlld(input);

        score.push_back(input);

        maxscore += input;
    }

    ll team1, team2;
    flag = 0;

    for(i = 0; i < 6; i++)
    {
        for(j = i + 1; j < 6; j++)
        {
            team1 = 0;
            for(k = j + 1; k < 6; k++)
            {
                team1 = score[i] + score[j] + score[k];

                team2 = maxscore - team1;

                if(team1 == team2)
                {
                    flag = 1;
                }
            }
        }
    }



    if(flag)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;


}


