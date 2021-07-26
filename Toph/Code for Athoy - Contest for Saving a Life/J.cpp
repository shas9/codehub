// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

map < ll, ll > mp, mp1;
vector < ll > vec;

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
		slld(k);

		mp.clear();
		mp1.clear();
		vec.clear();

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			ll x, y;

			slld(x);
			slld(y);

			ans += abs(x - k);

			vec.push_back(y);
			mp1[y]++;
			mp[y] = 1;
		}

		bool x = 0;

		for(auto it: mp1)
		{
			ll lft = it.first;
			ll rgt = it.first;

			for(j = 2; j <= it.second; j++)
			{
				if((j & 1))
				{
					while(mp.find(rgt) != mp.end()) rgt++;

					mp[rgt]++;

				}
				else
				{
					while(mp.find(lft) != mp.end()) lft--;

					mp[lft]++;
				}
			}
		}

		ll idx = 0;
		sort(vec.begin(),vec.end());

		for(auto it: mp)
		{
			ans += abs(vec[idx++] - it.first);

//			cout << it.first << " ";
		}

//		cout << endl;

		cout << "Case #" << cs << ": " << ans << '\n';
    }


}



