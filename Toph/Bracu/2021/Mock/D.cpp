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

ll solve(ll x, ll y)
{
	stack < ll > q;

	ll ans = x * y;

	if(ans == 0) return 0;

	ll sum = x;
	ll now = x;
	ll step = 0;

	while(sum + now <= ans)
	{
		q.push(now);

		sum += now;
		now = sum;

		step++;

//		if(step >= 3000000) return mxlld;

//	bug;
	}

//	cout << step << endl;

	while(!q.empty() && sum < ans)
	{
		if(sum + q.top() <= ans)
		{
			sum += q.top();
			step++;
		}

		q.pop();
	}

	if(sum != ans) return mxlld;

	return step;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		ll ans = (n * m);

		cout << min(solve(n,m), solve(m,n)) << "\n";
    }


}

