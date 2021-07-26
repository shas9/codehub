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

pll arr[100005];

bool solve(ll idx, ll &now, ll &dest)
{
	if(dest == mnlld)
	{
		dest = arr[idx].second;
	}

	if(now < dest)
	{
		ll reach = min(now + arr[idx + 1].first - arr[idx].first, dest);

		if(reach == dest) dest = mnlld;

		ll z = now;
		now = reach;

		if(z <= arr[idx].second && arr[idx].second <= reach) return 1;
	}
	else
	{
		ll reach = max(now - arr[idx + 1].first + arr[idx].first, dest);

		if(reach == dest) dest = mnlld;

		ll z = now;
		now = reach;

		if(reach <= arr[idx].second && arr[idx].second <= z) return 1;
	}

	return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ll now = 0;
		ll dest = mnlld;
		ans = 0;

		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i].first);
			slld(arr[i].second);
		}

		arr[n + 1].first = 1e12;


		for(ll i = 1; i <= n; i++)
		{
			if(solve(i,now,dest)) ans++;

//			cout << now << " " << dest << " " << ans << endl;
		}

		cout << ans << "\n";
    }


}



