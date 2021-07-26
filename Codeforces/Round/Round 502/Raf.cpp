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

#define maxn 300005
using namespace std;

ll arr[2][maxn];
bool vis[2][maxn];
ll dp[2][maxn];
ll n;
ll path[100];
ll disx[] = {1,-1,0,0};
ll disy[] = {0,0,-1,1};

bool check(ll r, ll c)
{
    if(r > 2 || r <= 0) return 1;
    if(c > n || c <= 0) return 1;
    if(vis[r][c]) return 1;

    return 0;
}

ll solve(ll r, ll c, ll time)
{
    if(check(r,c)) return 0;

    vis[r][c] = 1;


    ll way = 0;

    for(ll i = 0; i < 4; i++)
    {
        if(check(r + disx[i], c + disy[i])) continue;

        way = max(way,solve(r + disx[i], c + disy[i], time + 1));
    }
    vis[r][c] = 0;

    return way + arr[r][c] * time;

}
int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

     freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        for(i = 1; i <= 2; i++)
        {
            for(j = 1; j <= n; j++)
            {
                slld(arr[i][j]);
                vis[i][j] = 0;
            }
        }

        ans = solve(1,1,0);

        cout << ans << endl;
    }

}

