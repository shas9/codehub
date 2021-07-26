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

#define lim 30000
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

ll up( ll valu, ll node ) {

    //cout<<valu<<" : "<<node<<endl;
	ll l = 0 , r = tree[node].size() - 1 , mid;
	ll pos = 0;

	while ( l <= r )
    {
		mid = (l + r) / 2;

		if ( tree[node][mid] <= valu )
        {
			pos = mid + 1;
			l = mid + 1;
		}
		else
        {
            r = mid - 1;
		}
	}

	ll x = (tree[node].size() - pos);

	//cout << "check x: " << x << endl;

	return x;
}

ll query(ll node, ll a, ll b, ll i, ll j, ll val) {
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
	r1 = query( left , a, mid, i , j , val );
	r2 = query( right , mid + 1 , b, i, j, val);
	return r1 + r2;

}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    slld(m);

    ans = 0;

    ll r;
    merge_sort(1,1,n);
    for(i = 1; i <= m; i++)
    {
        slld(l);
        slld(r);
        slld(k);

        l ^= ans;
        r ^= ans;
        k ^= ans;

        if(l < 1) l = 1;
        if(r > n) r = n;

        if(l > r)
        {
            ans = 0;
            plld(ans);
            continue;
        }
//        if(l == r)
//        {
//            if(arr[l] > k) ans = 1;
//            else ans = 0;
//
//            plld(ans);
//            continue;
//        }


        ans = query(1, 1, n, l, r, k);

        plld(ans);

    }


}

