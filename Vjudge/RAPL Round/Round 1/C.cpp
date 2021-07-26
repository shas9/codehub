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

ll freq[30];
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
		memset(freq,0,sizeof freq);

		for(auto it: str) freq[it - 'A']++;

		ans = 1;

		for(i = 0; i < str.size(); i++)
		{
			ll cnt = 0;
			ll mx = 0, mxpos = -1;

			for(j = 0; j < 25; j++)
			{
				if(freq[j]) cnt++;

				if(freq[j] > mx)
				{
					mx = freq[j];
					mxpos = j;
				}
			}

//			cout << cnt << endl;

			ans = (ans * cnt);

//			cout << ans << " " << cnt << endl;
			freq[mxpos]--;
		}

		cout << ans << '\n';
    }


}


