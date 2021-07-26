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

ll arr[103];

vector < pll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		vec.clear();

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		for(ll i = 1; i <= k + 1; i++)
		{
			ll mx = 0;
			ll mn = mxlld;

			for(ll j = 1; j <= n; j++) mx = max(mx, arr[j]), mn = min(mn, arr[j]);

			if(i == k + 1 || mx == mn)
			{
				ans = mx - mn;
				break;
			}

			vec.push_back({0,0});
			for(ll j = 1; j <= n; j++)
			{
				if(arr[j] == mx)
				{
					arr[j]--;
					mx = mnlld;

					vec.back().first = j;
				}
				else if(arr[j] == mn)
				{
					arr[j]++;
					mn = mnlld;

					vec.back().second = j;
				}
			}
		}

		cout << ans << " " << vec.size() << "\n";

		for(auto it: vec) cout << it.first << " " << it.second << "\n";
    }


}



