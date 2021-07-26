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

ll cnt[35];
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
		memset(cnt,0,sizeof cnt);

		for(i = 1; i <= n; i++)
		{
			slld(input);

			for(j = 0; j <= 30; j++)
			{
				if((1 << j) == input)
				{
					cnt[j]++;
					break;
				}
			}
		}

		ll idx = 0;

		for(i = 0; i < 30; i++)
		{
			if((1 << i) == 2048)
			{
				idx = i;
			}
		}

		bool on = 0;

		for(i = 0; i <= 30; i++)
		{
			if(idx == i)
			{
				if(cnt[i]) on = 1;

				break;
			}
			ll x = cnt[i] / 2;
			cnt[i] %= 2;
			cnt[i + 1] += x;
		}

		if(on) printf("YES\n");
		else printf("NO\n");
    }


}


