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

const ll lim = 150005;

vector < ll > g1[lim], g2[lim], g3[lim];
ll dp1[lim], dp2[lim], dp3[lim];
ll val1[lim], val2[lim], val3[lim], val4[lim];

void clr()
{
	for(ll i = 0; i < lim; i++)
	{
		g1[i].clear();
		g2[i].clear();
		g3[i].clear();
	}
}

void solve3(ll n, ll m)
{
	multiset < ll > st;

	for(ll i = 1; i <= m; i++) st.insert(val4[i]);

	st.insert(1e16);

	for(ll i = 1; i <= n; i++)
	{
		for(auto it: g3[i])
		{
			st.erase(st.find(val4[it]));
		}

		dp3[i] = *st.begin() + val3[i];

		for(auto it: g3[i])
		{
			st.insert(val4[it]);
		}
	}
}

void solve2(ll n, ll m)
{
	multiset < ll > st;

	for(ll i = 1; i <= m; i++) st.insert(dp3[i]);

	st.insert(1e16);

	for(ll i = 1; i <= n; i++)
	{
		for(auto it: g2[i])
		{
			st.erase(st.find(dp3[it]));
		}

		dp2[i] = *st.begin() + val2[i];

		for(auto it: g2[i])
		{
			st.insert(dp3[it]);
		}
	}
}

void solve1(ll n, ll m)
{
	multiset < ll > st;

	for(ll i = 1; i <= m; i++) st.insert(dp2[i]);

	st.insert(1e16);

	for(ll i = 1; i <= n; i++)
	{
		for(auto it: g1[i])
		{
			st.erase(st.find(dp2[it]));
		}

		dp1[i] = *st.begin() + val1[i];

		for(auto it: g1[i])
		{
			st.insert(dp2[it]);
		}
	}
}

ll solve(ll n)
{
	ll ret = mxlld;

	for(ll i = 1; i <= n; i++) ret = min(ret, dp1[i]);

	return ret;
}

void test()
{
	multiset < ll > st;

	for(ll i = 1; i <= 5; i++) st.insert(10);

	for(ll i = 1; i <= 5; i++)
	{
		st.erase(10);
		cout << st.size() << endl;
	}

	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

	ll n1, n2, n3, n4;

	while(cin >> n1 >> n2 >> n3 >> n4)
    {
		clr();

		for(ll i = 1; i <= n1; i++) cin >> val1[i];
		for(ll i = 1; i <= n2; i++) cin >> val2[i];
		for(ll i = 1; i <= n3; i++) cin >> val3[i];
		for(ll i = 1; i <= n4; i++) cin >> val4[i];

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;
			g1[u].push_back(v);
		}

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;
			g2[u].push_back(v);
		}

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;
			g3[u].push_back(v);
		}

		solve3(n3,n4);
		solve2(n2,n3);
		solve1(n1,n2);

		ans = solve(n1);

		if(ans > 1e10) ans = -1;

		cout << ans << "\n";
    }


}



