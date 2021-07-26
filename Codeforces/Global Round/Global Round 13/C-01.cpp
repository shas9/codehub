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

ll arr[100005];

struct BIT
{
       vector < ll > tree;
       ll n;

       void init(ll _n)
       {
			n = _n;
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
//		bug;
              while(idx<=n)
              {
                    tree[idx]+=x;
                    idx += idx & (-idx);
              }
       }
} bit;

ll solve(ll n)
{
	ll ret = 0;

	for(ll i = 1; i < n; i++)
	{
		if(bit.query(i) >= arr[i])
		{
			bit.update(i + 1, 1);
			if(arr[i] + i <= n) bit.update(arr[i] + i + 1, -1);

			ll extra = bit.query(i) - arr[i];

			bit.update(i + 1, extra);
			bit.update(i + 2, -extra);
		}
		else
		{
			bit.update(i + 2, 1);
			if(arr[i] + i <= n) bit.update(arr[i] + i + 1, -1);

			arr[i] -= bit.query(i);
			ret += arr[i] - 1;
		}
	}

	return ret += max(0LL, arr[n] - bit.query(n) - 1);;
}

/**
7
10
4 1 1 1 2 1 1 1 3 1
7
1 4 2 2 2 2 2
2
2 3
5
1 1 1 1 1
5
1 4 4 4 4
5
5 4 3 2 1
5
4 3 2 1 1
**/


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
		slld(n);

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		bit.init(n + n);

		ans = solve(n);

		cout << ans << "\n";

    }


}



