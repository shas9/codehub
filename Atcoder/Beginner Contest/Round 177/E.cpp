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

const ll maxn  = 1000002;
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

ll arr[1000006];
ll freq[1000005];

bool pairwise(ll n)
{
	memset(freq,0,sizeof freq);

	for(ll i = 1; i <= n; i++)
	{
		ll x = arr[i];

		for(ll j = 0; primes[j] * primes[j] <= x; j++)
		{
			if(x % primes[j] == 0)
			{
				freq[primes[j]]++;

				while(x % primes[j] == 0) x /= primes[j];
			}
		}

		if(x > 1) freq[x]++;
	}

	for(ll i = 1; i <= 1000000; i++)
	{
		if(freq[i] > 1) return 0;
	}

	return 1;
}

bool setwise(ll n)
{
	ll gc = 0;

	for(ll i = 1; i <= n; i++) gc = __gcd(gc, arr[i]);

	return gc == 1;
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
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		if(pairwise(n)) cout << "pairwise coprime\n";
		else if(setwise(n)) cout << "setwise coprime\n";
		else cout << "not coprime\n";
    }


}




