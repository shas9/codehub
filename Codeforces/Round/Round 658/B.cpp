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

ll arr[100005];

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

		ll one = 0;

		for(ll i = 1; i <= n; i++) slld(arr[i]);
		for(ll i = 1; i <= n; i++) if(arr[i] == 1) one++;

		if(one == 0 || n == 1)
		{
			printf("First\n");
			continue;
		}

		bool on = 1;

		for(i = 1; i <= n; i++)
		{
			if(arr[i] != 1) break;

			on ^= 1;
		}

		if(i > n) on ^= 1;

		if(on) printf("First\n");
		else printf("Second\n");
    }


}




