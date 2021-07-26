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

bool solve()
{
	ll a = 0, b = 0, c = 0;

	for(auto it: str)
	{
		if(it == 'A') a++;
		else if(it == 'B') b++;
		else c++;
	}

	ll seq = 0;

	for(auto it: str)
	{
		if(it == str.front())
		{
			seq++;
		}
		else
		{
			if(str.front() == 'A')
			{
				if(a == b + c)
				{
					seq--;
				}
				else
				{
					if(a + b == c)
					{
						if(it == 'B') seq++;
						else seq--;
					}
					else if(a + c == b)
					{
						if(it == 'C') seq++;
						else seq--;
					}
					else return 0;
				}
			}
			else if(str.front() == 'B')
			{
				if(b == a + c)
				{
					seq--;
				}
				else
				{
					if(a + b == c)
					{
						if(it == 'A') seq++;
						else seq--;
					}
					else if(b + c == a)
					{
						if(it == 'C') seq++;
						else seq--;
					}
					else return 0;
				}
			}
			else if(str.front() == 'C')
			{
				if(a + b == c)
				{
					seq--;
				}
				else
				{
					if(c + b == a)
					{
						if(it == 'B') seq++;
						else seq--;
					}
					else if(a + c == b)
					{
						if(it == 'A') seq++;
						else seq--;
					}
					else return 0;
				}
			}
		}

		if(seq < 0) return 0;
	}

	return seq == 0;
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

		if(solve()) cout << "YES\n";
		else cout << "NO\n";
    }


}


