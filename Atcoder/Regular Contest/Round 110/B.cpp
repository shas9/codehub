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

string str, str2;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
		ll sz = str.size();

		str2 = "";

		for(ll i = 1; i <= sz; i++)
		{
			str2 += "110";
		}

		ll meet = -1;
		ll cnt = 0;

		for(ll i = 0; i < 3; i++)
		{
			bool on = 1;

			for(ll j = 0; j < sz; j++)
			{
				if(str2[i + j] != str[j])
				{
					on = 0;
					break;
				}
			}

			if(on)
			{
				cnt++;
				meet = i + sz;
			}
		}

		ans = 0;

		ll strsz = 3e10 - (meet - 3);

		ans = (strsz / 3) * cnt;

		if(meet == -1) ans = 0;

		cout << ans << "\n";

    }


}



