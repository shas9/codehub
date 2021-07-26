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

pll dp[100005];
ll arr[100005];
ll n;

void process(ll x)
{
    if(x == 0) return;

    if(x + arr[x] > n)
    {
        dp[x].first = x;
        dp[x].second = 1;
    }
    else
    {
        dp[x].first = dp[x + arr[x]].first;
        dp[x].second = dp[x + arr[x]].second + 1;
    }

    process(x - 1);
}

void update(ll x, ll y)
{
    arr[x] = y;

    if(x + arr[x] > n)
    {
        dp[x].first = x;
        dp[x].second = 1;
    }
    else
    {
        dp[x].first = dp[x + arr[x]].first;
        dp[x].second = dp[x + arr[x]].second + 1;
    }
}

void solve(ll x)
{
    if(x + arr[x] > n)
    {
        dp[x].first = x;
        dp[x].second = 1;
    }
    else
    {
        dp[x].first = dp[x + arr[x]].first;
        dp[x].second = dp[x + arr[x]].second + 1;
    }
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++) slld(arr[i]);

    process(n);

    for(i = 1; i <= m; i++)
    {
        slld(q);

        if(q == 0)
        {
            slld(k);
            slld(r);
            update(k,r);
        }
        else
        {
            slld(k);

            solve(k);

            cout << dp[k].first << " " << dp[k].second << endl;
        }
    }




}


