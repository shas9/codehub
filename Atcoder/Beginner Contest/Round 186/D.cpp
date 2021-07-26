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
} bit1(300002), bit2(300002);

map < ll, ll > mp;
ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		mp.clear();
		bit1.init();
		bit2.init();

		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];

			mp[arr[i]] = -1;
		}

		ll cnt = 0;

		for(auto &it: mp)
		{
			it.second = ++cnt;
		}

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			ll pos = mp[arr[i]];

			ll boro = bit1.query(cnt) - bit1.query(pos);
			ll choto = pos > 1 ? bit1.query(pos - 1) : 0;

			ll borof = bit2.query(cnt) - bit2.query(pos);
			ll chotof = pos > 1 ? bit2.query(pos - 1) : 0;

			ans += (boro - (borof * arr[i])) + ((chotof * arr[i]) - choto);

//			cout << boro << " " << borof << " " << choto << " " << chotof << "\n";

			bit1.update(pos,arr[i]);
			bit2.update(pos,1);

//			cout << ans << "\n";
		}

		cout << ans << "\n";
    }


}



