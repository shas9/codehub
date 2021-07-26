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
bool chose[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.clear();

		for(ll i = 0; i < n; i++)
		{
			slld(input);

			vec.push_back({input,i});
			chose[i] = 0;
		}

		sort(vec.rbegin(),vec.rend());

		bool adj = 0;
		ll took = (n + 1) / 2;
		ans = 0;

		for(auto it: vec)
		{
			if(took == 1) break;

			ll lft = ((it.second - 1) + n) % n;
			ll rgt = ((it.second + 1)) % n;

			if(chose[lft] || chose[rgt]) continue;

			ans += it.first;

			chose[it.second] = 1;

			took--;
		}

		for(auto it: vec)
		{
			if(chose[it.second]) continue;

			ll lft = ((it.second - 1) + n) % n;
			ll rgt = ((it.second + 1)) % n;

			if(chose[lft] || chose[rgt])
			{
				ans += it.first;
				took--;
				break;
			}
		}

//		assert(took != 0);

		if(n == 1) ans += vec.front().first;

		printf("%lld\n", ans);
    }

}


