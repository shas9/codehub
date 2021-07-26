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

const ll maxn  = 20000000;
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

bool is_it(ll n)
{
	ll x = sqrt(n);

	return x * x == n;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;


//    freopen("subtask_3_in_random.txt", "r", stdin);
//
//    freopen("subtask_3_out_random.txt", "w", stdout);

	sieve();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(input);

		assert(1 <= input && input <= 100000000000000);

		input *= 2;

		ans = 1;

		bool perfect_square = is_it(input);

		for(ll i = 0; primes[i] * primes[i] <= input; i++)
		{
			if(input % primes[i] == 0)
			{
				ll cnt = 0;

				while(input % primes[i] == 0)
				{
					cnt++;

					input /= primes[i];
				}

				ans = (ans * (cnt + 1));

//				cout << primes[i] << " " << cnt << endl;
			}
		}

		if(input > 1) ans = (ans * 2);

		if(perfect_square) ans++;

		ans /= 2;

		printf("%lld\n", ans);
    }


}



