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

struct node
{
    ll a, h, id;
};

bool comp(node a, node b)
{
    return a.h < b.h;
}

node arr[300005];

pll tree[1200006];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = {arr[b].a,arr[b].id};
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = max(tree[left], tree[right]);
}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node].first = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = max(tree[left], tree[right]);
}

pll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return {0,0};
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    pll p1 = sum(left, b, mid, i, j);
    pll p2 = sum(right, mid + 1, e,i, j);

    return max(p1,p2);
}

ll fndind(ll i, ll n)
{
    ll lo = 1;
    ll hi = n;

    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(arr[mid].h <= arr[i].a)
        {
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i].a);
            slld(arr[i].h);

            arr[i].id = i;
        }

        sort(arr + 1, arr + 1 + n, comp);

        ans = 0;
        pll cast = {1,2};

        init(1,1,n);

        for(i = 1; i <= n; i++)
        {
            ll ind = fndind(i, n);

            update(1,1,n,i,0);

            pll xx = sum(1,1,n,1,ind);

            if((xx.first >= arr[i].h) && (ans < (xx.first + arr[i].a)))
            {
                ans = xx.first + arr[i].a;
                cast = {xx.second, arr[i].id};
            }
            else if((tree[1].first >= arr[i].h) && (ans < arr[i].a))
            {
                ans = arr[i].a;
                cast = {tree[1].second,arr[i].id};
            }
            else if(ans < xx.first)
            {
                ans = xx.first;
                cast = {xx.second,arr[i].id};
            }

            update(1,1,n,i,arr[i].a);
        }

        cout << ans << endl;
        cout << cast.second << " " << cast.first << endl;
    }


}


