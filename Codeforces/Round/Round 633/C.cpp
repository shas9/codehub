#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


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
ll pw[70];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	pw[0] = 1;
	for(ll i = 1; i <= 62; i++)
	{
		pw[i] = pw[i - 1] * 2;
	}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 1; i <= n; i++) slld(arr[i]);
		ans = 0;
		for(i = 2; i <= n; i++)
		{
			ll diff = arr[i] - arr[i - 1];

			if(diff >= 0) continue;

			diff *= -1;

			for(j = 62; j >= 0; j--)
			{
				if(check(diff,j)) break;
			}

			ans = max(ans,j + 1);

			arr[i] = arr[i - 1];
		}

		cout << ans << endl;
    }


}



