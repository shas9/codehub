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

string s, t;

bool autom()
{
	ll idx = 0;

	for(auto it: t)
	{
		if(idx >= s.size()) return 0;

		while(s[idx] != it)
		{
			idx++;
			if(idx == s.size()) return 0;
		}

		idx++;
	}

	return 1;
}

bool arr()
{
	string x = s, y = t;

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	return x == y;
}

bool both()
{
	ll freq[30];

	memset(freq,0,sizeof freq);

	for(auto it: s) freq[it - 'a']++;
	for(auto it: t) freq[it - 'a']--;

	for(ll i = 0; i < 26; i++) if(freq[i] < 0) return 0;

	return 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> s >> t)
    {
		if(autom()) cout << "automaton\n";
		else if(arr()) cout << "array\n";
		else if(both()) cout << "both\n";
		else cout << "need tree\n";
    }


}


