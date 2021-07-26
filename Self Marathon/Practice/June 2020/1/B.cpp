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

vector < ll > g[1003];
vector < pll > ans;

ll arr[1003];
ll sarr[1003];

bool sorted(ll n)
{
	ll prv = -1;

	for(ll i = 1; i <= n; i++)
	{
		if(arr[i] < prv) return 0;

		prv = arr[i];
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++) g[i].clear();

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);

			sarr[i] = arr[i];

			for(j = i - 1; j >= 1; j--)
			{
				if(arr[j] > arr[i])
				{
					g[i].pb(j);
//					g[j].pb(i);
				}
			}
		}

		ans.clear();

		sort(sarr + 1, sarr + 1 + n);

		bool no = 0;

		for(i = n; i >= 1 && !sorted(n); i--)
		{
			if(arr[i] == sarr[i]) continue;

			if(g[i].empty())
			{
				no = 1;
				break;
			}

//			for(j = 1; j <= n; j++)
//			{
//				printf("%lld-", arr[j]);
//			}
//
//			cout << endl;
//
//			cout << i << ": " << arr[i] << " = ";

			for(auto it: g[i])
			{
				cout << it  << ", ";
				if(arr[it] == sarr[i])
				{
					ans.push_back({it,i});
					swap(arr[it],arr[i]);
					break;
				}
			}

			cout << arr[i] << endl;

			if(arr[i] != sarr[i])
			{
				no = 1;
				break;
			}
		}

		if(no) printf("-1\n");
		else
		{
			cout << ans.size() << '\n';

			for(auto it: ans)
			{
				cout << it.first << " " << it.second << '\n';
			}
		}
    }


}


