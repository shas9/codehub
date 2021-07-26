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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> s)
    {
		bool ab = 0, ba = 0;

		for(ll i = 0; i + 1 < s.size(); i++)
		{
			if(s[i] == 'B' && s[i + 1] == 'A' && !ba)
			{
				ba = 1;
				i++;
				continue;
			}

			if(s[i] == 'A' && s[i + 1] == 'B' && ba)
			{
				ab = 1;
				i++;
				continue;
			}
		}

		if(ab && ba)
		{
			cout << "YES\n";
			continue;
		}


		ab = 0, ba = 0;

		for(ll i = 0; i + 1 < s.size(); i++)
		{
			if(s[i] == 'A' && s[i + 1] == 'B' && !ab)
			{
				ab = 1;
				i++;
				continue;
			}

			if(s[i] == 'B' && s[i + 1] == 'A' && ab)
			{
				ba = 1;
				i++;
				continue;
			}
		}

		if(ab && ba) cout << "YES\n";
		else cout << "NO\n";
    }


}


