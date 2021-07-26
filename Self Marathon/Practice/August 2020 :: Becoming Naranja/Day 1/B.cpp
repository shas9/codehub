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

deque < ll > dq[101];

ll grabtop(ll n)
{
	ll mx = 0;
	ll pos = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(!dq[i].empty())
		{
			mx = max(mx, dq[i].front());
			if(mx == dq[i].front()) pos = i;
		}
	}

	dq[pos].pop_front();

	return mx;
}

ll grabbot(ll n)
{
	ll mx = 0;
	ll pos = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(!dq[i].empty())
		{
			mx = max(mx, dq[i].back());
			if(mx == dq[i].back()) pos = i;
		}
	}

	dq[pos].pop_back();

	return mx;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	fastio;
    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) dq[i].clear();

		ll tot = 0;

		for(ll i = 1; i <= n; i++)
		{
			ll sz;
			cin >> sz;

			tot += sz;

			for(ll j = 1; j <= sz; j++)
			{
				cin >> input;

				dq[i].push_back(input);
			}
		}

		ll a1 = 0, a2 = 0;

		for(ll i = 1; i <= tot; i++)
		{
			if(i & 1) a1 += grabtop(n);
			else a2 += grabbot(n);
		}

		cout << a1 << " " << a2 << endl;
    }



}


