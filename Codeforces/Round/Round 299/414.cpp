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

#define lim (1 << 21)
using namespace std;

ll arr[lim + 20];
vector < ll > tree[4 * lim];

ll normal[25];
ll rev[25];
bool check[25];

void merge_sort(ll node, ll a, ll b, ll lev) {
	if (a == b) {
		tree[node].pb(arr[a]);
		return;
	}
	ll mid = (a + b) / 2 , left, right;
	left = node * 2 ; right = left + 1;
	merge_sort( left, a, mid, lev + 1);
	merge_sort( right, mid + 1, b, lev + 1);

	ll i = 0, j = 0;

	while(1)
    {
        if(i == tree[left].size())
        {
            for(ll ind = j; ind < tree[right].size(); ind++)
            {
                tree[node].pb(tree[right][ind]);
            }
            break;
        }

        if(j == tree[right].size())
        {
            for(ll ind = i; ind < tree[left].size(); ind++)
            {
                tree[node].pb(tree[left][ind]);
            }
            break;
        }

        if(tree[left][i] > tree[right][j])
        {
            normal[lev] += tree[left].size()- i;
            tree[node].pb(tree[right][j]);
            j++;
        }
//        else if(tree[left][i] < tree[right][j])
//        {
//            rev[lev] += tree[right].size() - j;
//            tree[node].pb(tree[left][i]);
//            i++;
//        }
        else
        {
            tree[node].pb(tree[left][i]);
            i++;
        }

    }

    i = j = 0;

    while(1)
    {
        if(i == tree[left].size()) break;
        if(j == tree[right].size()) break;

        if(tree[left][i] < tree[right][j])
        {
            rev[lev] += tree[right].size() - j;
            i++;
        }
        else
        {
            j++;
        }
    }

}

//ll up( ll valu, ll node ) {
//
//    //cout<<valu<<" : "<<node<<endl;
//	ll l = 0 , r = tree[node].size() - 1 , mid;
//	ll pos = 0;
//
//	while ( l <= r )
//    {
//		mid = (l + r) / 2;
//
//		if ( tree[node][mid] <= valu )
//        {
//			pos = mid + 1;
//			l = mid + 1;
//		}
//		else
//        {
//            r = mid - 1;
//		}
//	}
//
//	ll x = (tree[node].size() - pos);
//
//	//cout << "check x: " << x << endl;
//
//	return x;
//}
//
//ll query(ll node, ll a, ll b, ll i, ll j, ll val) {
//	if ( a > j || b < i ) return 0;
//	if ( i <= a && b <= j ) {
//
//		ll ret = 0;
//		if ( tree[node].size() )
//			ret = up( val, node );
//		//scout<<"ret "<<ret<<endl;
//		return ret;
//
//	}
//	ll r1 , r2;
//	ll left, right, mid;
//	left = node * 2 ;  right = left + 1;
//	mid = (a + b) / 2;
//	r1 = query( left , a, mid, i , j , val );
//	r2 = query( right , mid + 1 , b, i, j, val);
//	return r1 + r2;
//
//}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    ll sz = (1 << n);

    for(i = 1; i <= sz; i++) slld(arr[i]);

    merge_sort(1,1,sz,0);

    slld(m);

    for(i = 0; i < 24; i++) check[i] = 1;

    ll x;

    //bug;
    for(ll y = 1; y <= m; y++)
    {
        //cout << y << " :: " << endl;
        slld(x);

        ll lev = n - x;

        for(i = lev; i <= n; i++)
        {
            if(check[i]) check[i] = 0;
            else check[i] = 1;
        }

        ans = 0;
        for(i = 0; i <= n; i++)
        {
            if(check[i]) ans += normal[i];
            else ans += rev[i];
        }

        cout << ans << endl;
    }



}


