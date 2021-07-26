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

string s;
ll a, b;

ll solve()
{
	ll ret = 0;

	ll ptr = 0;

	bool start = 0;
	ll gap = 0;

	while(ptr < s.size())
	{
		if(s[ptr] == '1')
		{
			if(start == 0)
			{
				start = 1;
				ret += a;
			}
			else
			{
				ll cost = gap * b;

				if(cost < a) ret += cost;
				else ret += a;
			}

			while(ptr < s.size() && s[ptr] == '1') ptr++;

			gap = 0;
		}
		else
		{
			gap++;
			ptr++;
		}
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> a >> b >> s;

		ans = solve();

		cout << ans << "\n";
    }


}



