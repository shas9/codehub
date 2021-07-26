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

string solve(ll x)
{
	string ret;

	for(ll i = 0; i < str.size(); i++) ret += "2";

	for(ll i = 0; i < str.size(); i++)
	{
		if(i >= x)
		{
			if(ret[i - x] == '2')
			{
				ret[i - x] = str[i];
			}

			if(ret[i - x] == str[i])
			{
				if(str[i] == '0')
				{
					if(i + x < str.size()) ret[i + x] = '0';
				}

				continue;
			}

			if(str[i] == '0' && ret[i - x] != '0')
			{
				ret = "-1";
				return ret;
			}
		}

		if(i + x < str.size())
		{
			assert(ret[i + x] == '2');

			ret[i + x] = str[i];
		}
	}

	for(ll i = 0; i < str.size(); i++)
	{
		if(str[i] == '0')
		{
			if(i - x >= 0) if(ret[i - x] != '0') return "-1";
			if(i + x < str.size()) if(ret[i + x] != '0') return "-1";
		}
		else
		{
			if(i - x >= 0) if(ret[i - x] == '1') continue;
			if(i + x < str.size()) if(ret[i + x] == '1') continue;

			return "-1";
		}
	}

	for(auto &it: ret) if(it == '2') it = '0';
	return ret;
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
		cin >> str >> n;

		cout << solve(n) << "\n";
    }


}




