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

string torn(string s, vector < ll > num)
{
	string ret = "";

	ll tmp = num.back();

//	cout << tmp << endl;

	tmp--;
	bool on = 0;

	while(tmp)
	{
		ll x = tmp % 26;
//
		if(tmp < 26 && on) x -= 1;
//
		x += 26;

		x %= 26;

		ret += (x + 'A');

		if(x + 'A' != 'Z') on = 1;

		tmp /= 26;
	}

	reverse(ret.begin(),ret.end());

	tmp = num.front();

	string ret1;

	while(tmp)
	{
		ret1 += (tmp % 10) + '0';
		tmp /= 10;
	}

	reverse(ret1.begin(),ret1.end());

	ret += ret1;

	return ret;
}

string tobc(string s, vector < ll > num)
{
	int n = 0;

	for(auto it: s)
	{
		if(it >= '0' && it <= '9')
		{
			num.push_back(n);
			break;
		}

		n *= 26;
		n += (it - 'A' + 1);
	}

	string ret = "";

	ret += 'R';

	for(ll i = 0; i < num.size(); i++)
	{
		ll tmp = num[i];

		string ret1 = "";

		while(tmp)
		{
			ret1 += (tmp % 10) + '0';
			tmp /= 10;
		}

		reverse(ret1.begin(),ret1.end());

		ret += ret1;

		if(i == 0) ret += 'C';
	}

	return ret;
}

string solve(string n)
{
	vector < ll > num;

	for(int i = 0, j = 0; i <= n.size(); i++)
	{
		if(i == n.size())
		{
			if(j) num.push_back(j);
			j = 0;
			break;
		}

		if(n[i] >= '0' && n[i] <= '9')
		{
			j *= 10;
			j += n[i] - '0';
		}
		else
		{
			if(j) num.push_back(j);
			j = 0;
		}
	}

//	cout << num.front() << " " << num.back() << endl;

	if(num.size() == 2) return torn(n, num);
	else return tobc(n, num);
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
		string str;
		cin >> str;

		string out = solve(str);

		cout << out << "\n";

    }


}

/*

100
R250332C676
R250332C677
AZZ250332
ZZA250
R23C55
BC23
Z25
ZA32
A355
B366

*/


