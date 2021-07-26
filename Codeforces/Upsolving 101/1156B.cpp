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

string s, o, e, t;

bool chk()
{
	for(ll i = 1; i < t.size(); i++)
	{
		if(abs(t[i] - t[i - 1]) == 1) return 1;
	}

	return 0;
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> s;
		sort(s.begin(),s.end());

		o = "";
		e = "";

		for(auto it: s)
		{
			if((it - 'a') % 2) o += it;
			else e += it;
		}

		t = o + e;

		if(chk())
		{
			t = e + o;

			if(chk()) cout << "No answer" << '\n';
			else cout << t << '\n';
		}
		else cout << t << '\n';
    }


}



