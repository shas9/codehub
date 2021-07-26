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

struct BIT
{
       vector < ll > tree;
       ll n;

       BIT(ll n) : n(n), tree(n + 3, 0) {}

       void init()
       {
			tree.assign(n + 3, 0);
       }

       ll query(ll idx)
       {
              ll sum=0;
              while(idx>0){
                    sum+=tree[idx];
                    idx -= idx & (-idx);
              }
              return sum;
       }

       void update(ll idx, ll x) //n is the size of the array, x is the number to add
       {
              while(idx<=n)
              {
                    tree[idx]+=x;
                    idx += idx & (-idx);
              }
       }
} bit(300002);

vector < pll > en[300005];
ll arr[300005];
ll ans[300005];

ll bs(ll x, ll hi)
{
	ll lo = 1;
	ll ret = hi;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(bit.query(mid) <= x)
		{
			ret = mid;

			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

//	cout << bit.query(ret) << endl;

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) en[i].clear();

		bit.init();

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		for(ll i = 1; i <= m; i++)
		{
			ll x, y;
			cin >> x >> y;

			l = x + 1;
			r = n - y;

			en[r].pb({l,i});
		}

		for(ll i = 1; i <= n; i++) arr[i] = i - arr[i];

		ll tot = 0;

		for(ll i = 1; i <= n; i++)
		{

//			for(ll j = 1; j <= i; j++) cout << bit.query(i) << " ! ";
//
//			cout << endl;

			if(arr[i] >= 0 && tot >= arr[i])
			{
				ll pos = bs(tot - arr[i], i);

				tot++;

//				cout << i << ": " << tot << " " << pos << endl;

				bit.update(pos + 1,1);
			}

			for(auto it: en[i])
			{
				ans[it.second] = tot - bit.query(it.first);
			}
		}

		for(ll i = 1; i <= m; i++)
		{
			cout << ans[i] << "\n";
		}
    }



}



