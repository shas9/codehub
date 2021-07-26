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

ll arr[lim * 2];
vector < ll > tree[4 * 2 * lim];

void merge_sort(ll node, ll a, ll b) {
	if (a == b) {
		tree[node].pb(arr[a]);
		return;
	}
	ll mid = (a + b) / 2 , left, right;
	left = node * 2 ; right = left + 1;
	merge_sort( left, a, mid);
	merge_sort( right, mid + 1, b);

	merge( tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}
ll low( ll valu, ll node ) {
	//cout<<valu<<' '<<node<<endl;
	ll l = 0 , r = tree[node].size() - 1 , mid;
	ll pos = 0;

    while ( l <= r )
    {
		mid = (l + r) / 2;

		if ( tree[node][mid] >= valu )
        {
			r = mid - 1;
		}
		else
		{
            pos = mid + 1;
			l = mid + 1;
		}
	}


	return pos;
}

ll up( ll valu, ll node ) {
	//cout<<valu<<' '<<node<<endl;
	ll l = 0 , r = tree[node].size() - 1 , mid;
	ll pos = -1;

	while ( l <= r )
    {
		mid = (l + r) / 2;

		if ( tree[node][mid] <= valu )
		{
			l = mid + 1;
		}
		else
		{
		    pos = mid + 1;
			r = mid - 1;
		}
	}

	if(pos == -1) return 0;


	return tree[node].size() - pos + 1;
}

ll query1(ll node, ll a, ll b, ll i, ll j, ll val) {
	if ( a > j || b < i ) return 0;
	if ( i <= a && b <= j ) {

		ll ret = 0;
		if ( tree[node].size() )
			ret = low( val, node );
		//scout<<"ret "<<ret<<endl;
		return ret;

	}
	ll r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query1( left , a, mid, i , j , val );
	r2 = query1( right , mid + 1 , b, i, j, val);
	return r1 + r2;

}

ll query2(ll node, ll a, ll b, ll i, ll j, ll val) {
	if ( a > j || b < i ) return 0;
	if ( i <= a && b <= j ) {

		ll ret = 0;
		if ( tree[node].size() )
			ret = up( val, node );
		//scout<<"ret "<<ret<<endl;
		return ret;

	}
	ll r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query2( left , a, mid, i , j , val );
	r2 = query2( right , mid + 1 , b, i, j, val);
	return r1 + r2;

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

ll cnt;


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    //freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    slld(m);

    merge_sort(1,1,n);

    ll r;
    ll ssq = sqrt(n) + 1;
    for(i = 1; i <= m; i++)
    {
        slld(l);
        slld(r);

        q[i].l = l;
        q[i].r = r;
        q[i].id = i;
        q[i].blc = l / ssq;
    }

    sort(q + 1,q + 1 + m,comp);

    l = 1;
    r = 0;

    cnt = 0;

    for(i = 1; i <= m; i++)
    {
        //cout << q[i].l << " : " << q[i].r << endl;

        while(l < q[i].l)
        {
            //bug;
            flag = query1(1,1,n,l + 1, r, arr[l]);

            cnt -= flag;

            l++;

            //cout << flag << " " << l <<
        }

        while(l > q[i].l)
        {
            //bug;
            flag = query1(1,1,n,l, r, arr[l - 1]);

            cnt += flag;

            l--;
        }

        while(r < q[i].r)
        {
            flag = query2(1,1,n,l,r,arr[++r]);

            cnt += flag;

            //cout << flag << " : " << cnt << " : " << r << endl;
        }

        while(r > q[i].r)
        {
            flag = query2(1,1,n,l,r - 1,arr[r]);

            cnt -= flag;

            r--;
        }

        ans[q[i].id] = cnt;
    }

    for(i = 1; i <= m; i++)
    {
        plld(ans[i]);
    }




}


