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

char f[14], t[14];

ll dp[13][2][2][11];

ll solve(ll pos, ll isbig, ll issmall, ll prv)
{
//    cout << pos << " " << prv << endl;
    ll &ret = dp[pos][isbig][issmall][prv];

    if(pos == 13) return 1;

    if(ret != -1) return ret;

    ll hi = 9;
    if(issmall == 0) hi = t[pos] - '0';
    ll lo = 0;
    if(isbig == 0) lo = f[pos] - '0';

    ret = 0;

    for(ll i = lo; i <= hi; i++)
    {
        if(prv != 10)
            if(abs(prv - i) > 1) continue;

//        if(prv == 10) cout << i << " " << pos << endl;

        ll sup = i;

        if(prv == 10 && hi == lo && lo == 0) sup = 10;

        if(i < hi)
        {
            if(i > lo) ret += solve(pos + 1, 1, 1, sup);
            else ret += solve(pos + 1, isbig, 1,  sup);
        }
        else
        {
            if(i > lo) ret += solve(pos + 1, 1, issmall, sup);
            else ret += solve(pos + 1, isbig, issmall, sup);
        }
    }

    return ret;
}

ll calc(ll y)
{
    ll i;
    for(i = 0; i < 13; i++) f[i] = t[i] = '0';

    memset(dp, -1, sizeof dp);

    f[12] = '1';
    f[13]= '\0';

//    cout << y << " ";
    i = 12;
    while(y)
    {
        t[i] = (y % 10) + '0';
        i--;
        y /= 10;
    }

    t[13] ='\0';

//    cout << f << " " << t << endl;

    return solve(0,0,0,10);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    while(cin >> k)
    {
        ans = 1;

        ll lo = 1;
        ll hi = 3234566667;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

//            cout << mid << " " << calc(mid) << endl;
            if(calc(mid) < k)
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }

        cout << ans << endl;
    }


}




