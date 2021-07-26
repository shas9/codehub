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

multiset < ll > r, g, b;

bool comp(pll a, pll b)
{
	if(a.first == b.first)

}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll sr, sg, sb;

    while(cin >> sr >> sg >> sb)
    {
		r.clear();
		g.clear();
		b.clear();


		for(ll i = 0; i < sr; i++)
		{
			cin >> input;

			r.insert(input);
		}

		for(ll i = 0; i < sg; i++)
		{
			cin >> input;

			g.insert(input);
		}

		for(ll i = 0; i < sb; i++)
		{
			cin >> input;

			b.insert(input);
		}

		ans = 0;

		while(1)
		{
			vector < pll > vec;

			if(!r.empty())
			{
				auto it = r.end();
				it--;

				vec.push_back({*it,1});
			}

			if(!g.empty())
			{
				auto it = g.end();
				it--;

				vec.push_back({*it,2});
			}

			if(!b.empty())
			{
				auto it = b.end();
				it--;

				vec.push_back({*it,3});
			}

			if(vec.size() < 2) break;

			sort(vec.begin(),vec.end(), comp);

			ans += vec[vec.size() - 1].first * vec[vec.size() - 2].first;
		}

		cout << ans << "\n";
    }


}



