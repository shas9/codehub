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

vector < ll > ev, od;

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
		cin >> n;
		ev.clear();
		od.clear();

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;

			if(input & 1) od.push_back(input);
			else ev.push_back(input);
		}

		sort(od.begin(),od.end());
		sort(ev.begin(),ev.end());

		ll a = 0, b = 0;

		for(ll i = 1; i <= n; i++)
		{
			if(i & 1)
			{
				if(!ev.empty() && !od.empty())
				{
					if(ev.back() > od.back())
					{
						a += ev.back();
						ev.pop_back();
					}
					else
					{
						od.pop_back();
					}
				}
				else if(!ev.empty())
				{
					a += ev.back();
					ev.pop_back();
				}
				else
				{
					od.pop_back();
				}
			}
			else
			{
				if(!ev.empty() && !od.empty())
				{
					if(ev.back() > od.back())
					{
						ev.pop_back();
					}
					else
					{
						b += od.back();
						od.pop_back();
					}
				}
				else if(!ev.empty())
				{
					ev.pop_back();
				}
				else
				{
					b += od.back();
					od.pop_back();
				}
			}
		}

		if(a > b) cout << "Alice\n";
		else if(b > a) cout << "Bob\n";
		else cout << "Tie\n";
    }


}


