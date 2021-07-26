
// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

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
	string tmp = "";

	bool ok = 0;

	for(ll i = 0; i < str.size(); i++)
	{
		if(i + 1 == str.size()) tmp += str[i];
		else if(ok == 0 && str[i] != str[i + 1]) i++, ok = 1;
		else tmp += str[i];
	}

	str = tmp;

//	cout << str << endl;

	return ok;
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

		bool on = 0;

		while(solve())
		{
			on ^= 1;
		}


		if(on) printf("DA\n");
		else printf("NET\n");
    }


}



