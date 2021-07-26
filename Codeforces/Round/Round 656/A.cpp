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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
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
		vector < ll > vec;
		ll a, b, c;

		vec.clear();

		for(ll i = 0; i < 3; i++)
		{
			slld(input);
			vec.push_back(input);
		}

		if(vec[0] == vec[1] && vec[2] <= vec[1])
		{
			cout << "YES\n" << vec[0] << " " << vec[2] << " " << vec[2] << '\n';
		}
		else if(vec[1] == vec[2] && vec[0] <= vec[1])
		{
			cout << "YES\n" << vec[0] << " " << vec[0] << " " << vec[1] << '\n';
		}
		else if(vec[0] == vec[2] && vec[1] <= vec[0])
		{
			cout << "YES\n" << vec[1] << " " << vec[0] << " " << vec[1] << '\n';
		}
		else
		{
			cout << "NO\n";
		}
    }


}


