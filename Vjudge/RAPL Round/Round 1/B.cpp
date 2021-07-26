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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n)
	{
		queue < ll > q;

		bool on = 0;

		for(i = 32; i >= 0; i--)
		{
			if(check(n,i)) q.push(1), on = 1;
			else if(on) q.push(0);
		}

		ans = n;

		ll curr = n;

		ll msb = q.size() - 1;

		for(i = 0; i <= 40; i++)
		{
			ll top = q.front();
			q.pop();

			if(top == 1) curr -= (1 << msb);

			curr = (curr << 1);

			q.push(top);

			if(top == 1) curr += 1;

			ans = max(ans,curr);
		}

		cout << ans << '\n';
	}

}



