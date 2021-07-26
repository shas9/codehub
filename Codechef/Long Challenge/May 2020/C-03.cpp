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

vector < pair < pll, ll > > ans;
vector < pll > two;
vector < ll > cycle;
bool vis[200005];
ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ans.clear();
		two.clear();

		slld(n);
		slld(k);

		for(i = 1; i <= n; i++) slld(arr[i]), vis[i] = 0;

		for(i = 1; i <= n; i++)
		{
			if(vis[i]) continue;

			cycle.clear();

			ll idx = i;

			while(vis[idx] == 0)
			{
				cycle.push_back(idx);

				vis[idx] = 1;

				idx = arr[idx];
			}

			while(cycle.size() > 2)
			{
				ll z = cycle.back();
				cycle.pop_back();
				ll y = cycle.back();
				cycle.pop_back();
				ll x = cycle.back();

				if(cycle.size() == 1) cycle.pop_back();

				ans.push_back({{x,y},z});
			}

			if(cycle.size() == 2) two.push_back({cycle[0],cycle[1]});
		}

		while(two.size() > 1)
		{
			pll x = two.back();
			two.pop_back();
			pll y = two.back();
			two.pop_back();

			ans.push_back({x,y.second});
			ans.push_back({y,x.first});
		}

		if(ans.size() > k || !two.empty()) printf("-1\n");
		else
		{
			cout << ans.size() << "\n";
			for(auto it: ans) cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
		}
    }


}


