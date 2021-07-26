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

string s, t;

bool solve()
{
	t = "";

	ll took = 0;

	for(ll i = 0; i < s.size(); i++)
	{
		if(s[i] == '1')
		{
			if(took <= 1) t += '1';
			else if(took > 1)
			{
				t += '0';
			}

			took = 1;
		}
		else if(took) took++;
		else t += '0';
	}



	bool ret = t.size() == s.size();

	s = t;

	return (ret ^ 1);
}

void solve1()
{
	t = "";

	ll j = s.size() - 1;
	ll i = 0;

	while(i < s.size() && s[i] != '1') t += s[i], i++;

	string tt = "";

	while(j >= 0 && s[j] != '0') tt += s[j], j--;

	if(i > j) return;

	reverse(tt.begin(),tt.end());

	s = t;
	s += '0';
	s += tt;
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
		cin >> n;

		cin >> s;

		solve1();

		cout << s << '\n';
    }


}


