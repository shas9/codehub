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

ll arr[100005];
ll freq[10];

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

		memset(freq,0,sizeof freq);

		ll sum = 0;

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);

			arr[i] /= 100000000;

			sum += arr[i];

			freq[sum % 10]++;
		}

		sum = 0;
		ans = 0;

		for(i = 1; i <= n; i++)
		{
			ans += freq[sum];

			sum += arr[i];
			sum %= 10;

			freq[sum]--;
		}

		printf("%lld\n", ans);
    }


}


