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

#define mx 200005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[mx];
ll tree[mx*3];
ll dp[mx];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = min(tree[left],tree[right]);

}

ll solve(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return -1;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = solve(left, b, mid, i, j);
    ll p2 = solve(right, mid + 1, e, i, j);

    if(p1 >= 0 && p2 >= 0)
    {
        return min(p1,p2);
    }
    else if(p1 == -1)
    {
        return p2;
    }
    else
    {
        return p1;
    }
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++) slld(arr[i]);

    ll flag1 = 1, flag2 = 1;

    for(i = 1; i <= n; i++)
    {
        if(arr[i] == m) flag1 = 0;
        if(arr[i] == 0) flag2 = 0;
    }

    if(flag1 && flag2)
    {
        cout << "NO" << endl;
        return 0;
    }

    if(flag1)
    {
        for(i = 1; i <= n; i++)
        {
            if(arr[i] == 0)
            {
                arr[i] = m;
                break;
            }
        }
    }

    arr[0] = 1;

    for(i = 1; i <= n; i++)
    {
        if(arr[i] == 0)
            if(arr[i + 1] > 0) arr[i] = min(arr[i - 1],arr[i + 1]);
            else arr[i] = arr[i - 1];
    }

    init(1,1,n);

    for(i = 1; i <= n; i++)
    {
        input = arr[i];

        if(dp[input] == 0)
        {
            dp[input] = i;
            continue;
        }

        ll mn = m;
//        if(dp[input] + 1 < i - 1)
        mn = solve(1,1,n,dp[input],i);

        if(mn < input)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    for(i = 1; i <= n; i++) printf("%lld ", arr[i]);



}


