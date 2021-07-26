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

vector < set < ll > > ans;
string a, b;
vector < ll > g1[30], g2[30];

bool solve()
{
	ll sz = a.size();
	ll mna = 30, mnb = 30;

	for(ll i = 0; i < sz; i++) g1[a[i] - 'a'].pb(i), mna = min(mna, (long long)(a[i] - 'a'));
	for(ll i = 0; i < sz; i++) g2[b[i] - 'a'].pb(i), mnb = min(mnb, (long long)(b[i] - 'a'));

	if(mna != mnb) return 0;

//	bug;

	for(ll i = 0; i < sz; i++) if(a[i] < b[i]) return 0;

//	bug;

	for(ll i = 0; i < 30; i++)
	{
		if(g2[i].empty() == 0 && g1[i].empty()) return 0;
	}

//	bug;

	for(ll i = 25; i >= 0; i--)
	{
		if(g2[i].empty()) continue;

		set < ll > st;

		bool shobc = 1, ektac = 0;

		for(auto it: g2[i])
		{
			if(a[it] != b[it]) shobc = 0;
			if(a[it] == b[it]) ektac = 1;

			st.insert(it);
		}

		if(shobc) continue;

		if(ektac == 0) st.insert(g1[i].front());

		ans.push_back(st);
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		for(i = 0; i < 30; i++) g1[i].clear(), g2[i].clear();
		ans.clear();

		cin >> n >> a >> b;

		if(!solve()) printf("-1\n");
		else
		{
			cout << ans.size() << '\n';

			for(auto it: ans)
			{
				cout << it.size() << ' ';

				for(auto jt: it) cout << jt << " ";

				cout << '\n';
			}
		}
    }


}



