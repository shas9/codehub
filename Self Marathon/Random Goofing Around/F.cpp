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

ll par[55];
vector < pair < ll, pll > > vec;

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
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
		slld(n);

		for(i = 1; i <= n; i++) par[i] = i;
		vec.clear();

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				slld(input);

				if(input) vec.push_back({input, {i,j}});
			}
		}

		sort(vec.begin(), vec.end());

		ans = 0;

		for(auto it: vec)
		{
			ll u = it.second.first;
			ll v = it.second.second;

			ll paru = fnd(u);
			ll parv = fnd(v);

//			cout << u << " = " << paru << " && " << v << " = " << parv << endl;

			if(paru == parv) ans += it.first;
			else par[paru] = parv;
		}

		set < ll > st;

		for(i = 1; i <= n; i++) st.insert(fnd(i));

		if(st.size() > 1) ans = -1;

		printf("Case %lld: %lld\n", cs, ans);
    }


}


