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

vector < ll > vec;
ll dp[13][(1 << 13)][25];

ll solve(ll pos, ll mask, ll leaf)
{
	ll &ret = dp[pos][mask][leaf];

	if(ret != -1) return ret;

	if(pos == vec.size())
	{
		if(!(mask || leaf)) return ret = 1;

		return ret = 0;
	}

	if(check(mask,pos)) return ret = 0;

	ret = 0;

	if(vec[pos] - 1 <= leaf && vec[pos] - 1 >= 2)
	{
		ret |= solve(pos + 1, mask, leaf - vec[pos] + 1);
	}

	if(ret == 1) return ret;

	for(ll submask = mask; submask; submask = (submask - 1) & mask)
	{
		ll totnode = 0, subtree = 0;

		for(ll i = pos + 1; i < vec.size(); i++)
		{
			if(check(submask,i))
			{
				totnode++;
				subtree += vec[i];
			}
		}

		ll forleaf = vec[pos] - subtree - 1;

		if(forleaf > leaf) continue;
		if(totnode + forleaf <= 1) continue;

		ret |= solve(pos + 1, mask ^ submask, leaf - forleaf);

		if(ret == 1) return ret;
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

    while(cin >> n)
    {
		vec.clear();
		memset(dp,-1,sizeof dp);

		ll leaf = 0;

		for(ll i = 1; i <= n; i++)
		{
			slld(input);

			if(input == 1) leaf++;
			else vec.push_back(input);
		}

		sort(vec.rbegin(),vec.rend());

		if(leaf < (n + 1) / 2)
		{
			printf("NO\n");
			continue;
		}

		if(n == 1)
		{
			if(leaf == 1) printf("YES\n");
			else printf("NO\n");
			continue;
		}

		ans = solve(0,((1 << vec.size()) - 1) ^ 1, leaf);

		if(ans == 1) printf("YES\n");
		else printf("NO\n");
    }


}



