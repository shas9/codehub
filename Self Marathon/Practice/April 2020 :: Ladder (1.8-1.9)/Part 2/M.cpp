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

#define mod 999998683

#define base 3323

//#define base 10

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll basei[1000006];
ll hasht[1000006];
char str[1000006];
vector < ll > ps;

ll mul(ll a, ll b)
{
	return ((a % mod) * (b % mod)) % mod;
}

ll hsh(ll l, ll r)
{
	return (hasht[r] - hasht[l - 1] + mod) % mod;
}

bool solve(ll len, ll n)
{
	ll bhash = hsh(1,len);

	for(ll i = 2; i + len - 1 < n; i++)
	{
		ll chash = hsh(i, i + len - 1);

		if(mul(bhash,basei[i - 1]) == chash) return 1;
	}

	return 0;
}
ll bs(ll n)
{
	ll lo = 0;
	ll hi = ps.size() - 1;
	ll ret = -1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(solve(ps[mid], n))
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	basei[0] = 1;

	for(i = 1; i <= 1000000; i++)
	{
		basei[i] = mul(basei[i - 1], base);
	}

    while(scanf("%s", str + 1) != EOF)
    {
		n = strlen(str + 1);

		for(i = 1; i <= n; i++)
		{
			hasht[i] = mul(str[i], basei[i]);

			hasht[i] = (hasht[i] + hasht[i - 1]) % mod;

//			cout << hasht[i] << " ~~ ";
		}

//		cout << endl;

		ps.clear();

		for(i = 1; i < n; i++)
		{
//			cout << i << " " << mul(hsh(1,i),basei[n-i]) << " " << hsh(n - i + 1, n) << endl;

			if(mul(hsh(1,i),basei[n-i]) == hsh(n - i + 1, n))
			{
//				cout << 1 << " " << i << " && " << n - i + 1 << " " << n << endl;
				ps.push_back(i);
			}
		}

//		for(auto it: ps) cout << it << " ";
//
//		cout << endl;

		ans = bs(n);

		if(ans == -1) printf("Just a legend\n");
		else
		{
			ans = ps[ans];
			for(i = 1; i <= ans; i++) printf("%c", str[i]);

			printf("\n");
		}
    }


}

