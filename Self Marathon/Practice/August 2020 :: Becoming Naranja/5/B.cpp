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

string str;

bool solve(ll n)
{
	for(ll i = 0; i <= 500; i++)
	{
		ll seg = 0;
		ll sum = 0;

		for(auto it: str)
		{
			sum += (it - '0');

			if(sum == i)
			{
				sum = 0;
				seg++;
			}
		}

		if(sum == 0 && seg > 1) return 1;
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

    while(cin >> n >> str)
    {
		if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
    }


}



