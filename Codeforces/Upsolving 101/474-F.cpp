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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009
#define mx 100005
using namespace std;

ll arr[mx];
pair < ll, ll > tree[mx*3];
map < ll, vector < ll > > mp;

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].first = arr[b];
        tree[node].second = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].first = __gcd(tree[left].first, tree[right].first);
    tree[node].second = min(tree[left].second, tree[right].second);
}

//void update(ll node, ll b, ll e, ll i, ll val)
//{
//    if(i > e || i < b)
//    {
//        return;
//    }
//
//    if(b == i && e == i)
//    {
//        tree[node] = val;
//        return;
//    }
//
//    ll left = node * 2;
//    ll right = (node * 2) + 1;
//    ll mid = (b + e) / 2;
//
//    update(left, b, mid, i, val);
//    update(right, mid + 1, e, i, val);
//
//    tree[node] = tree[left] + tree[right];
//}

ll gcd(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].first;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = gcd(left, b, mid, i, j);
    ll p2 = gcd(right, mid + 1, e,i, j);

    if(p1 == 0) return p2;
    else if(p2 == 0) return p1;
    return __gcd(p1,p2);
}

ll mini(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].second;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = mini(left, b, mid, i, j);
    ll p2 = mini(right, mid + 1, e,i, j);

    if(p1 == 0) return p2;
    else if(p2 == 0) return p1;
    return min(p1,p2);


}

ll lowww(ll l, ll num)
{
    ll ans = -1;
    ll low = 0;
    ll high = mp[num].size();

    while(low <= high)
    {
        ll mid = (low + high) / 2;
        ll x = mp[num][mid];

        if(x == l)
        {
            ans = mid;
            break;
        }
        else if(x > l)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }

    return ans;
}

ll uppp(ll l, ll num)
{
    ll ans = -1;
    ll low = 0;
    ll high = mp[num].size();

    while(low <= high)
    {
        ll mid = (low + high) / 2;
        ll x = mp[num][mid];

        if(x == l)
        {
            return mid + 1;
        }
        else if(x > l)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    //slld(testcase);

    //for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
            mp[arr[i]].pb(i);
        }

        init(1,1,n);

        slld(q);

        ll r;
        for(i = 1; i <= q; i++)
        {
            slld(l);
            slld(r);

            ll gc = gcd(1,1,n,l,r);
            ll mn = mini(1,1,n,l,r);

            if(gc != mn)
            {
                ans = (r - l) + 1;
            }
            else
            {
                ll low = lower_bound(mp[mn].begin(),mp[mn].end(), l) - mp[mn].begin();
                ll up = upper_bound(mp[mn].begin(),mp[mn].end(), r) - mp[mn].begin();

                //cout << low  << " :  " << up << endl;
                ans = (r - l) + 1 - (up - low);
            }

            plld(ans);
        }

    }


}




