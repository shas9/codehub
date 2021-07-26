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

vector < pll > vec;

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
		cin >> n >> m;
		vec.clear();

		ll aa = -1, bb = -1;

		for(ll i = 0; i < m; i++)
		{
			ll a, b;

			cin >> a >> b;

			if(bb < b)
			{
				if(aa != -1) vec.push_back({aa,bb});

				aa = a;
				bb = b;

				continue;
			}
			else if(bb == b)
			{
				if(aa < a)
				{
					vec.push_back({aa,bb});

					aa = a;

					continue;
				}
			}

			vec.push_back({a,b});
		}

		sort(vec.rbegin(),vec.rend());

		ll cost = aa + (n - 1) * bb;
		ll lft = (n - 1);
		ll idx = 0;
		ll mx = 0;

		for(ll i = 1; i <= n && idx < vec.size(); i++)
		{
			if(vec[idx].first > bb && lft)
			{
				cost -= bb;
				cost += vec[idx].first;

				lft--;

				idx++;
			}
			else if(lft == 0 && vec[idx].first > aa && vec[idx].first > mx)
			{
				cost -= aa;
				cost += vec[idx].first;

				break;
			}
			else if(lft == 0 && mx > aa)
			{
				cost -= aa;
				cost += mx;

				break;
			}
			else break;


			mx = max(mx, vec[idx - 1].second);
		}

		cout << cost << "\n";
    }


}



