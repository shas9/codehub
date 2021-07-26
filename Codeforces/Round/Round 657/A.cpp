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
string out;

bool solve()
{
	ll cnt = 0;

	for(ll i = 0; i + 7 <= str.size(); i++)
	{
		string sub = "";
		for(ll j = i; j < i + 7; j++) sub += str[j];

		if(sub == "abacaba") cnt++;
	}
	if(cnt > 1) return 0;

	if(cnt == 1)
	{
		out = str;

		for(auto &it: out) if(it == '?') it = 'x';

		return 1;
	}

	for(ll i = 0; i + 7 <= str.size(); i++)
	{
		string sub = "";
		string mt = "abacaba";

		for(ll j = i; j < i + 7; j++) sub += str[j];

		bool poss = 1;

		for(ll j = 0; j < 7; j++)
		{
			if(sub[j] == mt[j]) continue;

			if(sub[j] == '?') continue;

			poss = 0;

			break;
		}

		if(poss == 1)
		{
			out = "";
			for(ll j = 0; j < i; j++) out += str[j];

			out += "abacaba";

			for(ll j = i + 7; j < str.size(); j++) out += str[j];

			for(auto &it: out) if(it == '?') it = 'x';

			cnt = 0;

			for(ll j = 0; j + 7 <= out.size(); j++)
			{
				string sub = "";
				for(ll k = j; k < j + 7; k++) sub += out[k];

				if(sub == "abacaba") cnt++;
			}

//			cout << cnt << endl;

			if(cnt != 1) continue;

			return 1;
		}
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
		cin >> n >> str;

		if(solve()) cout << "YES\n" <<  out << "\n";
		else cout << "NO\n";

    }


}


