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

ll n, d, a;
pll arr[200005];

struct info
{
    ll prop, summ;
} tree[mx*5];

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        tree[node].summ += (e - b + 1) * val;
        tree[node].prop += val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node].summ = tree[left].summ + tree[right].summ + (e - b + 1) * tree[node].prop;
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].summ + carry * (e - b + 1);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = sum(right, mid + 1, e,i, j, carry + tree[node].prop);

    return p1 + p2;
}


ll solve(ll pos)
{
    if(pos > n) return 0;
    ll rght = arr[pos].first + (2 * d);

    ll lo = pos;
    ll hi = n;
    ll rpos = pos;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(arr[mid].first > rght)
        {
            hi = mid - 1;
        }
        else
        {
            rpos = mid;
            lo = mid + 1;
        }
    }

//    cout << pos << " " << rpos << endl;

    ll cnt = 0;

    arr[pos].second = sum(1,1,n,pos,pos);

    if(arr[pos].second < 0) arr[pos].second = 0;

//    cout << arr[pos].second << " ";

    ll att = (arr[pos].second / a);

    if(arr[pos].second % a) att++;

    cnt = att;

//    cout << att * a << " ";

    update(1,1,n,pos,rpos, -(att * a));

//    cout << cnt << endl;
//
//    cout << pos << " - " << rpos << endl;

//    for(ll i = 1; i <= n; i++)
//    {
//        cout << sum(1,1,n,i,i) << " ";
//    }
//
//    cout << endl;

    return cnt + solve(pos + 1);
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> d >> a)
    {
        memset(tree,0,sizeof tree);
        for(i = 1; i <= n; i++)
        {
            slld(arr[i].first);
            slld(arr[i].second);
        }

        sort(arr + 1, arr + 1 + n);

        for(i = 1; i <= n; i++)
            update(1,1,n,i,i,arr[i].second);

        ans = solve(1);

        cout << ans << endl;
    }


}


