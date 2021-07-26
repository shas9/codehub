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

ll arr[10000];
ll freq[10000];

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
		ans = 0;

		slld(n);

		for(i = 0; i <= n + n; i++) freq[i] = 0;

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
			freq[arr[i]]++;
		}

		for(i = 1; i <= n; i++)
		{
			ll sum = 0;

			for(j = i; j <= n; j++)
			{
				sum += arr[j];

				if(j == i) continue;

				if(sum > n) continue;
				assert(sum);

				ans += freq[sum];
				freq[sum] = 0;
			}
		}

		printf("%lld\n", ans);
    }


}


