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

		ll first0 = -1, last0 = -1, first1= -1, last1= -1;

		for(i = 0; i < str.size(); i++)
		{
			if(str[i] == '0') {if(first0 == -1) first0 = i;}
			else {if(first1 == -1) first1 = i;}
		}

		for(i = str.size() - 1; i >= 0; i--)
		{
			if(str[i] == '0') {if(last0 == -1) last0 = i;}
			else {if(last1 == -1) last1 = i;}
		}

		ans = str.size();

		ll cnt = 0;

		for(i = first0; i < str.size(); i++)
		{
			if(str[i] == '1') cnt++;
		}

		ans = min(ans,cnt);

		cnt = 0;

		for(i = 0; i <= last0; i++)
		{
			if(str[i] == '1') cnt++;
		}

		ans = min(ans,cnt);

		cnt = 0;

		for(i = first1; i < str.size(); i++)
		{
			if(str[i] == '0') cnt++;
		}

		ans = min(ans,cnt);

		cnt = 0;

		for(i = 0; i <= last1; i++)
		{
			if(str[i] == '0') cnt++;
		}

		ans = min(ans,cnt);

		cout << ans << '\n';
    }


}


