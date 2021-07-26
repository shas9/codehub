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


const ll maxn  = 100002;
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

ll arr[100005];
ll freq[100005];

ll solve(ll num)
{
	ll n = num;
	ll mx = 0;

	for(auto it: primes)
	{
		if(it * it > n) break;

		if(n % it) continue;

		mx = max(mx, freq[it]);

		while(n % it == 0)
		{
			n /= it;
		}
	}

	if(n > 1)
	{
		mx = max(mx, freq[n]);
	}

	n = num;

	for(auto it: primes)
	{
		if(it * it > n) break;

		if(n % it) continue;

		freq[it] = mx + 1;

		while(n % it == 0)
		{
			n /= it;
		}
	}

	if(n > 1)
	{
		freq[n] = mx + 1;
	}

	return mx + 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    sieve();

    while(cin >> n)
    {
		memset(freq,0,sizeof freq);

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			ans = max(ans,solve(arr[i]));
		}

		cout << ans << endl;
    }


}


