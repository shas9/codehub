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

ll freq[10];
string str;

ll odd()
{
	ll mx = 0;

	for(ll i = 0; i < 10; i++) mx = max(mx, freq[i]);

	if(mx % 2 == 0) mx--;

	return (str.size() - mx);
}

ll even()
{
	ll ret = 2;

	for(ll i = 0; i < 10; i++)
	{
		for(ll j = 0; j < 10; j++)
		{
			ll len = 0;
			for(auto it: str)
			{
				if(len & 1)
				{
					if(it - '0' == j) len++;
				}
				else
				{
					if(it - '0' == i) len++;
				}
			}
//
//			cout << i << " " << j << " " << len << endl;

			if(!(len & 1)) ret = max(ret, len);
		}
	}

	return (str.size() - ret);
}

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

		memset(freq,0,sizeof freq);

		for(auto it: str) freq[it - '0']++;

		ans = min(odd(), even());
		cout << ans << "\n";
    }


}



