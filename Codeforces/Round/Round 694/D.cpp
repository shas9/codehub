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

void brute()
{
	vector < ll > vec;
	ll n;

	cin >> n;

	for(ll i = 0; i < n; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}

	for(ll i = 1; i <= 100; i++)
	{
		vector < ll > v;

		sort(vec.begin(),vec.end());

		for(auto it: vec) cout << it << " ";

		cout << "\n";

		for(auto it: vec)
		{
			ll num = 1;
			cout << it << ":: ";

			for(auto jt: vec)
			{
				ll y = __gcd(it,jt);
				ll x = (it * jt) / (y * y);
				ll sqx = sqrt(x);

				if(sqx * sqx == x)
				{
					num = (num * jt);
					cout << jt << " ";
				}

			}

			cout << "= " << num << endl;

			v.push_back(num);
		}

		vec = v;
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	brute();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

    }


}



