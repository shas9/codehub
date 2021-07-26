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

ll cnt[5000005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll a, b, c, d;

    while(cin >> a >> b >> c >> d)
    {
		ans = 0;

		memset(cnt,0,sizeof cnt);

		for(i = a; i <= b; i++)
		{
			cnt[i + b]++;
			cnt[i + c + 1]--;

//			cout << i + b << " " << i + c << endl;
		}

		for(i = 1; i <= 5000000; i++) cnt[i] += cnt[i - 1];
		for(i = 1; i <= 5000000; i++) cnt[i] += cnt[i - 1];

		for(i = c; i <= d; i++)
		{
			ans += cnt[a+b+c+d] - cnt[i];
		}

		printf("%lld\n", ans);
    }

}


