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
ll arr[300005];

ll solve(ll n)
{
	sort(arr + 1, arr + 1 + n);

//	for(ll i = 1, j = 2 * n; i <= n && j )
}

void brute()
{
	vector < ll > v1, v2, v;

	v.clear();

	for(ll i = 1; i <= 6; i++) v.push_back(i);

	map < pll, ll > mp;

	while(next_permutation(v.begin(), v.end()))
	{
		v1.clear();
		v2.clear();

		for(ll i = 0; i < 3; i++) v1.push_back(v[i]);
		for(ll i = 0; i < 3; i++) v2.push_back(v[i + 3]);

		sort(v1.begin(),v1.end());
		sort(v2.rbegin(),v2.rend());

		for(ll i = 0; i < 3; i++)
		{

			mp[make_pair(min(v1[i], v2[i]), max(v1[i], v2[i]))]++;
		}
	}

	for(auto it: mp)
	{
		cout << it.first.first << " " << it.first.second << ": " << it.second << "\n";
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	brute();

    while(cin >> n)
    {
		for(ll i = 1; i <= 2 * n; i++) cin >> arr[i];

		ans = solve(n);

		cout << ans << "\n";
    }
}



