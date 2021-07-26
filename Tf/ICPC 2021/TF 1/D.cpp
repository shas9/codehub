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

vector < pll > vec, ans;
ll arr[200005];
ll nxt[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		vec.clear();
		ans.clear();

		for(ll i = 1; i <= n; i++)
		{
			vec.push_back({arr[i], i});
		}

		sort(vec.rbegin(), vec.rend());

		bool no = 0;

		for(ll i = 0; i <= n; i++)
		{
			nxt[i] = i + 1;
		}

		ll now = nxt[0];
		ll prv = 0;

		while(vec.back().first == 0) vec.pop_back();

		n = vec.size();
		ll rem = n - 1;

		for(ll i = 0; i < n; i++)
		{
			if(now == i) now = nxt[now];
			if(rem < vec[i].first)
			{
				no = 1;
				break;
			}

			while(now < n && vec[i].first)
			{
				vec[i].first--;
				ans.push_back({vec[i].second, vec[now].second});

				vec[now].first--;

				if(vec[now].first == 0)
				{
					rem--;
					nxt[prv] = nxt[now];
				}
				else
				{
					prv = now;
				}

				now = nxt[now];

				if(now >= n)
				{
					now = nxt[i];
					prv = i;
				}

				if(now == i) now = nxt[now];
			}
		}

		for(ll i = 0; i < n; i++)
		{
			if(vec[i].first > 0)
			{
				no = 1;
			}
		}

		if(no)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n" << ans.size() << "\n";

			for(auto it: ans)
			{
				cout << it.first << " " << it.second << "\n";
				assert(it.first != it.second);
			}
		}

    }


}



