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

		ll last = -1;
		ll tot = 0;

		for(auto it: v)
		{
			if(last != -1)
			{
				if(last == 0)
				{
					if(mp[0]) out += '+';
					else if(mp[2]) out += '*';
					else out += '-';
				}
				else if(it == 0)
				{
					if(mp[0]) out += '+';
					else if(mp[1]) out += '-';
					else out += '*';
				}
				else if(last == 1 && it == 1)
				{
					if(mp[2]) out += '+';
					else if(mp[2]) out += '*';
					else out += '-';
				}
				else if(last == 1 || it == 1)
				{
					if(mp[0]) out += '+';
					else if(mp[2]) out += '*';
					else out += '-';
				}
				else
				{
					if(mp[2]) out += '*';
					else if(mp[0]) out += '+';
					else out += '-';
				}
			}


			out += it + '0';
			last = it;
		}

		cout << out << "\n";
    }


}


