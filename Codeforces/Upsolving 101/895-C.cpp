// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

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

#define mod 1000000007

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

ll freq[2][100];
ll dp[71][1 << 19];
ll emask[100];

const ll maxn  = 100;
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

//    cout << primes[18] << " " << primes[19] << endl;
    for(ll i = 1; i <= 70; i++)
    {
        ll num = i;

        for(ll j = 0; primes[j] <= num && j < 19; j++)
        {
			if(num % primes[j] == 0)
			{
				ll cnt = 0;

				ll x = primes[j];

				while(num % x == 0)
				{
					x *= primes[j];
					cnt++;
				}

				if(cnt & 1) emask[i] = Set(emask[i],j);
			}
        }
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
        memset(dp,0,sizeof dp);
        memset(freq,0,sizeof freq);

        for(i = 1; i <= 70; i++) freq[0][i] = 1;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            ll x = freq[0][input] + freq[1][input];

            freq[0][input] = freq[1][input] = x % mod;
        }

        dp[0][0] = 1;

        for(i = 1; i <= 70; i++)
        {
            for(ll mask = 0; mask < (1 << 19); mask++)
            {
				dp[i][mask] = ((dp[i - 1][mask] * 1LL * freq[0][i]) % mod + (dp[i - 1][mask ^ emask[i]] * 1LL * freq[1][i]) % mod) % mod;
            }
		}

		printf("%d\n", (dp[70][0] - 1 + mod) % mod);
    }


}


