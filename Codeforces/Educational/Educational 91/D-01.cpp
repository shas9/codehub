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

ll pos[200005];
ll arr[200005];
ll brr[200005];

bool issub(ll n, ll m)
{
	ll idx = 1;

	for(ll i = 1; i <= n; i++)
	{
		pos[i] = idx;
		if(idx <= m && brr[idx] == arr[i]) idx++;
	}

	if(idx <= m) return 0;
	return 1;
}

ll x, k, y;

ll solve(ll n, ll m)
{
	brr[m + 1] = mnlld;
	brr[0] = mnlld;

	ll cnt = 0;
	ll mx = 0;

	pos[n + 1] = 0;

	ll ret = 0;

//	for(ll i = 1; i <= n + 1; i++) cout << pos[i] << " ";
//	cout << endl;

	for(ll i = 1; i <= n; i++)
	{
		if(pos[i] == pos[i + 1])
		{
			cnt++;
			mx = max(mx, arr[i]);
		}
		else
		{
			if(i == n && arr[i] != brr[m])
			{
				cnt++;
				mx = max(mx, arr[i]);
			}

			if(mx > brr[pos[i] - 1] && mx > brr[pos[i]])
			{
				if(cnt < k) return -1;
				else
				{
					ret += x;
					cnt -= k;
				}
			}

			ret += (cnt / k) * min(x, y * k) + (cnt % k) * y;

			cnt = 0;
			mx = 0;
		}
	}

	return ret;
}

int main()
{
    ll i, j, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		slld(x);
		slld(k);
		slld(y);

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		for(ll i = 1; i <= m; i++)
		{
			slld(brr[i]);
		}

		if(issub(n,m) == 0)
		{
			printf("-1\n");
			continue;
		}

		ans = solve(n, m);

		printf("%lld\n", ans);
    }


}



