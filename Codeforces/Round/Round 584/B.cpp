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

ll cnt[1000006];
string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		cin >> str;
		memset(cnt,0,sizeof cnt);

		for(i = 1; i <= n; i++)
		{
			ll a, b;
			slld(a);
			slld(b);
			bool on = 0;

			if(str[i - 1] == '1') on = 1;

			if(on) cnt[0]++;

			for(j = 1; j <= 500000; j++)
			{
				if((j - b) >= 0 && (j - b) % a == 0) on ^= 1;

				if(on) cnt[j]++;
			}
		}

		ans = 0;

		for(i = 0; i <= 500000; i++)
		{
			ans = max(ans,cnt[i]);
		}

		printf("%lld\n", ans);
    }


}



