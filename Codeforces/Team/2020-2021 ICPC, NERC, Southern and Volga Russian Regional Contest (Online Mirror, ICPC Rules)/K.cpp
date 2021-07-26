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

string str;

pll dfs(ll nx, ll ny, ll pos, ll px, ll py)
{
	if(pos == str.size())
	{
		if(nx == 0 && ny == 0)
		{
			return {px, py};
		}
		else
		{
			return {mxlld,mxlld};
		}
	}

	ll nxx = nx;
	ll nyy = ny;

	if(str[pos] == 'U') nyy++;
	if(str[pos] == 'D') nyy--;
	if(str[pos] == 'L') nxx--;
	if(str[pos] == 'R') nxx++;

	pll ret;

	if(px == 0 && py == 0)
	{
		if(nxx != 0 || nyy != 0)
		{
			ret = dfs(nx, ny, pos + 1, nxx, nyy);


			if(ret.first != mxlld) return ret;
		}

		ret = dfs(nxx, nyy, pos + 1, px, py);

		if(ret.first != mxlld) return ret;
	}
	else
	{
		if(nxx == px && nyy == py)
		{
			ret = dfs(nx, ny, pos + 1, px, py);

			if(ret.first != mxlld) return ret;
		}
		else
		{
			ret = dfs(nxx, nyy, pos + 1, px, py);

			if(ret.first != mxlld) return ret;
		}
	}

	return {mxlld, mxlld};
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
		cin >> str;

		pll ans = dfs(0, 0, 0, 0, 0);

		if(ans.first == 0 && ans.second == 0) assert(0);

		if(ans.first == mxlld) ans = {0,0};

		cout << ans.first << " " << ans.second << "\n";



    }


}


