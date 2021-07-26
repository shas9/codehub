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

void solve(ll n)
{
	vector < pll > v;
	vector < ll > v1;

	for(ll i = 2; i <= n; i++)
	{
		if(xorval[i] == (n - 1))
		{
			v.push_back({i,0});
			break;
		}
	}

	for(ll i = 2; i <= n; i++)
	{
		if(v.size() == 2)
		{
			v.push_back({-1, ask(v.front().first, v.back().first, 1)});
			break;
		}

		if(i == v.front().first) continue;

		v.push_back({i,ask(1,i,1)});
	}

	for(auto it: v)
	{
		v1.push_back(2 * it.second);
		if(v1.size() <= 2) v1.back() += xorval[it.first];
		else
		{
			v1.back() += (xorval[v[0].first] ^ xorval[v[1].first]);
		}
	}

	ll one = (v1[0] + v1[1] - v1[2]) / 2;

	cout << "! " << one << " ";

	for(ll i = 2; i <= n; i++) cout << (one ^ xorval[i]) << " ";

	cout << endl;

	return;
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
			solve(n);
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
