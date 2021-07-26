#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%d\n", longvalue)

#define ll int

#define pll pair < int, int >



using namespace std;


#define mx 200005

struct info
{
    ll prop, summ;
} tree[mx*6];
ll arr[mx];

void init(ll node, ll b, ll e)
{
    tree[node].prop = 0;

    if(b > e) return;

    if(b == e)
    {
        tree[node].summ = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].summ = min(tree[left].summ,tree[right].summ);
}
void update(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        tree[node].summ++;
        tree[node].prop++;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);

    tree[node].summ = min(tree[left].summ,tree[right].summ);
    tree[node].summ += tree[node].prop;
}


pll solve(ll node, ll b, ll e, ll range)
{
    ll x = (e - b + 1);

    if(b > e) return make_pair(0,0);

    if(x <= range) return make_pair(b,e);

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    if(tree[left].summ < tree[right].summ) return solve(left,b, mid, range);
    else return solve(right,mid + 1, e, range);
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    ll w;

    slld(n);
    slld(m);
    slld(w);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    init(1,1,n);

    for(i = 1; i <= m; i++)
    {
        pll mnnode = solve(1,1,n,w);

        x = (mnnode.second - mnnode.first + 1);

        update(1,1,n,mnnode.first,mnnode.second);
    }

    plld(tree[1].summ);

}



