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

ll dp[300005][2][2];

map < pll, bool > mp;

string str;

ll solve(ll node, ll dir, ll state)
{
	if(node < 0) return 0;
	if(node > str.size()) return 0;

	ll &ret = dp[node][dir][state];

	if(ret != -1) return ret;

	ret = 0;

	if(dir == 0)
	{
		if(state)
		{
			if(mp.find({node, node - 1}) == mp.end()) ret = solve(node - 1, dir, state ^ 1);
		}
		else
		{
			if(mp.find({node, node - 1}) != mp.end()) ret = solve(node - 1, dir, state ^ 1);
		}
	}
	else
	{
		if(state)
		{
			if(mp.find({node, node + 1}) == mp.end()) ret = solve(node + 1, dir, state ^ 1);
		}
		else
		{
			if(mp.find({node, node + 1}) != mp.end()) ret = solve(node + 1, dir, state ^ 1);
		}
	}

	return ret = ret + 1;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		mp.clear();

		cin >> n >> str;

		for(ll i = 1; i <= n; i++)
		{
			if(str[i - 1] == 'L')
			{
				mp[{i,i - 1}] = 1;
			}
			else
			{
				mp[{i - 1, i}] = 1;
			}
		}

		for(ll i = 0; i <= n; i++) for(ll j = 0; j < 2; j++) for(ll k = 0; k < 2; k++) dp[i][j][k] = -1;

		for(ll i = 0; i <= n; i++)
		{
//			if(i == 5) cout << i << ": " << solve(i,0,0) << " " << solve(i,1,0) << endl;

			cout << solve(i, 0, 0) + solve(i, 1, 0) - 1 << " ";
		}

		cout << "\n";
    }


}




