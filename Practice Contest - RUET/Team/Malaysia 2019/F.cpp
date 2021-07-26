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

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[2005][1003];
ll n, e, k;
ll mat[2005][2005];

ll solve(ll pos, ll mask)
{
//    cout << mask << " --- " << pos << endl;
    if(pos > n)
    {
//        cout << mask << endl;
        return 1;
    }

    ll nmask = 0;
    for(ll i = 1; i <= 8; i++)
    {
        if(check(mask,i))
        {
            nmask = Set(nmask,i - 1);
        }
    }

    mask = nmask;

//    cout << mask << " (()) " << pos << endl;

    ll &ret = dp[pos][mask];

    if(ret != -1) return ret;

    ret = 0;

    ll l = pos - e;
    ll r = pos + e;

//    cout << l << " " << r << endl;

    for(ll i = l, j = 0; i <= r; j++, i++)
    {
        if(i <= 0) continue;

        if(i > n) break;

        if(check(mask,j)) continue;

//        cout << " ** " << i << endl;

        if(mat[pos][i]) continue;

//        cout << pos << " " << i << endl;
        ret = (ret + solve(pos + 1, Set(mask,j))) % mod;
    }

    return ret;
}


int main()
{
    ll i, j, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> e >> k)
    {
        memset(mat,0,sizeof mat);

        for(i = 1; i <= k; i++)
        {
            ll u, v;

            cin >> u >> v;

            mat[u][v]++;
        }

        memset(dp,-1,sizeof dp);

        ans = solve(1,0);

        cout << ans << endl;

    }


}


