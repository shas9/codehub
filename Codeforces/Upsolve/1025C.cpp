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
		ans = 1;

		ll cnt = 1;

		for(ll i = 1; i < str.size(); i++)
		{
			if(str[i] != str[i - 1]) cnt++;
			else cnt = 1;

			ans = max(ans, cnt);
		}

		if(str.front() != str.back())
		{
			ll pos = 1;
			ll cnt1 = 1;

			for(i = 1; i < str.size() - 1; i++)
			{
				if(str[i] != str[i - 1]) cnt1++;
				else
				{
					break;
				}
			}

			pos = i;

			ll cnt2 = 1;

			for(ll i = str.size() - 2; i >= pos; i--)
			{
				if(str[i] != str[i + 1]) cnt2++;
				else
				{
					break;
				}
			}

			ans = max(ans, cnt1 + cnt2);
		}

		cout << ans << "\n";
    }


}



