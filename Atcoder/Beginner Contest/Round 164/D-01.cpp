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

map < ll, ll > freq;
string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
		freq.clear();

		reverse(str.begin(),str.end());

		ll x = 1;
		ll num = 0;
		ans = 0;

		freq[0] = 1;

		for(auto it: str)
		{
			num += (it - '0') * x;

			num %= 2019;

			ans += freq[num];

			freq[num]++;

			x = (x * 10) % 2019;
		}

		cout << ans << '\n';
    }


}


