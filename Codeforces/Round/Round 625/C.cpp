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
string str;

ll dp[105][30];
ll n;

ll solve(ll pos, ll lch)
{
    if(pos == n)
    {
        return 0;
    }

    ll &ret = dp[pos][lch];

    if(ret != -1) return ret;

    ll ch = (str[pos] - 'a') + 1;

    ret = solve(pos + 1, ch);

    if(ch == 1)
    {
        return ret;
    }

    if(abs(ch - lch) == 1)
    {
        ret = max(ret, solve(pos + 1, lch) + 1);
    }

    if(pos < (n - 1))
    {
        ll nch = str[pos + 1] - 'a';

        if(abs(nch - ch) == 1)
        {
            ret = max(ret, solve(pos + 1, lch) + 1);
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        cin >> str;

        memset(dp,-1,sizeof dp);

        ans = solve(0,0);

        cout << ans << endl;
    }


}



