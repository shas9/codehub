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

vector < ll > vec;
map < ll, ll > mp;



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
		vec.clear();

		mp.clear();

		slld(n);
		slld(m);

		for(i = 1; i <= n; i++)
		{
			slld(input);

			if(mp[input]) continue;
			mp[input] = 1;
			vec.pb(input);
		}

		sort(vec.begin(),vec.end());

		ll shift = 0;

		ll ans = 0;


		for(i = vec.size() - 1; i >= 0; i--)
		{
			vec[i] -= shift;

			if(vec[i] > 0)
			{
				ans++;
				shift += m;
			}
		}

		cout <<ans << "\n";
    }


}



