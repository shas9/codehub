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

vector < ll > p1, p2, p;
vector < ll > sp1, sp2, sp;
ll dp1[200005];
ll dp2[200005];

ll bs(ll x)
{
	if(x < sp.front()) return 0;

	ll lo = 0;
	ll hi = sp.size() - 1;
	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(sp[mid] <= x)
		{
			ret = mid + 1;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	assert(ret);

	return ret;
}

ll solve(ll num)
{
	if(num == 1)
	{
		p = p1;
		sp = sp1;
	}
	else
	{
		p = p2;
		sp = sp2;
	}

	ll ret = 0;

	map < ll, ll > mp;

	sort(p.begin(),p.end());
	sort(sp.begin(),sp.end());

	for(auto it: p)
	{
		mp[it] = 1;
	}

	for(ll i = 0; i <= sp.size() + 4; i++) dp1[i] = dp2[i] = 0;

	for(ll i = sp.size() - 1; i >= 0; i--)
	{
		if(mp.find(sp[i]) != mp.end()) dp1[i] = 1;
		dp1[i] += dp1[i + 1];
	}

	ll ptr = 0;

	for(ll i = 0; i < sp.size(); i++)
	{
//		cout << p[ptr] << " + " << sp[i] << endl;
		while(ptr < p.size() && p[ptr] <= sp[i]) ptr++;

		ll pos = bs(sp[i]) - bs(sp[i] - ptr);

//		cout << ptr << " " << dp2[i] << " " << dp1[i + 1] <<  endl;

		ret = max(ret, pos + dp1[i + 1]);
	}

//	cout << ret << " ";

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
		p1.clear();
		p2.clear();
		sp1.clear();
		sp2.clear();

		cin >> n >> m;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;

			if(input < 0) p1.push_back(abs(input));
			else p2.push_back(input);
		}

		for(ll i = 1; i <= m; i++)
		{
			cin >> input;

			if(input < 0) sp1.push_back(abs(input));
			else sp2.push_back(input);
		}

		ans = solve(1) + solve(2);

		cout << ans << "\n";
    }


}



