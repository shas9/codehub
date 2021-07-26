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

map < ll, ll > mp, mp2;
vector < ll > vec;

ll solve(ll pos, ll d, ll m)
{
	ll lo = pos + 1;
	ll hi = mp[mp2[pos] + m - 1];

//	cout << lo << " " << hi << " is ";

	ll ret = -1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		ll ask = bit.query(mid) - bit.query(pos) + 1;

		if(ask >= d)
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

//	cout << ret << endl;

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		bit.init();
		mp.clear();
		mp2.clear();
		vec.resize(m);

		for(auto &it: vec)
		{
			cin >> it;
			mp[it] = 0;
			mp[it + m - 1] = 0;
		}

		ll cnt = 0;

		for(auto &it: mp)
		{
			 it.second = ++cnt;
			 mp2[cnt] = it.first;
		}

		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		for(auto it: vec)
		{
			bit.update(mp[it], 1);
		}

		ans = 0;

		ll last = 0;

		for(ll i = 0; i < vec.size(); i++)
		{
			ll lft = mp[vec[i]];

			ll rgt = solve(lft, m - k, m);

			if(rgt == -1) continue;

			ll cnt1 = mp2[rgt] - m + 1;

			ans += min(vec[i] - last, vec[i] - cnt1 + 1);

			last = vec[i];

//			cout << i << " : " << vec[i] << " " << mp2[rgt] << " " << ans << endl;
		}

		if(m - k == 1 && vec.back() + (m - k) <= n)
		{
			ans++;
		}

		cout << ans << "\n";
    }


}



