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

multiset < pll > mt;

vector < pll > seg[200005];

vector < ll > rem;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		mt.clear();

		rem.clear();

		for(i = 1; i <= n; i++) seg[i].clear();

		for(i = 1; i <= n; i++)
		{
			slld(l);
			slld(r);

			seg[l].pb({r,i});
		}

		for(i = 1; i <= 200000; i++)
		{
			for(auto it: seg[i])
			{
				mt.insert(it);
			}

			for(multiset < pll > ::iterator it = mt.begin(); it != mt.end();)
			{
				pll x = *it;

				if(x.first < i) it = mt.erase(it);
				else break;
			}

//			if(i <= 15) cout << i << " " << mt.size() << " " << rem.size() << endl;

			if(mt.size() > k)
			{
				multiset < pll > ::iterator it = mt.end();

				while(mt.size() > k)
				{
					it--;
					pll x = *it;
					rem.push_back(x.second);

					it = mt.erase(it);
				}
			}
		}

		cout << rem.size() << "\n";

		for(auto it: rem) cout << it << " ";

		cout << "\n";

    }


}



