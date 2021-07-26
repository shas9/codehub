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

string a, b;


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> a >> b)
    {
		ans = 0;
		ll cnt1 = 0;
		ll cnt2 = 0;

		for(ll i = 0; i < b.size(); i++) cnt1 += (a[i] == '1');
		for(ll i = 0; i < b.size(); i++) cnt2 += (b[i] == '1');

		for(ll i = b.size(); i < a.size(); i++)
		{
			ans += ((cnt1 + cnt2) % 2 == 0);

			if(a[i - b.size()] == '1') cnt1--;
			if(a[i] == '1') cnt1++;
		}

		ans += ((cnt1 + cnt2) % 2 == 0);

		cout << ans << "\n";
    }


}



