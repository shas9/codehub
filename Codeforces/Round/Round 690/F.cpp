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

vector < ll > v;
vector < pll > seg;

ll arr[200005 * 2];
vector < ll > tree[4 * 200005];

void merge_sort(ll node, ll a, ll b) {
	tree[node].clear();

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

ll solve2(ll idx)
{
	ll lo1 = 0;
	ll hi1 = idx;

	ll ret1 = idx;

	while(lo1 <= hi1)
	{
		ll mid = (lo1 + hi1) / 2;

		if(seg[mid].first >= seg[idx].first)
		{
			ret1 = mid;
			hi1 = mid - 1;
		}
		else
		{
			lo1 = mid + 1;
		}
	}

//	cout << idx << " ++ " << ret1 << endl;
//	idx = ret1;


	ll lim = seg[idx].second;

	ll lo = idx;
	ll hi = seg.size() - 1;
	ll ret = idx;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(seg[mid].first <= lim)
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return query(1,1,seg.size(),ret1 + 1, ret + 1, lim);
}

ll bs(ll x)
{
	ll lo = 0;
	ll hi = v.size() - 1;
	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (hi + lo) / 2;

		if(v[mid] <= x)
		{
			ret = mid + 1;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret;
}
ll solve1(ll idx)
{
	return bs(seg[idx].second) - bs(seg[idx].first - 1);
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
		v.clear();
		seg.clear();

		cin >> n;

		seg.resize(n);

		for(auto &it: seg)
		{
			 cin >> it.first >> it.second;
			 v.push_back(it.first);
			 v.push_back(it.second);
		}

		sort(v.begin(),v.end());
		sort(seg.begin(),seg.end());

		for(ll i = 0; i < n; i++)
		{
			arr[i + 1] = seg[i].second;
		}

		merge_sort(1,1,n);

		ans = 1;

		for(ll i = 0; i < n; i++)
		{
			ans = max(ans, solve1(i) - solve2(i));

//			cout << i << " : " << solve1(i) << " " << solve2(i) << "\n";
		}

		cout << n - ans << "\n";

    }


}



