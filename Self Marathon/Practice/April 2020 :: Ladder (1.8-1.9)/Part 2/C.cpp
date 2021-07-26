#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll lcmm(ll a, ll b)
{
	return a * b / __gcd(a,b);
}

ll lcm(ll x, ll y, ll z)
{
	return lcmm(x,lcmm(y,z));
}

const ll maxn  = 1000002;
//vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
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
//
//    for(ll i = 2; i <= maxn; i++)
//    {
//        if(vis[i] == false)
////        primes.pb(i);
//    }

}

ll brute(ll n)
{
	ll ret = 0;

	ll x, y, z;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= n; j++)
		{
			for(ll k = 1; k <= n; k++)
			{
				ll llcm = lcm(i,j,k);
				ret = max(ret, llcm);

				if(llcm == ret)
				{
					x = i;
					y = j;
					z = k;
				}

//				if(ret == llcm) cout << i << " " << j << " " << k << " " << ret << endl;
			}
		}
	}

//	if(n == 12)
//	cout << x << " ~~ " << y << " ~~ " << z << endl;
	return ret;
}

ll solve(ll n)
{
	ll ret = 0;

	ll x, y, z;

	for(ll i = max(1LL,n - 50); i <= n; i++)
	{

		for(ll j = max(1LL,n - 50); j <= n; j++)
		{
			for(ll k = max(1LL,n - 50); k <= n; k++)
			{
				ll llcm = lcm(i,j,k);
				ret = max(ret, llcm);

				if(llcm == ret)
				{
					x = i;
					y = j;
					z = k;
				}

//				if(ret == llcm) cout << i << " " << j << " " << k << " " << ret << endl;
			}
		}
	}

//	if(n == 12)
//	cout << x << " ~~ " << y << " ~~ " << z << endl;
	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n)
	{
		cout << solve(n) << "\n";
	}

//    bug;


}


