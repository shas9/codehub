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

ll arr[200005];

struct info
{
	ll ev, od;

} sqblc[505];

ll sqsz = 400;

void cle()
{
	for(ll i = 0; i <= 500; i++)
	{
		sqblc[i] = {mxlld, 0,0};
	}
}

void build(ll n)
{
	for(ll i = 1; i <= n; i++)
	{
		if(i & 1)
		{
			sqblc[((i - 1) / sqsz) + 1].od = min(sqblc[((i - 1) / sqsz) + 1].od, arr[i]);
		}
		else
		{
			sqblc[((i - 1) / sqsz) + 1].ev = min(sqblc[((i - 1) / sqsz) + 1].ev, arr[i]);

		}
	}

	return;
}

bool check(ll n)
{
	ll now = arr[1];

	for(ll i = 2; i <= n; i++)
	{
		if(now == 0)
		{
			now = arr[i];
			continue;
		}

		if(now > arr[i]) return 0;

		now = arr[i] - now;
	}

	return now == 0;
}

bool soln(ll n, ll pos)
{

}

bool solve(ll n)
{
	if(check(n)) return 1;

	ll diff = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(diff > arr[i])
		{
			if(soln(n, i)) return 1;
			else return 0;
		}
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
		slld(n);

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
    }


}


