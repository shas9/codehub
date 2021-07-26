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

ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		ll zero = 0;

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);
			zero += arr[i] == 1;
		}

		for(ll i = 1; i <= m; i++)
		{
			cin >> flag;
			cin >> input;

			if(flag == 1)
			{
				arr[input] = 1 - arr[input];

				if(arr[input] == 1) zero++;
				else zero--;
			}
			else
			{
				if(zero < input) cout << 0 << "\n";
				else cout << 1 << "\n";
			}
		}
    }


}


