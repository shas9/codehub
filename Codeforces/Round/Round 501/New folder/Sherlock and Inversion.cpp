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

#define lim 100005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll tree[lim];
unordered_map < ll, ll > mapp;
ll arr[lim];

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
    ll l, r, id, blc;
};

node q[lim];
ll ans[lim];

bool comp(node a, node b)
{
    if(a.blc != b.blc)
    {
        return a.blc < b.blc;
    }

    if(a.blc % 2 == 0)
    {
        return a.r < b.r;
    }
    else
    {
        return a.r > b.r;
    }
}

vector < ll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, qq;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(qq);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        vec.push_back(arr[i]);
    }

    sort(vec.begin(),vec.end());

    for(i = 0; i < n; i++)
    {
        mapp[vec[i]] = i + 1;
    }

    ll ssq = sqrt(n) + 1;

    for(i = 1; i <= qq; i++)
    {
        slld(l);
        slld(r);

        q[i].l = l;
        q[i].r = r;
        q[i].id = i;
        q[i].blc = l / ssq;
    }

    sort(q + 1, q + 1 + qq, comp);

    l = 1;
    r = 0;

    ll cnt = 0;

    for(i = 1; i <= qq; i++)
    {
//        cout << l << " " << r << " " << q[i].l << " " << q[i].r << endl;
        while(r < q[i].r)
        {
            ll ind = arr[++r];
            ind = mapp[ind];

            cnt += query(n);
            cnt -= query(ind);

//            cout << cnt  << " && " << r << endl;

            update(ind,1,n);

        }

        while(l < q[i].l)
        {
            ll ind = arr[l];
            ind = mapp[ind];
            cnt -= query(ind - 1);

            update(ind,-1,n);

            l++;
        }

        while(l > q[i].l)
        {
            ll ind = arr[--l];
            ind = mapp[ind];

            cnt += query(ind - 1);

            update(ind,1,n);
        }

        while(r > q[i].r)
        {
            ll ind = arr[r];
            ind = mapp[ind];

            cnt -= (query(n) - query(ind));

            update(ind,-1,n);
            r--;
        }

        ans[q[i].id] = cnt;
    }

    for(i = 1; i <= qq; i++) plld(ans[i]);



}


