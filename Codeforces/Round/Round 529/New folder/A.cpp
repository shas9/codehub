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


char t[20];

ll dp[20][2][200];
ll s;

ll solve(ll pos, ll issmall, ll sum, ll nn)
{
    if(pos == 20)
    {
//        cout << nn << endl;
        if(abs(nn - sum) >= s)
        {
            return 1;
        }
        return 0;
    }

    ll &ret = dp[pos][issmall][sum];

    if(ret != -1) return ret;

    ll hi = 9; if(issmall == 0) hi = t[pos] - '0';
    ll lo = 0;

    ret = 0;
    for(ll i = lo; i <= hi; i++)
    {
        ll nnn = nn * 10 + i;
        if(i < hi)
        {
            ret += solve(pos + 1, 1, sum + i, nnn);
        }
        else
        {
            ret += solve(pos + 1, issmall, sum + i, nnn);
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

    {
        for(i = 0; i < 20; i++) t[i] = '0';
        cin >> t >> s;

        memset(dp, -1, sizeof dp);

        ll ln = strlen(t);
        t[ln] = '0';

        for(i = 19; i >= 0; i--)
        {
            t[i] = t[ln - 1];
            t[ln - 1] = '0';
            ln--;

            if(ln == 0) break;
        }


        ans = solve(0,0,0,0);

        cout << ans << endl;
    }

}


