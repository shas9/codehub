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

#define mx 300005
using namespace std;

bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

/*trie part*/
struct Trie
{
    ll endmark;
    Trie *Next[2];
    Trie()
    {
        endmark=0;
        for(ll i=0; i<2; i++) Next[i]=NULL;
    }
}*root;

void insert(Trie *curr,ll val)
{
    for(ll i=21;i>=0;i--)
    {
        ll id=check(val,i);
        if(curr->Next[id]==NULL)
            curr->Next[id]=new Trie();
        curr=curr->Next[id];
    }
    curr->endmark=val;
}
ll search(Trie *curr,ll val)
{
    for(ll i=21;i>=0;i--)
    {
        ll id=check(val,i);
        if (curr->Next[id^1] != NULL)curr=curr->Next[id^1];
        else curr=curr->Next[id];
    }
    return val^curr->endmark;
}
/*end of trie part*/


ll arr[mx];
struct
{
    Trie *root;
} tree[mx*4];;

void init(ll node, ll b, ll e)
{
    tree[node].root = new Trie();
    for(ll i = b; i <= e; i++)
    {
        insert(tree[node].root,arr[i]);
    }

    if(b == e) return;

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);
}

ll solve(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return search(tree[node].root,val);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = solve(left, b, mid, i, j,val);
    ll p2 = solve(right, mid + 1, e, i, j,val);

    return max(p1,p2);
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    init(1,1,n);

    slld(m);
    ll r, x;
    for(i = 1; i <= m; i++)
    {
        slld(l);
        slld(r);
        slld(x);

//        bug;

        ans = solve(1,1,n,l,r,x);

        plld(ans);
    }

}

