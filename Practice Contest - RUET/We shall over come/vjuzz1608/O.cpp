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

ll val[20][20];
ll sizearr, sum, maxsum;
ll check;
ll temp[20];;

ll dp[16][1<<16];

ll solve (ll pos, ll mask)
{
	if (pos >= sizearr)
    {
        return 0;
    }
	if (dp[pos][mask] == -1U)
    {
		for (ll i = 0; i < sizearr; i++)
		{
			if (!(mask & (1<<i)))
			{
				dp[pos][mask] = max(dp[pos][mask], val[pos][i] + solve(pos+1, mask | (1<<i)));
			}
		}
	}

	return dp[pos][mask];
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    scanlld(testcase);

    for(l = 1; l <= testcase; l++)
    {
        scanlld(sizearr);

        for(i = 1; i <= sizearr; i++)
        {
            for(j = 1; j <= sizearr; j++)
            {
                scanlld(m);

                val[i][j] = m;
            }
        }

        maxsum = -999;

        for(i = 0; i < 20; i++)
        {
            temp[i] = 0;
        }

        check = 0;
        maxsum = solve(0,0);

        printf("Case %lld: %lld\n", l, maxsum);

    }


}


