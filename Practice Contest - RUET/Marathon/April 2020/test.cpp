#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


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

vector < set < string > > vvv;

ll brute(ll x, ll y)
{
	vector < ll > v1, v2;

	for(ll i = x; i <= y; i++)
	{
		v1.push_back(vec[i]);
	}

	while(v1.size() > 1)
	{
		v2.clear();

		for(ll i = 0; i + 1 < v1.size(); i++)
		{
			v2.push_back(v1[i] ^ v1[i + 1]);
		}

		v1 = v2;
	}

	return v1[0];
}

void eq(ll sz)
{
	vvv.clear();
	for(ll i = 1; i <= sz; i++)
	{
		vvv.push_back({});
		string s = "";
		ll tmp = i;

		while(tmp)
		{
			ll x = tmp % 10;
			tmp /= 10;

			s += x + '0';
		}

		s += 'a';

		reverse(s.begin(),s.end());
		vvv.back().insert(s);
	}

	while(vvv.size() > 1)
	{
		for(ll i = 0; i + 1 < vvv.size(); i++)
		{
			for(auto it: vvv[i + 1])
			{
				vvv[i].insert(it);
			}
		}

		vvv.pop_back();
	}

	for(auto it:vvv[0]) cout << it << " ";

	cout << "\n";
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("output.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);
//
//	while(cin >> input)
//	{
//		eq(input);
//	}
    while(cin >> n >> m)
    {
		vec.clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);
			vec.push_back(input);
		}

		for(i = 1; i <= m; i++)
		{
			cin >> l >> r;

			cout << i << ": ";

//			ll x = 0;
//			ll y = 0;
//
//			for(j = l; j <= r; j++)
//			{
//				x ^= vec[j];
//			}
//
//			y = vec[l] ^ vec[r];
//
//			cout << x << " " << y << " " << brute(l,r) << endl;
			ans = brute(l,r);

//			cout << ans << endl;
			for(j = 0; j <= 60; j++)
			{
				if(check(ans,j))
				{
					cout << j + 1 << " ";
				}
			}

			cout << endl;
		}
    }


}



