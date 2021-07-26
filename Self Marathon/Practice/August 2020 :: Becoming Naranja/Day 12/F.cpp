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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    string s;

    while(cin >> n >> s)
    {
		ll c3 = 0, c2 = 0, c5 = 0, c7 = 0;

		for(auto it: s)
		{
			if(it == '9') c7++, c3 += 2, c2++;
			if(it == '8') c7++, c2 += 3;
			if(it == '7') c7++;
			if(it == '6') c5++, c3++;
			if(it == '5') c5++;
			if(it == '4') c3++, c2 += 2;
			if(it == '3') c3++;
			if(it == '2') c2++;
		}

		for(ll i = 1; i <= c7; i++) cout << 7;
		for(ll i = 1; i <= c5; i++) cout << 5;
		for(ll i = 1; i <= c3; i++) cout << 3;
		for(ll i = 1; i <= c2; i++) cout << 2;

		cout << endl;
    }


}



