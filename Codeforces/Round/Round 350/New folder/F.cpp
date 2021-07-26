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

struct node
{
    ll st, ed, w;

    node(ll a, ll b, ll c)
    {
        st = a;
        ed = b;
        w = c;
    }
};

bool comp(node a, node b)
{
    return a.st < b.st;
}
vector < node > vec;
vector < ll > start;

ll dp[10005];
ll n;

ll low(ll x)
{
    ll low = 0;
    ll high = start.size();

    ll ans = high;
    while(low <= high)
    {
        ll mid = (low + high) / 2;


        if(start[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
ll solve(ll now)
{
    if(now >= n) return 0;

    if(dp[now] != -1) return dp[now];


    dp[now] = solve(now + 1);

    ll x = low(vec[now].ed);

    return dp[now] = max(dp[now], solve(x) + vec[now].w);


}
int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(dp,-1,sizeof dp);
        vec.clear();
        start.clear();


        slld(n);

        for(i = 1; i <= n; i++)
        {
            ll a, b, c;

            slld(a);
            slld(b);
            slld(c);


            b += a;

            vec.pb(node(a,b,c));
            start.pb(a);
        }

        sort(vec.begin(),vec.end(),comp);
        sort(start.begin(),start.end());

        printf("%lld\n", solve(0));
    }




}

