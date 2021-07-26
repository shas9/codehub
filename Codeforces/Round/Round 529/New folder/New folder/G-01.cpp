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


#define mx 200005

struct info
{
    ll prop, summ;

} tree[mx*3];

struct info2
{
    ll l, r;
    ll cond;

    vector < ll > graph;
} arr[mx];

ll arra[mx];

ll node;
ll cnt;

void dfs(ll x)
{
    ll l = cnt + 1;
    ll r;

    ll sz = arr[x].graph.size();

    for(ll i = 0; i < sz; i++)
    {
        ll top = arr[x].graph[i];

        dfs(top);
    }

    arr[x].l = l;
    arr[x].r = ++cnt;
}

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].summ = arra[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].summ = tree[left].summ + tree[right].summ;


}

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{

    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        tree[node].summ = (e - b + 1) - tree[node].summ;
        tree[node].prop += val;
        tree[node].prop %= 2;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node].summ = tree[left].summ + tree[right].summ;

    if(tree[node].prop % 2) tree[node].summ = (e - b + 1) - tree[node].summ;
}

void printtt()
{
    for(ll i = 1; i <= 25; i++)
    {
        cout << tree[i].summ << " ";
    }

    cout << endl;

    for(ll i = 1; i <= 25; i++)
    {
        cout << tree[i].prop << " ";
    }

    cout << endl;
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
//    bug;
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        if(carry % 2) return (e - b + 1) - tree[node].summ;
        else return  tree[node].summ;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = sum(right, mid + 1, e,i, j, carry + tree[node].prop);

    return p1 + p2;
}






int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(node);

    for(i = 2; i <= node; i++)
    {
        slld(input);

        arr[input].graph.push_back(i);
    }

    cnt = 0;
    dfs(1);

    for(i = 1; i <= node; i++)
    {
        slld(input);

        arr[i].cond = input;

        arra[arr[i].r] = input;
    }

    init(1,1,node);


    slld(q);

    char xx[20];

//    printtt();

    for(i = 1; i <= q; i++)
    {
        scanf("%s %lld", xx, &input);
//        cout << xx << " && " << input << endl;

        if(xx[0] == 'g')
        {
//            cout << arr[input].l << " " << arr[input].r << endl;

            printf("%lld\n", sum(1,1,node,arr[input].l,arr[input].r));
        }
        else
        {
            update(1,1,node,arr[input].l,arr[input].r,1);
        }

//        printtt();
    }



}



