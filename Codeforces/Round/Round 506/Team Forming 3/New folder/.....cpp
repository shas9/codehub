#include <bits/stdc++.h>
using namespace std;
/***template***/
#define ll                   long long
#define ___                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  1e18
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
#define uniquee(x)            x.erase(unique(x.begin(), x.end()),x.end())
#define print_vector(v)       for(ll i=0;i<(v.size());i++)cout<<v[i]<<" ";

ll Set(ll n,ll pos)
{
    return n=n|(1LL<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1LL<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}

/***template***/


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

ll arr[300005];
struct tree
{
    Trie *root;
}seg[4*300005];

void build(ll node, ll b, ll e)
{
    seg[node].root = new Trie();
    for(ll i = b; i <= e; i++)
    {
        insert(seg[node].root,arr[i]);
    }
    if (b == e)
    {
        return ;
    }
    ll mid = (b+e)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
}

ll query(ll node, ll b, ll e, ll i, ll j,ll val)
{
    if(b>j || e<i)return 0;
    if (b>=i && e<=j)return search(seg[node].root,val);
    ll mid = (b+e)/2;
    return max(query(node*2,b,mid,i,j,val),query(node*2+1,mid+1,e,i,j,val));
}

ll n;

int main()
{
    scl(n);
    FOR(i,n)scl(arr[i]);
    build(1,1,n);
    ll q;
    scl(q);
    FOR(i,q)
    {
        ll l,r,x;
        scl(l);
        scl(r);
        scl(x);
        printf("%lld\n",query(1,1,n,l,r,x));
    }
    return 0;
}



