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

map < ll, ll > mp, xorval;
vector < ll > vec;

ll ask(ll x, ll y, ll z)
{
	if(z == 1) cout << "AND " << x << " " << y << endl;
	if(z == 2) cout << "OR " << x << " " << y << endl;
	if(z == 3) cout << "XOR " << x << " " << y << endl;

	cin >> x;

	assert(x != -1);

	return x;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		mp.clear();
		xorval.clear();
		vec.clear();
		pll num = {-1,-1};

		for(ll i = 2; i <= n; i++)
		{
			ll x = ask(1,i,3);

			if(x == 0)
			{
				num = {1,i};
			}
			else if(mp.find(x) != mp.end())
			{
				num = {mp[x],i};
			}
			else mp[x] = i;

			xorval[i] = x;
		}

		if(num.first == -1)
		{
			cout << "! ";
			for(ll i = 0; i < n; i++) cout << i << " ";
			cout << endl;
		}
		else
		{
			ll val = ask(num.first, num.second, 1);

			ll one = (val ^ xorval[num.first]);

			cout << "! " << one << " ";

			for(ll i = 2; i <= n; i++) cout << (xorval[i] ^ one) << " ";

			cout << endl;
		}
    }


}


