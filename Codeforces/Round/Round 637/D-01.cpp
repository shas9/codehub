
// God put a smile upon your face <3

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

ll dp[2003][2003];
pll change[2003][11];
ll ans[2003];
ll arr[2003];
ll bits[11];
ll n, k;
string ss[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

void precalc()
{
	for(ll i = 0; i <= 9; i++)
	{
		for(ll j = 0; j < 7; j++)
		{
			if(ss[i][j] == '1')
			{
				bits[i] += (1 << j);
			}
		}
	}
}

ll solve(ll pos, ll rem)
{
	if(pos > n)
	{
		return rem == 0;
	}

	ll &ret = dp[pos][rem];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 9; i >= 0; i--)
	{
		if(change[pos][i].first > rem) continue;

		if(solve(pos + 1, rem - change[pos][i].first))
		{
			ans[pos] = change[pos][i].second;
			return ret = 1;
		}
	}

	return ret;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	precalc();

    while(cin >> n >> k)
    {
		string str;

		for(i = 1; i <= n; i++)
		{
			cin >> str;

			ll num = 0;

			for(j= 0; j < 7; j++)
			{
				if(str[j] = '1') num += (1 << j);
			}
		}

		memset(dp,-1,sizeof dp);
		memset(change,0,sizeof change);

		for(i = 1; i <= n; i++)
		{
			for(j = 0; j < 10; j++)
			{
				for(ll m = 0; m < 7; m++)
				{
					if(check(arr[i],m) && check(bits[j],m) == 0)
					{
						change[i][j] = {mxlld,j};
						break;
					}

					if(check(arr[i],m) == 0 && check(bits[j],m))
					{
						change[i][j] = {change[i][j].first + 1, j};
					}
				}
			}

//			sort(change[i], change[i] + 10);
		}

		if(solve(1,k) == 0) printf("-1\n");
		else
		{
			for(i = 1; i <= n; i++) printf("%lld", ans[i]);

			printf("\n");
		}
    }

}


