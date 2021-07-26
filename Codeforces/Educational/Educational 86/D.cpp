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

ll ck[200005];
ll arr[200005];
//ll cmn[200005];

vector < vector < ll > > ans;

set < ll > st;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		ans.clear();
		st.clear();

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		for(i = 1; i <= k; i++)
		{
			slld(ck[i]);
		}

		sort(arr + 1, arr + 1 + n);


		ans.push_back({});

		j = 1;

		for(i = n; i >= j; i--)
		{
			ll nn = arr[i];

			if(ans.back().size() >= ck[nn])
			{
				while(j < i)
				{
					if(ans.back().size() < ck[arr[j]])
					{
						ans.back().push_back(arr[j]);
					}
					else break;

					j++;
				}

				ans.push_back({});
			}

			ans.back().push_back(arr[i]);

		}

//		if(ans.back().empty()) ans.pop_back();

		assert(ans.size());
		cout << ans.size()  << "\n";

		ll tot = 0;

		for(i = 0; i < ans.size(); i++)
		{
			cout << ans[i].size() << " ";

			assert(ans[i].size());

			tot += ans[i].size();

			for(auto it: ans[i]) cout << it << " ";

			cout << "\n";
		}

		assert(tot == n);
    }


}



