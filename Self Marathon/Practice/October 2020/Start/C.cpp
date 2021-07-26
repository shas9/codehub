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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		if(n * 2 + 2 < m)
		{
			cout << -1 << "\n";
			continue;
		}

		if(n > m + 1)
		{
			cout << -1 << "\n";
			continue;
		}

		while(n < m && n)
		{
			cout << "110";

			m -= 2;
			n -= 1;
		}

		if(n == 0) for(ll i = 1; i <= m; i++) cout << 1;
		else if(n > m)
		{
			for(ll i = 1; i <= m; i++) cout << "01";
			cout << "0";
		}
		else
		{
			for(ll i = 1; i <= n; i++) cout << "10";
		}

		cout << "\n";


    }

}


