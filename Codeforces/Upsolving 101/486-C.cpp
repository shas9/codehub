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

ll solve1(ll n, ll m)
{
	ll half = (n / 2);

	ll ret = 0;
	ll last = m;

	for(ll i = m; i <= half; i++)
	{
		if(str[i] != str[n - i + 1])
		{
			ret += min(abs(str[i] - str[n - i + 1]), min(str[i] + 26 - str[n - i + 1], str[n - i + 1] + 26 - str[i]));
			ret += (i - last);
			last = i;
		}
	}

	for(ll i = last - 1; i >= 1; i--)
	{
		if(i < m)
		{
			if(str[i] != str[n - i + 1])
			{
				ret += min(abs(str[i] - str[n - i + 1]), min(str[i] + 26 - str[n - i + 1], str[n - i + 1] + 26 - str[i]));
				ret += last - i;
				last = i;
			}
		}
	}

//	cout << ret << " ";

	return ret;
}

ll solve2(ll n, ll m)
{
	ll half = (n / 2);

	ll ret = 0;
	ll last = m;

	map < ll, bool > mp;

	for(ll i = m; i <= n;i++)
	{
		if(str[i] != str[n - i + 1] && mp[i] == 0)
		{
			mp[i] = 1;
			mp[n - i + 1] = 1;
			ret += min(abs(str[i] - str[n - i + 1]), min(str[i] + 26 - str[n - i + 1], str[n - i + 1] + 26 - str[i]));
			ret += i - last;
			last = i;
		}
	}

//	cout << ret << " ";

	return ret;
}

ll solve3(ll n, ll m)
{
	ll half = (n / 2);

	ll ret = 0;
	ll last = m;

	for(ll i = last; i >= 1; i--)
	{
		if(str[i] != str[n - i + 1])
		{
			ret += min(abs(str[i] - str[n - i + 1]), min(str[i] + 26 - str[n - i + 1], str[n - i + 1] + 26 - str[i]));
			ret += last - i;
			last = i;
		}
	}

	for(ll i = last + 1; i <= half; i++)
	{
		if(str[i] != str[n - i + 1] && i > m)
		{
			ret += min(abs(str[i] - str[n - i + 1]), min(str[i] + 26 - str[n - i + 1], str[n - i + 1] + 26 - str[i]));
			ret += (i - last);
			last = i;
		}
	}

//	cout << ret << " ";

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		cin >> str;

		if(n == 1)
		{
			cout << 0 << "\n";
			continue;
		}

		ll half = (n / 2);

		if(m > half)
		{
			reverse(str.begin(), str.end());
			m = (n - m + 1);
		}

		str.insert(str.begin(), '0');

		ans = min(solve1(n,m), min(solve2(n,m), solve3(n,m)));

		cout << ans << "\n";
    }


}


