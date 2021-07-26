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

string str[4];

ll dp[200005][2][2];

ll solve(ll n = str[0].size())
{
	memset(dp,0,sizeof dp);

	for(ll i = 0; i < n; i++)
	{
		if(str[0][i] != str[1][i]) dp[i][0][0] = dp[i][1][0] = 1;
		if(str[0][i] != str[2][i]) dp[i][0][1] = dp[i][1][1] = 1;
	}

	for(ll i = 1; i < n; i++)
	{
		dp[i][0][0] += dp[i - 1][0][0];
		dp[i][0][1] += dp[i - 1][0][1];
	}

	for(ll i = n - 1; i >= 0; i--)
	{
		dp[i][1][0] += dp[i + 1][1][0];
		dp[i][1][1] += dp[i + 1][1][1];
	}

	ll ret = 0;

	str[3] = "";

	for(ll i = 0; i < n; i++)
	{
		ll first = dp[i][0][0] + dp[i + 1][1][0];
		ll second = dp[i][0][1] + dp[i + 1][1][1];

//		cout << i << " " << first << " " << second << endl;

		if(first == 0 && second == 0) return 4;
		if(first <= 1 && second <= 1)
		{
			ret++;

			if(ret == 1)
			{
				str[3] = str[0];
			}
		}

		if(first <= 2 && second <= 1 && str[0][i] != str[1][i])
		{
			ret++;

			if(ret == 1)
			{
				str[3] = str[0];
				str[3][i] = str[1][i];
			}
		}

		if(first <= 1 && second <= 2 && str[0][i] != str[2][i])
		{
			ret++;

			if(ret == 1)
			{
				str[3] = str[0];
				str[3][i] = str[2][i];
			}
		}

		if(first <= 2 && second <= 2 && str[1][i] == str[2][i] && str[1][i] != str[0][i])
		{
			ret++;

			if(ret == 1)
			{
				str[3] = str[0];
				str[3][i] = str[2][i];
			}
		}
	}

	return ret;
}

ll solve1(ll n = str[0].size())
{
	ll ret = 0, first = 0, second = 0;

	for(ll i = 0; i < n; i++)
	{
		if(str[0][i] != str[1][i]) first++;
		if(str[0][i] != str[2][i]) second++;
	}

	if(first == second && first == 0) return 4;

	if(first == 1 && second == 1)
	{

		str[3] = str[0];
		return 1;
	}

	for(ll i = 0; i < n; i++)
	{
		if(str[1][i] == str[0][i] && str[2][i] == str[0][i])
		{
			continue;
		}

		if(str[1][i] == str[2][i])
		{
			if(first <= 2 && second <= 2)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];
					str[3][i] = str[1][i];
				}
			}
		}
		else if(str[1][i] == str[0][i])
		{
			if(first <= 1 && second <= 2)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];
					str[3][i] = str[2][i];
				}
			}
		}
		else if(str[2][i] == str[0][i])
		{
			if(first <= 2 && second <= 1)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];
					str[3][i] = str[1][i];
				}
			}
		}
		else
		{
			if(first == 2 && second == 1)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];
					str[3][i] = str[1][i];
				}
			}
			else if(first == 1 && second == 2)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];

					str[3][i] = str[2][i];
				}
			}
		}

//		cout << str[3] << endl;
	}

	return ret;
}

ll solve2(ll n = str[0].size())
{
	ll ret = 0;

	str[3] = "";

	ll first = 0, second = 0;

	for(ll i = 0; i < n; i++)
	{
		if(str[0][i] != str[1][i]) first++;
		if(str[0][i] != str[2][i]) second++;
	}

	if(first == 0 && second == 0) return 2;

	if(first == 1 && second == 1)
	{
		ret = 1;
		str[3] = str[0];
	}

	for(ll i = 0; i < n; i++)
	{
		ll tf = first;
		ll ts = second;

		if(str[0][i] != str[1][i]) tf--;
		if(str[0][i] != str[2][i]) ts--;

		if(tf == 0 && ts == 0) return 5;

		if(str[2][i] == str[1][i] && str[0][i] != str[1][i])
		{
			if(tf <= 1 && ts <= 1)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];
					str[3][i] = str[2][i];
				}
			}

			continue;
		}

		if(str[2][i] != str[0][i])
		{
			if(tf == 0 && ts <= 1)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];
					str[3][i] = str[2][i];
				}
			}
		}

		if(str[1][i] != str[0][i])
		{
			if(tf == 1 && ts == 0)
			{
				ret++;

				if(ret == 1)
				{
					str[3] = str[0];
					str[3][i] = str[1][i];
				}
			}
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

    while(cin >> str[0] >> str[1] >> str[2])
    {
		ans = solve2();

		if(ans == 0) cout << "Impossible\n";
		else if(ans == 1) cout << str[3] << "\n";
		else cout << "Ambiguous\n";
    }


}



