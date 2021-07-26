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

bool valid(string x)
{
	ll seq = 0;

	for(auto it: x)
	{
		if(it == '(') seq++;
		else seq--;

		if(seq < 0) return 0;
	}

	return seq == 0;
}

bool gen(ll mask)
{
	string x = "";

	for(auto it: str)
	{
		ll y = it - 'A';

		if(check(mask, y))
		{
			x += '(';
		}
		else
		{
			x += ')';
		}
	}

	return valid(x);
}
bool solve()
{
	cin >> str;

	for(ll mask = 0; mask < (1 << 3); mask++)
	{
		if(gen(mask)) return 1;
	}

	return 0;
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
		if(solve()) cout << "Yes\n";
		else cout << "No\n";
    }


}



