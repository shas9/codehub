// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll lim = 1e5;

struct node
{
	ll first, second, third;

	const bool operator < (node const &x)
	{
		return x.third > third;
	}
};

ll arr[lim * 2];
vector < node > tree[4 * 2 * lim];

void merge_sort(ll node, ll a, ll b) {
	if (a == b) {
		tree[node].pb({arr[a], 0, arr[a]});
		return;
	}
	ll mid = (a + b) / 2 , left, right;
	left = node * 2 ; right = left + 1;
	merge_sort( left, a, mid);
	merge_sort( right, mid + 1, b);

	merge( tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

void process(ll node, ll a, ll b)
{
	ll num = 1;
	ll add = 0;

	for(auto &it: tree[node])
	{
		it.second = num;
		num++;

		it.first += add;
		add = it.first;

//		cout << it.third << " ";
	}

//	cout << endl;

	if(a == b) return;

	ll mid = (a + b) / 2 , left, right;
	left = node * 2 ; right = left + 1;

	process(left, a, mid);
	process(right, mid + 1, b);

}

pll up( ll valu, ll node ) {
	//cout<<valu<<' '<<node<<endl;
	ll l = 0 , r = tree[node].size() - 1 , mid;
	pll pos = {0,-1};

	while ( l <= r )
	{
		mid = (l + r) / 2;
		if ( tree[node][mid].third < valu )
		{
			pos = {tree[node][mid].first, tree[node][mid].second};
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	if(pos.second == -1) return {0,0};

	return pos;
}

pll down( ll valu, ll node )
{
	ll l = 0 , r = tree[node].size() - 1 , mid;
	pll pos = {0,-1};

	while ( l <= r )
    {
		mid = (l + r) / 2;
		if ( tree[node][mid].third > valu )
		{
			if(mid != 0) pos = {tree[node][mid - 1].first, tree[node][mid - 1].second};
			else pos = {0,0};
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	if(pos.second == -1) return {0,0};

	pos.first = tree[node].back().first - pos.first;
	pos.second = tree[node].back().second - pos.second;

	return pos;
}

pll query1(ll node, ll a, ll b, ll i, ll j, ll val)
{
	if ( a > j || b < i ) return {0,0};

	if ( i <= a && b <= j )
	{
		pll ret = {0,0};
		if ( tree[node].size() ) ret = up( val, node );

		return ret;
	}

	pll r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query1( left , a, mid, i , j , val );
	r2 = query1( right , mid + 1 , b, i, j, val);
	return {r1.first + r2.first, r2.second + r1.second};

}

pll query2(ll node, ll a, ll b, ll i, ll j, ll val)
{
	if ( a > j || b < i ) return {0,0};

	if ( i <= a && b <= j )
	{
		pll ret = {0,0};
		if ( tree[node].size() ) ret = down( val, node );

		return ret;
	}

	pll r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query2( left , a, mid, i , j , val );
	r2 = query2( right , mid + 1 , b, i, j, val);
	return {r1.first + r2.first, r2.second + r1.second};

}

ll solve(ll l, ll r, ll x, ll n)
{
	pll ask1 = query1(1, 1, n, l, r, x);
	pll ask2 = query2(1, 1, n, l, r, x);

	ll ret = ask1.second * x - ask1.first;
	ret += ask2.first - x * ask2.second;

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		for(ll i = 0; i < 4 * 2 * lim; i++) tree[i].clear();

		slld(n);

		for(ll i = 1; i <= n; i++) slld(arr[i]);

//		bug;
		merge_sort(1,1,n);
//		bug;

		process(1,1,n);
//		bug;
//
		slld(m);

		printf("Case %lld:\n", cs);

		for(ll i = 1; i <= m; i++)
		{
			slld(l);
			slld(r);
			slld(input);

			ans = solve(l,r,input, n);

			printf("%lld\n", ans);
		}

    }


}



