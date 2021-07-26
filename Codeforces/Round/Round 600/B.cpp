// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

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

ll arr[100005];
vector < ll > vec;
map < ll, ll > mp;

bool solve(ll n)
{

	vec.clear();
	set < ll > st;

	for(ll i = 1, cnt = 0; i <= n; i++)
	{
		if(arr[i] < 0 && mp[-1 * arr[i]] == 0) return 0;

		if(mp[arr[i]]) return 0;

		if(arr[i] < 0)
		{
			st.erase(st.find(-1 * arr[i]));
			mp[arr[i]] = 1;
		}
		else
		{
			st.insert(arr[i]);
			mp[arr[i]] = 1;
		}

		cnt++;

		if(st.empty())
		{
			vec.push_back(cnt);
			mp.clear();
			cnt = 0;
		}
	}

	if(st.empty()) return 1;

	return 0;
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
		for(i = 1; i <= n; i++) slld(arr[i]);

		ll days = 0;

		if(solve(n) == 0) printf("-1\n");
		else
		{
			cout << vec.size() << "\n";

			for(auto it: vec) cout << it << " ";

			cout << "\n";
		}

    }


}

