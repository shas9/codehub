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

ll arr[100005];
map < ll, deque < ll > > mp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ans = 0;
		mp.clear();

		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];

			mp[arr[i]].push_back(i);
 		}

 		for(auto &it: mp)
 		{
			it.second.push_back(n + 5);
 		}

		vector < ll > v1, v2;

		mp[0].push_back(n + 5);
		v1.push_back(0);
		v2.push_back(0);

		for(ll i = 1; i <= n; i++)
		{
			ll x = arr[i];

			if(v1.back() == x) v1.push_back(x);
			else if(v2.back() == x) v2.push_back(x);
			else if(mp[v2.back()].front() > mp[v1.back()].front()) v2.push_back(x);
			else v1.push_back(x);

			mp[x].pop_front();
		}

		ans = 0;

//		for(auto it: v1) cout << it << " + ";
//		for(auto it: v2) cout << it << " * ";
//		cout << endl;

		for(ll i = 1; i < v1.size(); i++) ans += v1[i] != v1[i - 1];
		for(ll i = 1; i < v2.size(); i++) ans += v2[i] != v2[i - 1];

		cout << ans << "\n";
    }


}



