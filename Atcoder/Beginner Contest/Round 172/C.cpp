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

vector < ll > v1, v2;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	while(cin >> n >> m >> k)
	{
		ans = 0;

		v1.clear();
		v2.clear();

		for(ll i = 0; i < n; i++) slld(input), v1.push_back(input);
		for(ll i = 0; i < m; i++) slld(input), v2.push_back(input);

		i = 0, j = 0;

		while(i < n && j < m && k > 0)
		{
			if(v1[i] <= v2[j])
			{
				k -= v1[i];
				i++;
			}
			else
			{
				k -= v2[j];
				j++;
			}
			ans++;
		}

		bool x = 0, y = 0;
		while(i < n && k > 0)
		{
			x = 1;
			k -= v1[i];
			i++;
			ans++;
		}

		while(j < m && k > 0)
		{
			y = 1;
			k -= v2[j];
			j++;
			ans++;
		}

		assert(!(x & y));

		if(k < 0) ans--;

		printf("%lld\n", ans);
	}

}

/*

7 3 15
5 5 1 1 1 1 1
3 2 5

*/




