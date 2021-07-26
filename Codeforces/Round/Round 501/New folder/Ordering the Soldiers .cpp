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
ll ans[mx];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = 1;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right] ;

}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] + tree[right];
}


ll solve(ll node, ll b, ll e, ll val)
{
//    cout << node << " & " << b << " & " << e << " & " << val << endl;
    if(b == e) return b;

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    if(tree[left] >= val) return solve(left, b, mid, val);

    return solve(right, mid + 1, e, val - tree[left]);


}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i <= n; i++) slld(arr[i]);

        init(1,1,n);

        for(i = n; i >= 1; i--)
        {
            ll ind = i - arr[i];

            ans[i] = solve(1,1,n,ind);

//            cout << ind << " " << ans[i] << endl;
            update(1,1,n,ans[i],0);
        }

        for(i = 1; i <= n; i++)
        {
            if(i != 1) printf(" ");

            printf("%lld", ans[i]);
        }

        printf("\n");
    }


}

