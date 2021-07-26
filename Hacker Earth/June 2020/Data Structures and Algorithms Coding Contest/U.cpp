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


char f[16], t[16];

ll dp[15][2][2];

ll solve(ll pos, ll isbig, ll issmall)
{
    ll &ret = dp[pos][isbig][issmall];

    if(pos == 15) return 0;

    if(ret != -1) return ret;

    ll hi = 9; if(issmall == 0) hi = t[pos] - '0';
    ll lo = 0; if(isbig == 0) lo = f[pos] - '0';

    ret = 0;
    for(ll i = lo; i <= hi; i++)
    {
        if(i < hi)
        {
            if(i > lo) ret += solve(pos + 1, 1, 1) + (i == 0);
            else ret += solve(pos + 1, isbig, 1) + (i == 0);
        }
        else
        {
            if(i > lo) ret += solve(pos + 1, 1, issmall) + (i == 0);
            else ret += solve(pos + 1, isbig, issmall) + (i == 0);
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        for(i = 0; i < 15; i++) f[i] = t[i] = '0';

        cin >> f >> t;

        memset(dp, -1, sizeof dp);

        ll ln = strlen(f);

        f[ln] = '0';
        for(i = 14; i >= 0; i--)
        {
            f[i] = f[ln - 1];
            f[ln - 1] = '0';
            ln--;

            if(ln == 0) break;
        }

        ln = strlen(t);
        t[ln] = '0';

        for(i = 14; i >= 0; i--)
        {
            t[i] = t[ln - 1];
            t[ln - 1] = '0';
            ln--;

            if(ln == 0) break;
        }

        f[15] = t[15] = '\0';

//        cout << endl << f << " && " << t << endl;

        ans = solve(0,0,0);

        cout << ans << endl;
    }


}

