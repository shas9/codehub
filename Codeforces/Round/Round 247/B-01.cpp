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

ll hp[10][10];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 5; j++)
        {
            slld(hp[i][j]);
        }
    }

    ll mx = -1;
    for(ll a = 1; a <= 5; a++)
    {
        for(ll b = 1; b <= 5; b++)
        {
            if(b == a) continue;
            ll temp1 = hp[a][b] + hp[b][a];
            for(ll c = 1; c <= 5; c++)
            {
                if(c == a || c == b)continue;
                ll temp2 = hp[a][c] + hp[c][a];
                for(ll d = 1; d <= 5; d++)
                {
                    if(d == a || d == b || d == c) continue;
                    ll temp3 = hp[c][d] + hp[d][c];
                    for(ll e = 1; e <= 5; e++)
                    {
                        if(e == a || e == b || e == c || e == d) continue;
                        ll temp4 = hp[d][e] + hp[e][d];

                        ll temp = (temp1 + temp2 + temp1 + temp2 + temp3 + temp4);

                        if(mx < temp) mx = temp;
                    }
                }
            }
        }
    }


    cout << mx << endl;




}



