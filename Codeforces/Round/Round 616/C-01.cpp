#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e9
#define mnd -2e9

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

ll arr[3510];
ll dp[3510][3510];
ll n, m, k;

ll solve(ll i, ll j)
{
//    cout << i << " " << j << endl;
    ll &ret = dp[i][j];

    if(ret != -1) return ret;
    if(i == j) return ret = arr[i];

    ll pos = n - (j - i);

    if(pos == m)
    {
        return ret = max(arr[i],arr[j]);
    }

    ret = 0;

    if(pos > k) return ret = min(solve(i + 1, j), solve(i,j - 1));
    else return ret = max(solve(i + 1, j), solve(i,j-1));

}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        slld(k);

        k = min(k,m-1);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        for(i = 0; i <= n + 1; i++)
            for(j = 0; j <= n + 1; j++)
                dp[i][j] = -1;

        if(m == 1)
        {
            ans = max(arr[1],arr[n]);
        }
        else ans = solve(1,n);

        cout << ans << endl;
    }


}

