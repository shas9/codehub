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

char grid[10][10];
ll ans[10][10];

bool vis[10][10];
bool on;

void trav(ll r, ll c, ll mov, ll k)
{
    if(r < 1 || r > 8) return;
    if(c < 1 || c > 8) return;

    if(vis[r][c]) return;

    vis[r][c] = 1;

    if(k == 2)
    {
        if(ans[r][c] && grid[r][c] != '#')
        {
            if(((ans[r][c] % 2) + (mov % 2)) % 2 == 0)
            {
                on = 1;
            }
        }
    }
    else
    {
        ans[r][c] = mov;
    }

    ll a[4] = {2,2,-2,-2};
    ll b[4] = {2,-2,2,-2};

    for(ll i = 0; i < 4; i++)
    {
        trav(r + a[i], c + b[i], mov + 1, k);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        for(i = 1; i <= 8; i++)
        {
            scanf("%s", grid[i] + 1);
        }

        memset(ans,0,sizeof ans);

        ll xx = 0;
        on = 0;

        for(i = 1; i <= 8; i++)
        {
            for(j = 1; j <= 8; j++)
            {
                if(grid[i][j] == 'K')
                {
                    memset(vis,0,sizeof vis);
                    trav(i,j, 0,++xx);
                }
            }
        }

//        bool ok = 0;
//        on =
//        for(i = 1; i <= 8; i++)
//        {
//            for(j = 1; j <= 8; j++)
//            {
//                if(ans[i][j] == 2)
//                {
//                    ok = 1;
////                    cout << i << " " << j << endl;
//                }
//            }
//        }

        if(on) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}


