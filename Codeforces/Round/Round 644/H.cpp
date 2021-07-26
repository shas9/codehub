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

string arr[105];

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
		slld(n);
		slld(m);

		string str;

		for(i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		ll pos = (1LL << m) - n;
		pos = (pos + 1) / 2;

		for(i = 0; i < m; i++)
		{
			ll cnt = 0;

			for(j = 1; j <= n; j++)
			{
				for(k = 0; k < str.size(); k++) if(str[k] != arr[j][k]) break;

				if(k < str.size()) continue;

				if(arr[j][k] == '0') cnt++;
			}

			ll tot = (1LL << (m - i - 1)) - cnt;

			assert(tot >= 0);

			if(tot >= pos) str += '0';
			else str  += '1', pos -= tot;


		}

		cout << str << '\n';
    }


}



