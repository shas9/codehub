
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

string str, prnt;

bool inc(ll idx)
{
	ll num = str[idx] - '0';

	if(num == 9)
	{
		str[idx] = '0';
		return 1;
	}

	num++;

	str[idx] = (char)(num + '0');

	return 0;
}

void solve(ll n, ll m)
{
	n = str.size();

	bool hand = 0;
	bool dot = 0;
	ll lim = n -1;

	for(ll i = 0; i < n; i++)
	{
		if(str[i] == '.') dot = 1;

		if(dot && str[i] >= '5')
		{
			lim = i;

			for(ll j = i; j >= 0; j--)
			{
				if(str[j] == '.')
				{
					dot = 0;
					continue;
				}

				if(dot == 0)
				{
					if(hand) hand = inc(j);

					continue;
				}

				if(hand)
				{
					hand = inc(j);
				}

				if(str[j] >= '5' && m)
				{
					hand = 1;
					str[j] = '0';
					m--;
				}
			}

			break;
		}
	}

	prnt = "";

	for(ll i = lim; i >= 0; i--)
	{
		if(prnt.empty() && str[i] == '0') continue;

		prnt += str[i];
	}

	if(hand) prnt += '1';

	reverse(prnt.begin(), prnt.end());

	if(prnt.back() == '.') prnt.pop_back();

	return;
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

		solve(n,m);

		cout << prnt << "\n";
	}


}


