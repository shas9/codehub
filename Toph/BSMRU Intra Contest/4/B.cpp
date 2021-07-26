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

void test(ll n)
{
	pll ans = {-1,-1};

	for(ll i = 1; i <= 1000; i++)
	{
		for(ll j = 1; j <= 1000; j++)
		{
			if(i + j == n)
			{
				if(__gcd(i,j) + ((i * j) / __gcd(i,j)) == n)
				{
					if(ans.first == -1)
					{
						ans = {i,j};
					}
					else
					{
						if(abs(i-j) < abs(ans.first - ans.second))
						{
							ans = {i,j};
						}
					}
				}
			}
		}
	}

	if(ans.first == -1) cout << -1 << endl;
	else cout << ans.first << " " << ans.second << endl;
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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(cin >> n)
//	{
//		test(n);
//	}

    slld(testcase);

    sieve();

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

//		test(n);
		if(!(n & 1)) cout << n / 2 << " " << n / 2 << "\n";
		else if(n == 1) printf("-1\n");
		else
		{
			vector < ll > div;

			m = n;

			for(ll i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
			{
				ll x = primes[i];

				while(n % x == 0)
				{
					div.pb(x);
					div.pb(n / x);

					x *= primes[i];
				}
			}

//			for(auto it: div) cout << it << " ";

//			cout << endl;

			if(n > 1) div.push_back(n);

			n = m;

			if(div.size() == 1 && div.back() == n) cout << 1 << " " << n - 1 << "\n";
			else
			{
				pll ret = {-1,-1};

				for(auto it: div)
				{
					ll jt = n - it;
					ll g = __gcd(it,jt);

					if(g + (it * jt / g) == n)
					{
						if(ret.first == -1) ret = {it,jt};
						else
						{
							if(abs(it-jt) < abs(ret.first - ret.second)) ret = {it,jt};
						}
					}
				}

				if(ret.first == -1) cout << -1 << "\n";
				else cout << ret.first << " " << ret.second << "\n";
			}
		}
    }


}



