
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
string missed;
string out;

void solve()
{
	out = "";

	sort(missed.begin(),missed.end());

	ll khali = 0;

	for(auto it: str) if(it == '?') khali++;

	assert(khali);
	assert(khali <= missed.size());

	out = "";

	ll idx = 0;

	ll rem = missed.size();

	for(ll i = 0; i < str.size(); i++)
	{
		if(str[i] != '?') out += str[i];
		else if(khali == 1)
		{
			while(idx < missed.size()) out += missed[idx], idx++;
			khali--;
		}
		else
		{
			assert(khali);

			out += missed[idx];
			idx++;
			rem--;
			ll jdx = i + 1;

			while(jdx < str.size() && str[i + 1] == str[jdx]) jdx++;

			while(rem >= khali)
			{
				if(str[i + 1] == '?') break;

				if(missed[idx] < str[i + 1])
				{
					out += missed[idx];
					idx++;
					rem--;
				}
				else if(jdx < str.size() && missed[idx] == str[i + 1] && missed[idx] < str[jdx])
				{
					out += missed[idx];
					idx++;
					rem--;
				}

				else break;
			}

			khali--;
		}
	}

	return;
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

		cin >> k >> missed;

		assert(k == missed.size());

		assert(1 <= str.size() && str.size() <= 20000);

		solve();

//		if(cs == 22) cout << str << " " << missed << " " << out << endl;
//
		cout << out << '\n';
    }

    assert(!(cin >> str));

}






