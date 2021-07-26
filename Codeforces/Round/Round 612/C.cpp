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
ll dp[105][105][105];
ll n;
ll ress[105];

ll solve(ll pos, ll xx, ll yy)
{
    if(pos > n)
    {
        return 0;
    }

    ll &ret = dp[pos][xx][yy];

    if(ret != -1) return ret;

    ret = 0;

    if(arr[pos] != 0)
    {
        ress[pos] = arr[pos];

        if(pos > 1)
        {
            if((ress[pos] + ress[pos - 1]) % 2) return ret = solve(pos + 1, xx, yy) + 1;
            else return ret = solve(pos + 1, xx, yy);
        }
        return ret = solve(pos + 1, xx, yy);
    }

    ll p1 = 0;
    ll p2 = 0;

    if(xx)
    {
        ress[pos] = 1;

        p1 = solve(pos + 1, xx - 1, yy);

        if(pos > 1)
        {
            if((ress[pos] + ress[pos - 1]) % 2)
                p1++;
        }
    }

    if(yy)
    {
        ress[pos] = 2;

        p2 = solve(pos + 1, xx, yy - 1);

        if(pos > 1)
        {
            if((ress[pos] + ress[pos - 1]) % 2)
            p1++;
        }
    }

    ret = min(p1,p2);

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
        memset(dp,-1,sizeof dp);

        ll xx, yy;
        xx = yy = 0;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            if(arr[i] == 0) continue;

            if(arr[i] % 2) xx++;
            else yy++;
        }

        xx = ((n + 1) / 2) - xx;
        yy = (n / 2) - yy;

        ans = solve(1,xx,yy);

        cout << ans << endl;
    }


}


