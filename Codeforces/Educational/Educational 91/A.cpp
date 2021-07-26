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

ll arr[1004];

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

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		bool on = 0;
		ll a, b, c;

		for(ll i = 1; i  <= n; i++)
		{
			a = c = -1;

			for(ll j = 1; j < i; j++)
			{
				if(arr[j] < arr[i])
				{
					a = j;
					break;
				}
			}

			if(a == -1) continue;

			for(ll j = i + 1; j <= n; j++)
			{
				if(arr[j] < arr[i])
				{
					c = j;
					break;
				}
			}

			if(c == -1) continue;

			on = 1;

			b = i;
			break;
		}

		if(on == 0)
		{
			cout << "NO" << '\n';
			continue;
		}

		cout << "YES" << '\n';
		cout << a << " " << b << " " << c << '\n';
    }


}


