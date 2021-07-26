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

vector < pll > vec;
ll track[300];

bool solve(ll n)
{
	memset(track, -1, sizeof track);

	for(auto it: vec)
	{
		if(it.first == -1 || it.second == -1) continue;

//		if(it.first > it.second) swap(it.first, it.second);

		if(it.first >= it.second) return 0;

		for(ll i = it.first; i <= it.second; i++)
		{
			if(track[i] != -1 && track[i] != it.second - it.first - 1) return 0;

			track[i] = it.second - it.first - 1;
		}
	}

	ll cnt = 500;

	while(cnt--)
	{
		for(auto &it: vec)
		{
			if(it.first == -1 && it.second == -1) continue;

			if(it.first == -1)
			{
				if(it.second == 1) return 0;

				if(track[it.second] != -1)
				{
					it.first = it.second - track[it.second] - 1;

					if(it.first < 1) return 0;

					for(ll i = it.first; i <= it.second; i++)
					{
						if(track[i] != -1 && track[i] != it.second - it.first - 1) return 0;
						track[i] = it.second - it.first - 1;
					}
				}
				else if(track[it.second - 1] != -1)
				{
					it.first = it.second - track[it.second - 1] - 1;

					if(it.first < 1) return 0;

					for(ll i = it.first; i <= it.second; i++)
					{
						if(track[i] != -1 && track[i] != it.second - it.first - 1) return 0;
						track[i] = it.second - it.first - 1;
					}
				}
			}
			else if(it.second == -1)
			{
				if(it.first == 2 * n) return 0;

				if(track[it.first] != -1)
				{
					it.second = it.first + track[it.first] + 1;

					if(it.second > 2 * n) return 0;

					for(ll i = it.first; i <= it.second; i++)
					{
						if(track[i] != -1 && track[i] != it.second - it.first - 1) return 0;
						track[i] = it.second - it.first - 1;
					}
				}
				else if(track[it.first + 1] != -1)
				{
					it.second = it.first + track[it.first + 1] + 1;

					if(it.second > 2 * n) return 0;

					for(ll i = it.first; i <= it.second; i++)
					{
						if(track[i] != -1 && track[i] != it.second - it.first - 1) return 0;
						track[i] = it.second - it.first - 1;
					}
				}
			}
		}
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.resize(n);

		for(pll &it: vec)
		{
			cin >> it.first >> it.second;
		}

		if(solve(n)) cout << "Yes\n";
		else cout << "No\n";
    }


}



