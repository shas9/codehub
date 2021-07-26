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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}
ll dp[10005][105];
ll m, n;

bool solve(ll num, ll turn)
{
//    if(n == 1234)
//    cout << num << " " << turn << endl;

    if(turn > m)
    {
        if(num > n) return 1;
        return 0;
    }

    if(dp[num][turn] != -1) return dp[num][turn];

    ll num1, num2, num3, num4;
    bool a, b, c, d;

    ll arr[4];
    ll i;

    for(i = 0; i < 4; i++) arr[i] = 0;

    i = 3;
    num1 = num;
    while(num1 > 0 && i >= 0)
    {
        ll flag = num1 % 10;
        num1 /= 10;

        arr[i--] = flag;
    }

    num1 = num2 = num3 = num4 = 0;

    ll num5;
    for(i = 0; i <= 3; i++)
    {
        num5 = arr[i];
        if(i == 0) num5++, num5 %= 10;

        num1 *= 10;
        num1 += num5;
    }

    for(i = 0; i <= 3; i++)
    {
        num5 = arr[i];
        if(i == 1) num5++, num5 %= 10;

        num2 *= 10;
        num2 += num5;
    }

    for(i = 0; i <= 3; i++)
    {
        num5 = arr[i];
        if(i == 2) num5++, num5 %= 10;

        num3 *= 10;
        num3 += num5;
    }

    for(i = 0; i <= 3; i++)
    {
        num5 = arr[i];
        if(i == 3) num5++, num5 %= 10;

        num4 *= 10;
        num4 += num5;
    }

    a = solve(num1, turn + 1);
    b = solve(num2, turn + 1);
    c = solve(num3, turn + 1);
    d = solve(num4, turn + 1);

    if(turn % 2)
    {
        if(a || b || c || d) return dp[num][turn] = 1;

        return dp[num][turn] = 0;
    }

    if(a && b && c && d) return dp[num][turn] = 1;

        return dp[num][turn] = 0;


}


int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    memset(dp,-1,sizeof dp);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        if(solve(n,1))
        {
            printf("Ada\n");
        }
        else printf("Vinit\n");


    }


}


