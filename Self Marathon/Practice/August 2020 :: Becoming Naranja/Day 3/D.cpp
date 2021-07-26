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

multiset < ll > w1, w2, h1, h2;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	ll w, h;

	fastio;

    while(cin >> w >> h >> n)
    {
		w1.clear();
		w2.clear();
		h1.clear();
		h2.clear();

		w1.insert(0);
		w1.insert(w);
		w2.insert(w);

		h1.insert(0);
		h1.insert(h);
		h2.insert(h);

		for(ll i = 1; i <= n; i++)
		{
			char c;
			cin >> c >> input;

			if(c == 'H')
			{
				auto it = h1.lower_bound(input);
				it--;

				auto jt = h1.upper_bound(input);

				ll diff = (*jt - *it);

				h2.erase(h2.find(diff));

				h1.insert(input);

				h2.insert(input - *it);
				h2.insert(*jt - input);
			}
			else
			{
				auto it = w1.lower_bound(input);
				it--;

				auto jt = w1.upper_bound(input);

				ll diff = (*jt - *it);

				w2.erase(w2.find(diff));

				w1.insert(input);

				w2.insert(input - *it);
				w2.insert(*jt - input);
			}

			auto it = h2.end();
			it--;
			auto jt = w2.end();
			jt--;

			ans  = *it * *jt;

			cout << ans << endl;
		}
    }


}



