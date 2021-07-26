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

vector < pll > vec;
set < ll > st;

bool solve(ll floor)
{
	for(auto it: vec)
	{
		ll need = it.first / floor;

		if(it.first % floor) need++;

		if(it.second != need) return 0;
	}

	return 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		vec.clear();
		st.clear();

		vec.resize(m);

		ans = -1;

		for(ll i = 0; i < m; i++)
		{
			cin >> vec[i].first >> vec[i].second;

			if(vec[i].first == n) ans = vec[i].second;
		}

		if(ans != -1)
		{
			cout << ans << "\n";
			continue;
		}


		for(ll i = 1; i <= 100; i++)
		{
			if(solve(i))
			{
				ll need = n / i;

				if(n % i) need++;

				st.insert(need);
			}
		}

		if(st.size() != 1) cout << -1 << "\n";
		else
		{
			cout << *st.begin() << "\n";
		}
    }


}



