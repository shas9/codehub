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

ll dp[100000];

ll solve(ll n, ll m)
{
    queue < ll > q;

    q.push(n);

    dp[n] = 0;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        if(dp[top - 1] == -1)
        {
            dp[top - 1] = dp[top] + 1;
            q.push(top - 1);
        }

        if(dp[top * 2] == -1 && m >= top)
        {
            dp[top * 2] = dp[top] + 1;
            q.push(top * 2);
        }
    }

    return dp[m];
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
//        if(n >= m)
//        {
//            cout << (n - m) << endl;
//            continue;
//        }

        memset(dp,-1,sizeof dp);

        ans = solve(n,m);

        cout << ans << endl;
    }

}


