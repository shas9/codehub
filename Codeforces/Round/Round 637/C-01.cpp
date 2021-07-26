// God put a smile upon your face <3

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

ll pos[100005];

ll last[100005];

ll par[100005];

ll cnt[100005];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

set < ll > st;

bool solve(ll n)
{
	st.clear();
	st.insert(1);

	for(ll i = 1; i <= n; i++)
	{
		ll idx = pos[i];

		ll u = fnd(idx);

		set < ll > :: iterator it = st.end();

		it--;
		ll mx = *it;

//		cout << i << " " << mx << endl;
		if(cnt[u] != mx) return 0;

		ll cc = cnt[u]--;

		par[u] = 0;
		par[u] = fnd(u + 1);
		cnt[par[u]]++;

		if(par[u])
		st.insert(cnt[par[u]]);
	}

	return 1;
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

		for(i = 1; i <= n; i++)
		{
			slld(input);
			pos[input] = i;
		}


		for(i = 1; i <= n; i++) last[i] = i, par[i] = i, cnt[i] = 1;
		last[n + 1] = 0;
		par[n + 1] = 0;

		if(solve(n)) cout << "Yes" << "\n";
		else cout << "No" << "\n";


    }


}



