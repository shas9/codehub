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

string sign;
char eqn[100005];
ll arr[100005];
ll dp[100005];
ll dp_rb[100005];

void solve1(ll n) //onesign
{
	for(ll i = 1; i <= n; i++) eqn[i] = sign.front();
}

void solve2(ll n) //onlyplus
{
	for(ll i = 1; i <= n; i++) eqn[i] = '+';
}

void solve3(ll n) //noplus
{
	for(ll i = 1; i <= n; i++)
	{
		if(arr[i] == 0) eqn[i - 1] = '-';
		else eqn[i - 1] = '*';
	}
}

void calc(ll x, ll y)
{

	if(x > y) return;



	__int128 product = 1;

	for(ll i = x; i <= y; i++)
	{
		if(product >= (1e16)) break;

		product *= arr[i];
	}

	if(product >= (1e16))
	{
		for(ll i = x; i < y; i++) eqn[i] = '*';

		return;
	}


	dp[x - 1] = 0;
	dp_rb[x - 1] = -1;

	for(ll i = x; i <= y; i++)
	{
		if(arr[i] == 1)
		{
			dp[i] = dp[i - 1] + 1;
			dp_rb[i] = i - 1;
		}
		else
		{
			product = 1;
			for(ll j = i; j >= x; j--)
			{
				product *= arr[j];

				if(product + dp[j - 1] > dp[i])
				{
					dp[i] = product + dp[j - 1];
					dp_rb[i] = j - 1;
				}
			}
		}

//		cout << dp[i] << " " << dp_rb[i] << endl;
	}

	for(ll i = y; i >= x; i = dp_rb[i])
	{
		for(ll j = i - 1; j > dp_rb[i]; j--) eqn[j] = '*';

		if(dp_rb[i] >= 0) eqn[dp_rb[i]] = '+';
	}

	return;
}

void solve4(ll n)
{
	memset(dp,0,sizeof dp);
	memset(dp_rb,0,sizeof dp_rb);

	ll last = 1;

	for(ll i = 1; i <= n; i++)
	{
		if(arr[i] == 0)
		{
			calc(last, i - 1);

			eqn[i - 1] = eqn[i] = '+';

			last = i + 1;
		}
	}

	calc(last, n);
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
		for(ll i = 1; i <= n; i++) slld(arr[i]);

		cin >> sign;

		map < char, bool > mp;

		for(auto it: sign) mp[it] = 1;

		if(sign.size() == 1) solve1(n);
		else if(mp['*'] == 0) solve2(n);
		else if(mp['+'] == 0) solve3(n);
		else solve4(n);

		for(ll i = 1; i < n; i++)
		{
			cout << arr[i] << eqn[i];
		}

		cout << arr[n] << "\n";
	}


}
