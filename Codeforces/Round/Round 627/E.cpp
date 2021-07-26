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

ll dp[2003][2003];
ll h, n, l, r;
ll hours[2003];

ll solve(ll pos, ll hh)
{
    ll &ret = dp[pos][hh];

    if(ret != -1) return ret;

    if(pos > 1 && l <= hh && hh <= r)
    {
        ret = 1;
//        cout << pos << " " << hh << endl;
    }
    else ret = 0;

    if(pos > n) return ret;

    ret += max(solve(pos + 1, (hh + hours[pos]) % h), solve(pos + 1, (hh + hours[pos] - 1) % h));

    return ret;
}

int main()
{
    ll i, j, k, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(h);
    slld(l);
    slld(r);

    for(i = 1; i <= n; i++)
        slld(hours[i]);

    memset(dp,-1,sizeof dp);

    ans = solve(1,0);

    cout << ans << endl;
}


