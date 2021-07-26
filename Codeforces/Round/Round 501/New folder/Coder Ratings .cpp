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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll tree[200005];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

struct node
{
    ll x, y, id;

    node(ll _x, ll _y, ll _id)
    {
        x = _x;
        y = _y;
        id = _id;
    }
};

bool comp(node a, node b)
{
    if(a.x == b.x)
        if(a.y == b.y) return a.id < b.id;
        else return a.y < b.y;

    return a.x < b.x;
}

vector < node > vec;
ll ans[300005];
map < pll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(j);
        slld(k);

        vec.push_back(node(j,k,i));
    }

    sort(vec.begin(),vec.end(),comp);

    update(vec[0].y, 1, 100000);


    for(i = 1; i < n; i++)
    {
        ll id = vec[i].id;
        ll y = vec[i].y;

        flag = query(y);

        flag -= mp[make_pair(vec[i].x, vec[i].y)];

        mp[make_pair(vec[i].x, vec[i].y)]++;

        ans[id] = flag;

        update(y,1,100000);
    }

    for(i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }



}


