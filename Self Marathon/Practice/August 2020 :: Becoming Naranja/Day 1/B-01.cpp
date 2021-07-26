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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n)
    {
		vector < ll > vec;

		ll a1 = 0, a2 = 0;

		for(i = 1; i <= n; i++)
		{
			ll sz;

			cin >> sz;

			for(ll j = 1; j <= sz; j++)
			{
				cin >> input;

				if(j <= (sz / 2)) a1 += input;
				else if(j + (sz / 2) > sz) a2 += input;
				else vec.push_back(input);
			}
		}

		sort(vec.rbegin(),vec.rend());

		for(ll i = 0; i < vec.size(); i++)
		{
			if(i & 1) a2 += vec[i];
			else a1 += vec[i];
		}

		cout << a1 << " " << a2 << endl;
    }


}


