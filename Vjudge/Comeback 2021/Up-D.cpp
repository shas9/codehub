 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

vector < ll > v1;
map < ll, ll > mp, mp2;

void brute()
{
	ll cnt = 0;

	for(ll i = 1000000, j = 1; i >= 1 && j <= 300000; i--, j++)
	{
		cnt += sqrt(i) + 1;
	}

	cout << cnt << "\n";
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	brute();

	fastio;
	sieve();
	mp2.clear();

    cin >> testcase;
    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		v1.resize(n);
		mp.clear();

		for(auto &it: v1) cin >> it;

		for(auto it: v1)
		{
			if(mp2.find(it) != mp2.end())
			{
				mp[mp2[it]]++;
				continue;
			}

			ll x = it;

			ll num = 1;
			for(ll j = 0; primes[j] * primes[j] <= it; j++)
			{
				ll cnt = 0;

				while(it % primes[j] == 0)
				{
					it /= primes[j];
					cnt++;
				}

				if(cnt & 1) num *= primes[j];
			}

			if(it != 1) num *= it;

			mp[num]++;
			mp2[x] = num;
		}

		ll ans1 = 0, ans2 = 0;

		for(auto it: mp)
		{
			ans1 = max(ans1, it.second);
		}

		for(auto &it: mp)
		{
			if(it.second % 2 == 0 && it.first != 1)
			{
				mp[1] += it.second;
				it.second = 0;
			}
		}

		for(auto it: mp)
		{
			ans2 = max(ans2, it.second);
		}

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			long long inn;
			cin >> inn;

			if(inn == 0) cout << ans1 << "\n";
			else cout << ans2 << "\n";
		}
    }


}


