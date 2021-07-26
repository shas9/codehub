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
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll val[500005];
ll arr[500005];
vector < ll > graph[500005];
pll cnt[500005];
ll xx;

void dfs(ll par, ll node)
{
    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll top = graph[node][i];

        if(top == par) continue;

        cnt[top].first = ++xx;

        val[xx] = arr[top];

        dfs(node,top);

        cnt[top].second = xx;

//        cout << top << " || " << cnt[top].first << " " << cnt[top].second << endl;
    }
}

vector < ll > tree[2000006];

void merge_sort(ll node, ll a, ll b) {
	if (a == b) {
		tree[node].pb(val[a]);
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
		if ( tree[node][mid] <= valu )
        {
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
		if ( tree[node][mid] >= valu ) {
			pos = mid ;
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
			ret = down( val, node );
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

ll solve(ll l, ll r, ll x, ll n)
{
    if(l > r) return 0;


    return query(1,1,n,l,r,x);
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 2; i <= n; i++)
    {
        slld(input);

        graph[input].push_back(i);
        graph[i].push_back(input);
    }

    for(i = 1; i <= n; i++) slld(arr[i]);

    xx = 1;
    cnt[1].first = 1;
    cnt[1].second = n;
    val[1] = arr[1];

    dfs(-1,1);

//    for(i = 1; i <= n; i++)
//    {
//        cout << cnt[i].first << " - " << cnt[i].second << endl;
//    }


//    for(i = 1; i <= n; i++)
//    {
//        cout << val[i] << " ";
//    }
//
//    cout << endl;

    merge_sort(1,1,n);

    for(i = 1; i <= m; i++)
    {
        ll v, x;

        slld(v);
        slld(x);

        ll l = cnt[v].first;
        ll r = cnt[v].second;

        ans = solve(l,r,x, n);

        printf("%lld\n", ans);

    }




}



