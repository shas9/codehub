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

ll corr[1000006];
ll large[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    string str;

    while(cin >> str)
    {
		memset(corr,-1,sizeof corr);
		memset(large,-1,sizeof large);

		stack < ll > st;

		for(ll i = 0; i < str.size(); i++)
		{
			if(str[i]== '(') st.push(i);
			else
			{
				if(st.empty()) corr[i] = large[i] = -1;
				else
				{
					ll top = st.top();
					st.pop();
					corr[i] = large[i] = top;

					if(top && large[top - 1] != -1) large[i] = large[top - 1];
				}
			}
		}

		ll mx = 0;
		ll cnt = 1;

		for(ll i = 1; i < str.size(); i++)
		{
			if(large[i] != -1)
			{
				ll sz = i - large[i] + 1;

				if(sz > mx) mx = sz, cnt = 0;

				if(mx == sz) cnt++;
			}
		}

		cout << mx << ' ' << cnt << '\n';

    }


}


