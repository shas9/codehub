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

ll arr[100005];
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
		cin >> n;

		ll o = 0, z = 0;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;

			o += input == 1;
		}

		z = n - o;
		vec.clear();

		if(z < o) for(ll i = 0; i < o; i++) vec.pb(1);
		else for(ll i = 0; i < z; i++) vec.pb(0);

		if((vec.size() & 1) && z < o)
		{
			vec.pop_back();
		}

		cout << vec.size() << "\n";

		for(auto it: vec) cout << it << " ";

		cout << "\n";
    }


}


