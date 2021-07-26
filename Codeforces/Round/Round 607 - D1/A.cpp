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

#define mod 1000000007

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


ll freq[3000006];
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
		cin >> input;
		cin >> str;

		ans = str.size();

		for(i = 0; i < str.size(); i++) freq[i] = str[i] - '1';

		ll idx = str.size();

		ll cnt = 0;

		for(i = 0; i < input; i++)
		{
			ll lft = i + 1;
			ll rgt = ans - 1;

			ans = (ans + freq[i] * (rgt - lft + 1 + mod)) % mod;

			for(j = 1; j <= freq[i] && idx <= (input * 2); j++)
			{
				for(k = lft; k <= rgt && idx <= (input * 2); k++)
				{
					freq[idx] = freq[k];
					idx++;

					cnt++;
				}

//				cout << cnt << endl;
			}

//			cout << ans << endl;
		}

//		cout << cnt << " & ";

		printf("%lld\n", ans);

    }


}



