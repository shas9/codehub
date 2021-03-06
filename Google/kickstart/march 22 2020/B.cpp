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

ll dp[55][35][1505];
ll arr[55][35];
ll n, m, k;

ll solve(ll st, ll pos, ll pl)
{
    if(pl == 0) return 0;
    if(pos > m) return solve(st + 1, 1, pl);
    if(st > n && pl != 0) return mnlld;

    ll &ret = dp[st][pos][pl];

    if(ret != -1) return ret;

    ret = 0;

    ret = max(solve(st + 1, 1, pl), solve(st, pos + 1, pl - 1) + arr[st][pos]);

    return ret;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(dp,-1,sizeof dp);

        slld(n);
        slld(m);
        slld(k);

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                slld(arr[i][j]);

//                if(j > 1) arr[i][j] += arr[i][j - 1];

//                cout << arr[i][j] << " ";
            }

//            cout << endl;
        }

        ans = solve(1,1,k);

        printf("Case #%lld: %lld\n", cs, ans);
    }


}



