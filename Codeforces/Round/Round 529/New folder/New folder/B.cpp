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

ll tree[mx*3];
ll tree2[mx * 3];
vector < ll > vec;
map < ll, ll > mp;
vector < pair < ll, ll > > qq;

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

void update2(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree2[node] = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update2(left, b, mid, i, val);
    update2(right, mid + 1, e, i, val);

    tree2[node] = tree2[left] + tree2[right];
}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree2[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return p1 + p2;
}

ll fnd(ll node, ll b, ll e, ll y)
{
//    cout << b << " && " << e << " && " << y << endl;
    if(b == e)
    {
        return b;
    }
    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

//    cout << tree[left] << " " << tree[right] << endl;
//    cout << tree2[left] << " " << tree2[right] << endl;


    if(tree[right] >= y) return fnd(right,mid + 1, e, y);
    else return fnd(left, b, mid, y - tree[right]);
}


int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    memset(tree2, 0, sizeof tree2);
    memset(tree, 0, sizeof tree);
    vec.clear();
    mp.clear();
    qq.clear();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(i);
        slld(j);

        if(i == 1)
        {
            vec.push_back(j);
        }

        qq.push_back(make_pair(i,j));
    }

    sort(vec.begin(),vec.end());

    ll sz = vec.size();

    for(i = 0; i < sz; i++)
    {
        if(i > 0)
        {
            if(vec[i] == vec[i - 1]) continue;
        }
        mp[vec[i]] = i + 1;
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        i = qq[cs - 1].first;
        j = qq[cs - 1].second;

//        cout << i << " - " << j << endl;
//        cout << mp[j] << endl;

        if(i == 1)
        {
            update(1,1,sz,mp[j],1);
            update2(1,1,sz,mp[j],j);
        }
        else if(i == 2)
        {
            update(1,1,sz,mp[j],0);
            update2(1,1,sz,mp[j],0);
        }
        else
        {
            ll ind = fnd(1,1,sz,j);

//            cout << ind << endl;

            printf("%lld\n", sum(1,1,sz,ind,sz));
        }
    }


}



