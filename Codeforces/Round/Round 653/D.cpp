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

map < ll, ll > mp;
vector < ll > vec;

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
		mp.clear();

		slld(n);
		slld(m);

		for(i = 0; i < n; i++)
		{
			slld(input);

			ll md = input % m;

			if(md == 0) continue;

			md = m - md;

			mp[md]++;
		}

		ans = -1;

		for(auto it: mp)
		{
			if(it.second > 1)
			{
				mp[it.first + m] += it.second - 1;
			}

//			cout << it.first << " " << it.second << endl;

			ans = max(ans, it.first);
		}

		printf("%lld\n", ans + 1);
    }


}



