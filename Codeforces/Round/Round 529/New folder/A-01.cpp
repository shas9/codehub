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


char f[20], t[20];
ll ss;

ll dp[20][2][2][200][200];
void conv(ll x)
{

        for(ll i = 19; i >= 0; i--)
        {
            f[i] = '0';
        }

        ll ln = 19;
        while(x > 0)
        {
            ll temp = x % 10;
            x /= 10;
            f[ln--] = temp + '0';
        }
}
ll solve(ll pos, ll isbig, ll issmall, ll sum, ll fix)
{
    if(pos == 20)
    {
//        cout << sum << " " << fix << endl;
        if(sum == fix) return 1;
        return 0;
    }


    ll &ret = dp[pos][isbig][issmall][sum][fix];
    if(ret != -1) return ret;

    ll hi = 9; if(issmall == 0) hi = t[pos] - '0';
    ll lo = 0; if(isbig == 0) lo = f[pos] - '0';

    ret = 0;
    for(ll i = lo; i <= hi; i++)
    {
        if(i < hi)
        {
            if(i > lo) ret += solve(pos + 1, 1, 1, sum + i, fix);
            else ret += solve(pos + 1, isbig, 1, sum + i, fix);
        }
        else
        {
            if(i > lo) ret += solve(pos + 1, 1, issmall, sum + i,fix);
            else ret += solve(pos + 1, isbig, issmall, sum + i,fix);
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

//    slld(testcase);

//    for(ll cs = 1; cs <= testcase; cs++)
    {
        for(i = 0; i < 20; i++) f[i] = t[i] = '0';
        cin >> t >> ss;

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

//        cout << t << endl;

        ans = 0;

        for(i = 1; i <= 180; i++)
        {
            conv(ss + i);

            ans += solve(0,0,0,0,i);
        }

        cout << ans << endl;
    }


}




