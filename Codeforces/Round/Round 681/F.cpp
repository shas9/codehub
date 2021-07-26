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

const ll mod = 998244353;
ll a[200005];
ll b[200005];

set < ll > st;
map < ll, ll > mp;

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
};

ll solve(ll n, ll k)
{
	mp.clear();
	st.clear();

	for(ll i = 1; i <= n; i++) mp[a[i]] = i;

	for(ll i = 1; i <= k; i++) st.insert(mp[b[i]]);

	BIT bit(n);
	bit.init();

	ll ret = 1;

	st.insert(n + 1);
	st.insert(0);
//
//	for(auto it: st) cout << it << " ";
//	cout << endl;
	for(ll i = 1; i <= k; i++)
	{
		ll pos = mp[b[i]];
		st.erase(st.find(pos));

		auto it = st.upper_bound(pos);
		ll daan = *it - 1;

		it--;
		ll baam = *it;
		baam = baam + 1;

//		cout << b[i] << ": " << baam << " " << daan << endl;



		ll daane = (daan - pos) - bit.query(daan) + bit.query(pos);
		ll baame = (pos - baam) - bit.query(pos) + (baam > 1 ? bit.query(baam - 1) : 0);

//		cout << daane << " " << baame << endl;

		if(daane && baame) ret = (ret * 2LL) % mod;
		else if(daane == 0 && baame == 0) return 0;

		bit.update(pos,1);
	}

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
		cin >> n >> k;

		for(ll i = 1; i <= n; i++) cin >> a[i];
		for(ll i = 1; i <= k; i++) cin >> b[i];

		ans = solve(n,k);

		cout << ans << "\n";
    }


}



