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
ll n;
ll freq[100005];

void test()
{
	memset(freq,0,sizeof freq);

	ll tm = 0;
	ll now = 1;

	cout << 1;
	while(now != (n + 1))
	{
		freq[now]++;
		tm++;

		if(freq[now] & 1) now = arr[now];
		else now = now + 1;

		cout << " -> " << now;
	}

	cout << tm << endl;

	for(ll i = 1; i <= n; i++)
	{
		cout << freq[i] << " ";
	}

	cout << endl;
}

ll dp[1000000];
const ll mod = 1000000007;

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		dp[1] = 1;

		for(ll i = 1; i <= n; i++)
		{
			dp[i + 1] = (2 * dp[i] - dp[arr[i]] + 2) % mod;
		}

		cout << ((dp[n + 1] - 1) % mod + mod) % mod << endl;
    }


}



