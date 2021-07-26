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

    string s, t;

    while(cin >> n >> s)
    {
		ans = 0;

		for(ll i = 0; i < n; i++)
		{
			ll a = 0, c = 0, g = 0, t = 0;

			for(ll j = i; j < n; j++)
			{
				a += s[j] == 'A';
				c += s[j] == 'C';
				g += s[j] == 'G';
				t += s[j] == 'T';

				if(a == t && c == g) ans++;
			}
		}

		cout << ans << "\n";
    }


}



