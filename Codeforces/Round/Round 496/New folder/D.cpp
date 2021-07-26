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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll grid[55][55];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            slld(grid[i][j]);


    bool on = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            flag = grid[i][j];

            if(flag == 1) continue;
            on = 0;
            for(k = 1; k <= n; k++)
            {
                for(l = 1; l <= n; l++)
                {
                    if(i == l && j == k) continue;

                    if(flag == grid[i][k] + grid[l][j])
                    {
                        //cout << flag << endl;
                        on = 1;
                    }

                    if(on)
                    {
                        break;
                    }
                }

                if(on) break;
            }

            if(on == 0)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;


}

