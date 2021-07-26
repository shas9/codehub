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

ll arr[1000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++) slld(arr[i]);

		ans = 0;

		for(i = 2; i <= n; i++)
		{
			if(arr[i - 1] == 1)
			{
				if(arr[i] == 3) ans += 4;
				else
				{
					ans += 3;

					if(i >= 3 && arr[i - 2] == 3) ans--;
				}
			}
			else if(arr[i - 1] == 2)
			{
				if(arr[i] == 3)
				{
					ans = -1;
					break;
				}
				else
				{
					ans += 3;
				}
			}
			else
			{
				if(arr[i] == 2)
				{
					ans = -1;
					break;
				}
				else
				{
					ans += 4;
				}
			}
		}

		if(ans == -1) cout << "Infinite" << '\n';
		else cout << "Finite" << '\n' << ans << '\n';
    }


}


