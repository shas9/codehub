
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

ll dp[lim];

ll arr[lim * 2];
vector < ll > tree[4 * 2 * lim];

bool check(ll node, ll val)
{
//	ll sz = node.size();

	if(tree[node][0] < val) return 1;

	return 0;
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}



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
//
//ll up( ll valu, ll node ) {
//	//cout<<valu<<' '<<node<<endl;
//	ll l = 0 , r = tree[node].size() - 1 , mid;
//	ll pos = 0;
//
//	while ( l <= r ) {
//		mid = (l + r) / 2;
//		if ( tree[node][mid] <= valu ) {
//			pos = mid + 1;
//			l = mid + 1;
//		}
//		else {
//			r = mid - 1;
//		}
//	}
//
//
//	return pos;
//}
//
//ll down( ll valu, ll node )
//{
//	ll l = 0 , r = tree[node].size() - 1 , mid;
//	ll pos = tree[node].size();
//
//	while ( l <= r )
//    {
//		mid = (l + r) / 2;
//		if ( tree[node][mid] > valu ) {
//			pos = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//
//
//	return tree[node].size() - pos;
//}

bool query(ll node, ll a, ll b, ll i, ll j, ll val) {
	if ( a > j || b < i ) return 0;
	if ( i <= a && b <= j ) {

		bool ret = 0;
		if ( tree[node].size() )
			ret = check(node,val);
		//scout<<"ret "<<ret<<endl;
		return ret;

	}
	bool r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query( left , a, mid, i , j , val );
	r2 = query( right , mid + 1 , b, i, j, val);
	return r1 || r2;

}



int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    flag = 0;
    ll flag1 = 0;
    for(i = 1; i <= n; i++)
    {
        if(arr[i] == m) flag = 1;
        if(arr[i] == 0) flag1 = 1;
    }

//    cout << flag << " " << flag1 << endl;

    if(flag == 0 && flag1 == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    else if(flag == 0)
    for(i = 1; i <= n; i++)
    {
        if(arr[i] == 0)
        {
            arr[i] = m;
            break;
        }
    }

    arr[0] = m;
    arr[n + 1] = m;
    for(i = 1; i <= n; i++)
    {
        if(arr[i] == 0)
        {
            if(arr[i + 1] > 0)
            arr[i] = min(arr[i - 1], arr[i + 1]);
            else arr[i] = arr[i - 1];

        }
    }

//    bug;

    merge_sort(1,1,n);

//    bug;

    for(i = 0; i <= m; i++) dp[i] = 0;

    for(i = 1; i <= n; i++)
    {
        input = arr[i];

        if(dp[input] == 0)
        {
            dp[input] = i;
            continue;
        }

        if(dp[input] + 1 <= i - 1)
        if(query(1,1,n,dp[input] + 1, i - 1, input))
        {
            cout << "NO" << endl;

            return 0;
        }
    }

    cout << "YES" << endl;

    for(i = 1; i <= n; i++) printf("%lld ", arr[i]);
}


