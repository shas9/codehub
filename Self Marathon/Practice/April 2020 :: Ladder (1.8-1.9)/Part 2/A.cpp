#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > head, datumn;

bool done(ll tm, ll n, ll m)
{
	ll shift = 0;

	for(ll i = 0; i < n; i++)
	{
//		if(tm == 10)
//			cout << i << " " << shift << endl;

		ll ct = 0;

		ct = max(0LL,(head[i] - datumn[shift]));

		if(ct > tm) return 0;

		ll remtm = tm - ct;

		ll lrange = ct;

		while(shift < m && datumn[shift] <= head[i]) shift++;

		if(shift == m) return 1;

		ll rrange = 0;

//		if(tm == 10) cout << shift << " " << lrange << " " << remtm << endl;

		while(shift < m)
		{
			rrange = datumn[shift] - head[i];
			ll cost = (rrange + lrange + min(lrange,rrange));

//			if(tm == 10) cout << cost << " " << rrange << endl;
			if(cost > tm) break;

			shift++;
		}

//		if(tm == 10) cout << "!! " << shift << endl;

		if(shift == m) return 1;
	}

	if(shift < m) return 0;

	return 1;
}

ll solve(ll n, ll m)
{

	ll lo = 0;
	ll hi = (1e11);
	ll ret = (1e11);

	sort(head.begin(),head.end());
	sort(datumn.begin(),datumn.end());

//	for(auto it: head) cout << it << " ";
//	cout << endl;
//
//	for(auto it: datumn) cout << it << " ";
//	cout << endl;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

//		cout << mid << endl;

		if(done(mid,n,m))
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return ret;
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
		head.resize(n);
		datumn.resize(m);

		for(i = 0; i < n; i++) slld(head[i]);

		for(i = 0; i < m; i++) slld(datumn[i]);

		ans = solve(n,m);

		printf("%lld\n", ans);
    }


}



