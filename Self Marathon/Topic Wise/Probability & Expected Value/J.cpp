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

vector < pll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		vec.clear();

		for(i = 0; i < n; i++)
		{
			slld(l);
			slld(r);

			vec.push_back({l,r});
		}

		long double ans = 0;

		for(i = 0; i < n; i++)
		{
			long double prob = 0;

			ll primein_i = (vec[i].second / m) - ((vec[i].first - 1) / m);
			ll primein_j = (vec[(i + 1) % n].second / m) - ((vec[(i + 1) % n].first - 1) / m);

			ll noprime_i = (vec[i].second - vec[i].first + 1) - primein_i;
			ll noprime_j = (vec[(i + 1) % n].second - vec[(i + 1) % n].first + 1) - primein_j;

			prob = ((noprime_i * 1.0) / (vec[i].second - vec[i].first + 1)) * ((noprime_j * 1.0) / (vec[(i + 1) % n].second - vec[(i + 1) % n].first + 1));
			prob = (1 - prob);

//			cout << prob << " ";

			ans += (prob * 2000);
		}

		printf("%.10f\n", (double)ans);
    }


}


