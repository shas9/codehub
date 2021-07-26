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

#define lim 10004
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[lim * 2];
ll cnt[lim * 2];
vector < ll > tree[4 * 2 * lim];
ll n;
ll cum[lim][105];

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
		if ( tree[node][mid] < valu ) {
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

    if(i > j) return 0;
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

ll query1(ll node, ll a, ll b, ll i, ll j, ll val) {

	if(i > j) return 0;
	if ( a > j || b < i ) return 0;
	if ( i <= a && b <= j ) {

		ll ret = 0;
		if ( tree[node].size() )
			ret = down( val, node );
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

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }
    memset(cum,0,sizeof cum);

    for(i = 1; i <= n; i++)
    {
        cum[i][arr[i]]++;

        for(j = 100; j >= 0; j--)
        {
            cum[i][j] += cum[i][j + 1];
        }

        for(j = 1; j <= 100; j++)
        {
            cum[i][j] += cum[i - 1][j];
        }
    }

    merge_sort(1,1,n);

    cnt[0] = 0;

    for(i = 1; i <= n; i++)
    {
        cnt[i] = query1(1,1,n,1, i - 1, arr[i]);

//        cout << cnt[i] << " ";

        cnt[i] += cnt[i - 1];
    }


    slld(m);

    for(i = 1; i <= m; i++)
    {
        ll t, u, v;

        slld(t);
        slld(u);
        slld(v);

        u++;
        v++;
        if(u > v) swap(u,v);

        if(t == 0)
        {
            ans = cnt[n];

            ans -= query(1,1,n,u + 1, v, arr[u]);
            ans += query1(1,1,n, u + 1, v - 1, arr[u]);

            ans += query(1,1,n,u, v - 1, arr[v]);
            ans -= query1(1,1,n,u + 1, v - 1, arr[v]);
        }
        else
        {
            ans = cnt[n];

            ans -= (cnt[v] - cnt[u - 1]);

            if(u == v)
            {
               ans -= query(1,1,n, v + 1, n, arr[u]);
            }
            else
            for(j = v + 1; j <= n; j++)
            {
//                ll zz = cum[v][100] - cum[v][arr[j]];
//                ll yy = cum[u - 1][100] - cum[u - 1][arr[j]];

                ans -= (cum[v][arr[i] + 1] - cum[u][arr[i] + 1]);

//                cout << (cum[v][arr[i] + 1] - cum[u][arr[i] + 1]) << endl;

//                cout << zz << " " << yy << endl;
            }

        }

        printf("%lld\n", ans);
    }


}



