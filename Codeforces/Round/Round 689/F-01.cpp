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
map < ll, bool > mp;
string out;
vector < ll > v;
vector < ll > dp;
vector < ll > dp_prv;

void solve1()
{
	for(ll i = 0; i < v.size(); i++)
	{
		if(i) out += str.front();

		out += v[i] + '0';
	}

	return;
}

void solve2()
{
	for(ll i = 0; i < v.size(); i++)
	{
		if(i) out += str.front();

		out += v[i] + '0';
	}

	return;
}

void solve3()
{
	bool on = 0;

	for(ll i = 0; i < v.size(); i++)
	{
		if(i)
		{
			if(v[i] == 0) out += '-';
			else out += '*';
		}

		out += v[i] + '0';
	}
}

void calc(ll l, ll r)
{
	if(l > r) return;

//	cout << l << " " << r << " " << out.size() << endl;
	bool on = 0;

	while(v[l] == 1 && l <= r)
	{
		out += "1+";
		l++;
		on = 1;
	}

//	cout << out.size() << endl;

	if(on) out.pop_back();

	ll y = r;

	while(v[y] == 1 && l <= y)
	{
		y--;
	}

//	cout << "DEBUG 1: " << l << " " << y << " " << out.size() << endl;

	// main

	__int128 product = 1;

	for(ll i = l; i <= y; i++)
	{
		product *= v[i];

		if(product >= 1e10) break;
	}

	string ret;

	if(product < 1e10 && l <= y)
	{
//		bug;
		if(l) dp[l - 1] = 0;

		for(ll i = l; i <= y; i++)
		{
			if(v[i] == 1)
			{
				dp[i] =  (i ? dp[i - 1] : 0) + 1;
				dp_prv[i] = i - 1;
				continue;
			}

			product = 1;

			for(ll j = i; j >= l; j--)
			{
				product *= v[j];

				ll x = product + (j ? dp[j - 1] : 0);

//				cout << i << " " << j << " " << x << endl;

				if(x > dp[i])
				{
					dp[i] = x;
					dp_prv[i] = j - 1;

//					bug;
				}
			}
		}

		ret.resize(y - l);


		for(ll i = y; i >= l; i = dp_prv[i])
		{
			for(ll j = i - 1; j > dp_prv[i]; j--)
			{
				ret[j - l] = '*';
			}

			if(dp_prv[i] >= l) ret[dp_prv[i] - l] = '+';
		}

		if(!out.empty() && out.back() != '+') out += '+';

		for(ll i = 0; i < ret.size(); i++)
		{
//			cout << i << " is " << l + i << " " << out.size() << endl;
			out += v[l + i] + '0';
//			bug;

			out += ret[i];

//			bug;
		}


		out += v[y] + '0';
	}
	else
	{
		for(ll i = l; i <= y; i++)
		{
			if(i != l) out += '*';

			out += v[i] + '0';
		}
	}

	// end


	for(ll i = y + 1; i <= r; i++)
	{
		out += "+1";
	}

	return;
}

void solve()
{
	ll last = 0;

	for(ll i = 0; i < v.size(); i++)
	{
		if(v[i] == 0)
		{
			calc(last, i - 1);

			if(i) out += '+';

			out += '0';

			if(i + 1 < v.size()) out += '+';

			last = i + 1;
		}
	}

	calc(last, v.size() - 1);
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
		mp.clear();
		dp.assign(n + 1, 0);
		dp_prv.assign(n + 1, -1);
		v.resize(n);

		for(auto &it: v) cin >> it;

		cin >> str;

		out = "";

		for(auto it: str)
		{
			if(it == '+') mp[0] = 1;
			if(it == '-') mp[1] = 1;
			if(it == '*') mp[2] = 1;
		}

		if(str.size() == 1) solve1();
		else if(mp[2] == 0) solve2();
		else if(mp[0] == 0) solve3();
		else solve();

		cout << out << "\n";
    }


}



