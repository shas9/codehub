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

void brute(ll n)
{
	ll arr[n + 4] = {0};

	ll cnt = 0;
	for(ll idx = 1; idx <= n; idx++)
	{
		if(arr[idx]) continue;

		cnt++;

		for(ll i = 1; i <= n; i++)
		{
			if(n % i) continue;

			for(ll j = idx; j <= n; j += i)
			{
				arr[j] = cnt;
			}
		}
	}
}

const ll maxn  = 6000000;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	sieve();

    while(cin >> n)
    {
		if(n == 1)
		{
			printf("1\n");
			continue;
		}

		vector < ll > d;

		for(i = 0; i < primes.size() && primes[i] * primes[i] <= n ; i++)
		{
			if(n % primes[i]) continue;

			d.push_back(primes[i]);

			while(n % primes[i] == 0) n /= primes[i];
		}

		if(n > 1) d.push_back(n);

		sort(d.begin(),d.end());

		ans = d.back();

		if(d.size() > 1) ans = 1;

		printf("%lld\n", ans);
    }


}




