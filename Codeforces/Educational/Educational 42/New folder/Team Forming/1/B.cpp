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

ll room[55][55];

ll ci[3000];

void solve(ll n, ll m, ll c)
{
    ll pos = 1;
    for(ll i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            for(ll j = 1; j <= m; j++)
            {
                //cout << ci[pos] << " " << pos << endl;
                if(ci[pos])
                {
                    ci[pos]--;
                    room[i][j] = pos;
                }
                else
                {
                    pos++;
                    ci[pos]--;
                    room[i][j] = pos;
                }
            }

        }
        else
        {
            for(ll j = m; j >= 1; j--)
            {
                //cout << ci[pos] << " " << pos << endl;
                    if(ci[pos])
                    {
                        ci[pos]--;
                        room[i][j] = pos;
                    }
                    else
                    {
                        pos++;
                        ci[pos]--;
                        room[i][j] = pos;
                    }
            }
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, c;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        slld(c);

        for(i = 1; i <= c; i++)
        {
            slld(ci[i]);
        }

        solve(n,m,c);

        //bug;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                cout << room[i][j];
                if(j < m) cout << " ";
            }

            cout << endl;
        }
    }


}

