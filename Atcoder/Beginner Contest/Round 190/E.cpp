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

ll arr[300005];
vector < ll > p;

void solve(ll n)
{
	p.clear();

	ll ans = 0;

	bit.init();

	for(ll i = 1; i <= n; i++)
	{
		ans += bit.query(n) - bit.query(arr[i]);

		bit.update(arr[i],1);
	}

	p.push_back(ans);

	for(ll i = 1; i <= n; i++)
	{
		ans -= arr[i] - 1;
		ans += n - arr[i];

		p.push_back(ans);
	}

	p.pop_back();

	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];

			arr[i]++;
		}

		solve(n);

		for(auto it: p) cout << it << "\n";
    }

}



