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

ll arr[105];
ll n;

ll dp[105][55][55][2];
ll res[105];

ll solve(ll pos, ll xx, ll yy, ll prev)
{
    if(pos > n)
    {
//        ll cnt = 0;
//        for(ll i = 1; i <= n; i++)
//        {
//            cout << res[i] << " ";
//
//            if(i > 1)
//            {
//                cnt += (res[i] + res[i - 1]) % 2;
//            }
//        }
//
//        cout << endl << cnt << endl;

        return 0;
    }

    ll &ret = dp[pos][xx][yy][prev];

    if(ret != -1) return ret;

    ret = 0;

    ll p1, p2, p3;

    p1 = p2 = p3 = mxlld;

    if(arr[pos])
    {
        p1 = solve(pos + 1, xx, yy, arr[pos] % 2);

        if(pos > 1)
        {
            p1 += (prev + arr[pos]) % 2;
        }

        return ret = p1;
    }

    if(xx)
    {
        p2 = solve(pos + 1, xx - 1, yy, 1);

        if(pos > 1)
        {
            p2 += (prev + 1) % 2;
        }
    }

    if(yy)
    {
        p3 = solve(pos + 1, xx , yy - 1, 0);

        if(pos > 1)
        {
            p3 += prev % 2;
        }
    }

    return ret = min(p2,p3);


}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    ll xx = 0;
    ll yy = 0;

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        if(arr[i])
        {
            if(arr[i] % 2) xx++;
            else yy++;
        }
    }

    memset(dp,-1,sizeof dp);

    xx = ((n + 1) / 2) - xx;
    yy = (n / 2) - yy;

    ans = solve(1,xx,yy,0);

    cout << ans << endl;


}



