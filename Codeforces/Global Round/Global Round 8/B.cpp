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

ll freq[20];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 0; i < 10; i++) freq[i] = 1;

		ll tot = 1;
		ll idx = 0;

		string str = "codeforces";

		while(tot < n)
		{
			tot /= freq[idx];
			freq[idx]++;
			tot *= freq[idx];
			idx++;
			idx %= 10;
		}

		for(i = 0; i < 10; i++)
		{
			for(j = 1; j <= freq[i]; j++) cout << str[i];
		}

		cout << '\n';
    }


}



