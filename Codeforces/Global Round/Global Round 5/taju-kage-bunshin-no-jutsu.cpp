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

#define lim 200005

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
	//cout<<valu<<' '<<node<<endl;
	ll l = 0 , r = tree[node].size() - 1 , mid;
	ll pos = 0;

	while ( l <= r ) {
		mid = (l + r) / 2;
		if ( tree[node][mid] <= valu ) {
			pos = mid + 1;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}


	return pos;
}

ll down( ll valu, ll node )
{
	ll l = 0 , r = tree[node].size() - 1 , mid;
	ll pos = tree[node].size();

	while ( l <= r )
    {
		mid = (l + r) / 2;
		if ( tree[node][mid] > valu ) {
			pos = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}


	return tree[node].size() - pos;
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

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        if(tree[node].size())
            tree[node][0] = val;
        else
            tree[node].pb(val);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node].clear();

    merge( tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    for(i = 1; i <= 200000; i++) arr[i] = mxlld;

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    merge_sort(1,1,200000);
    slld(testcase);

    ll ind = n;

    for(ll cs = 1; cs <= testcase; cs++)
    {
//        for(i = 1; i <= 10; i++)
//        {
//            printf("%lld ", tree[1][i]);
//        }
        slld(input);



        if(input == 1)
        {
            slld(flag);
            update(1,1,n,++ind,flag);
        }
        else if(input == 2)
        {
            ind--;
        }
        else
        {
            slld(l);
            slld(r);
            slld(k);

            ll lo = 1;
            ll hi = 1000000000;
            ans = 0;

            while(lo <= hi)
            {
                ll mid = (lo + hi) / 2;

                ll cnt = query(1,1,200000,l,r,mid);

                if(cnt < k)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }

            ans = hi;

            printf("%lld\n", ans);
        }
    }


}


