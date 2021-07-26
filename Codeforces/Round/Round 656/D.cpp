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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll freq[20][150000];
string str;
ll dp[150000][20];
ll n;
ll last;
ll len[30];

ll solve(ll pos, ll c)
{
	ll &ret = dp[pos][c];

	if(ret != -1) return ret;

	ret = 0;

	if(c == last - 1)
	{
		if(str[pos - 1] == c + 'a')
		{
			return ret = 0;
		}
		else return ret = 1;
	}

	ret = solve(pos + len[c],c + 1) + len[c] - (freq[c][pos + len[c] - 1] - freq[c][pos - 1]);
	ret = min(ret, solve(pos, c + 1) + len[c] - (freq[c][pos + len[c] + len[c] - 1] - freq[c][pos + len[c] - 1]));

//	cout << "Cost: " << pos << " " << c << " " <<  len[c] - (freq[c][pos + len[c] - 1] - freq[c][pos - 1]) << " vs " <<  len[c] - (freq[c][pos + len[c] + len[c] - 1] - freq[c][pos + len[c] - 1]) << endl;

	return ret;
}


int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		cin >> str;

		for(ll i = 0; i < 20; i++)
			for(ll j = 0; j <= n; j++)
			{
				dp[j][i] = -1;
				freq[i][j] = 0;
			}

		for(ll i = 0; i < n; i++)
		{
			if(str[i] - 'a' > 19) continue;

			freq[str[i] - 'a'][i + 1] = 1;
		}

		for(ll i = 0; i < 20; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				freq[i][j] += freq[i][j - 1];
			}
		}

		last = 0;
		ll _n = n;

		while(_n)
		{
			len[last] = _n / 2;
			last += 1;
			_n /= 2;

		}


		ans = solve(1,0);

		printf("%lld\n", ans);
    }


}



