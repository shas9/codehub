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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o, t;
    ll testcase;
    ll input, flag, tag, ans;
    ll temp;

    ll c, d, p, nl, np;
    ll r;

    string in;

//    freopen("in.txt", "r", stdin);

    ll arr[20][20];
    char ch;


    while(cin >> r >> c)
    {
        ans = 0;
        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                scanf(" %c", &ch);

                if(ch == 'S')
                {
                    arr[i][j] = -1;
                }
                else
                {
                    arr[i][j] = 1;
                }
            }
        }

        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                if(arr[i][j] == -1)
                {
                    break;
                }
            }

            if(j > c)
            {
                for(j = 1; j <= c; j++)
                {
                    ans += arr[i][j];

                    arr[i][j] = 0;
                }
            }
        }

        for(i = 1; i <= c; i++)
        {
            for(j = 1; j <= r; j++)
            {
                if(arr[j][i] == -1)
                {
                    break;
                }
            }

            if(j > r)
            {
                for(j = 1; j <= r; j++)
                {
                    ans += arr[j][i];

                    arr[j][i] = 0;
                }
            }
        }

        cout << ans << endl;
    }


}








