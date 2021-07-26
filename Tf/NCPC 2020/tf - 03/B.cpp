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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

char grid[4][1005];
char ans[4][1005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    slld(testcase);

    ll up = 0;
    ll down = 0;
    ll both = 0;

    for(i = 1; i <= 2; i++)
    {
        scanf("%s", grid[i] + 1);
    }

//    for(i = 1; i <= 2; i++)
//    {
//        for(j = 1; j <= 7; j++)
//            cout << grid[i][j];
//
//        cout << endl;
//    }

    n = strlen(grid[1] + 1);

    for(i = 1; i <= n; i++)
    {
        if(grid[1][i] == '#' && grid[2][i] == '#') both++;
        else if(grid[1][i] == '#') up++;
        else if(grid[2][i] == '#') down++;
    }

    if(both == 0 && (up == 0 || down == 0))
    {
        cout << "YES" << endl;
        if(up == 0)
        {
            for(i = 1; i <= n; i++) cout << '.';
            cout << endl;

            for(i = 1; i <= n; i++)
            {
                if(down)
                {
                    cout << '#';
                    down--;
                }
                else
                {
                    cout << '.';
                }
            }

            cout << endl;
        }
        else
        {


            for(i = 1; i <= n; i++)
            {
                if(up)
                {
                    cout << '#';
                    up--;
                }
                else
                {
                    cout << '.';
                }
            }

            cout << endl;

            for(i = 1; i <= n; i++) cout << '.';
            cout << endl;
        }

        return 0;
    }

    if(both == 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    i = 1;
    while(up--)
    {
        ans[1][i] = '#';
        i++;
    }

    while(both--)
    {
        ans[1][i] = '#';
        ans[2][i] = '#';
        i++;
    }

    while(down--)
    {
        ans[2][i] = '#';
        i++;
    }

    for(i = 1; i <= 2; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(ans[i][j] == '#') cout << ans[i][j];
            else cout << '.';
        }

        cout << endl;
    }

}


