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

ll par[200005];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

ll solve(ll x)
{
	if(x <= 3)
	{
		return 0;
	}

//	cout << x << " : ";

	ll now = 1;

	while(now + now <= x)
	{
		now += now;
	}

	now--;

//	cout << now << " ";

	ll ret = (now * (now - 1)) / 2;

//	cout << ret << " ";

	ll num = 0;

	x -= now + 1;

	for(ll i = 32; i >= 0; i--)
	{
		if(check(now,i))
		{
			if(Set(num,i) < x)
			{
				num = Set(num,i);
				ret += (1 << i);
			}
		}
	}

//	cout << num << " ";

	now++;

//	cout << now << " " << x << endl;

	if(x == 0) return ret;

	ret += solve(x) + (now * (x - 1));

	return ret;
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
		cin >> n;

		ans = solve(n);

		cout << ans << "\n";
    }


}

