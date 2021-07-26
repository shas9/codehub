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

vector < ll > v, v1, v2;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		v.resize(n);

		v1.clear();
		v2.clear();

		ll h1 = n / 2;
		ll h2 = n - h1;

		for(auto &it: v) cin >> it;

		for(ll i = 0; i < (1 << h1); i++)
		{
			ll sum = 0;

			for(ll j = 0; j < h1; j++)
			{
				if(check(i,j))
				{
					sum += v[j];
				}
			}

			v1.push_back(sum % m);
		}

		for(ll i = 0; i < (1 << h2); i++)
		{
			ll sum = 0;

			for(ll j = 0; j < h2; j++)
			{
				if(check(i,j))
				{
					sum += v[j + h1];
				}
			}

			v2.push_back(sum % m);
		}

		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());

		ans = 0;

		for(auto it: v1)
		{
			ll need = m - it - 1;

			auto jt = upper_bound(v2.begin(),v2.end(), need);

			jt--;

			ans = max(ans, it + *jt);
		}

		cout << ans << "\n";

    }


}



