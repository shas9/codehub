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

string str;
ll ns, nb, nc;
ll ps, pb, pc;
ll as, ab, ac;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
		cin >> nb >> ns >> nc;
		cin >> pb >> ps >> pc;
		cin >> m;

		as = ab = ac = 0;

		for(auto it: str)
		{
			if(it == 'S') as++;
			else if(it == 'C') ac++;
			else ab++;
		}

		if(as == 0) ns = 0;
		if(ab == 0) nb = 0;
		if(ac == 0) nc = 0;

		ans = 0;

		while(ns || nb || nc)
		{
			if(ns < as)
			{
				if((as - ns) * ps <= m)
				{
					m -= (as - ns) * ps;
				}
				else break;

				ns = 0;
			}
			else
			{
				ns -= as;
			}

			if(nb < ab)
			{
				if((ab - nb) * pb <= m)
				{
					m -= (ab - nb) * pb;
				}
				else break;

				nb = 0;
			}
			else
			{
				nb -= ab;
			}

			if(nc < ac)
			{
				if((ac - nc) * pc <= m)
				{
					m -= (ac - nc) * pc;
				}
				else break;

				nc = 0;
			}
			else
			{
				nc -= ac;
			}

			ans++;
		}

		ll tot = as * ps + ab * pb + ac * pc;

		ans += (m / tot);

		cout << ans << "\n";
    }

}


