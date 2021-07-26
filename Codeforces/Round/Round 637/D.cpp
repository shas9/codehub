
// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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
ll ans[2003];
string mask[2003];
string num[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

ll n, k;

ll solve(ll pos, ll rem)
{
	if(rem < 0) return 0;

	if(pos > n)
	{
		return rem == 0;
	}

	ll &ret = dp[pos][rem];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 9; i >= 0; i--)
	{
		ll change = 0;

		for(ll j = 0; j < 7; j++)
		{
			if(mask[pos][j] == '1' && num[i][j] == '0')
			{
				change = -1;
				break;
			}

			if(mask[pos][j] == '0' && num[i][j] == '1') change++;
		}

//		cout << pos << " " << i << " " << rem << " " << mask[pos] << " " << num[i] << " " << change << endl;

		if(change == -1) continue;

		if(change > rem) continue;

		if(solve(pos + 1, rem - change))
		{
			ans[pos] = i;
			return  ret = 1;
		}
	}

	return ret;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(i = 1; i <= n; i++)
		{
			cin >> mask[i];
		}

		memset(dp,-1,sizeof dp);

		if(solve(1,k) == 0) printf("-1\n");
		else
		{
			for(i = 1; i <= n; i++)
			{
				printf("%d", ans[i]);
			}

			printf("\n");
		}
    }


}


