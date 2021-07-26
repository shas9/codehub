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

vector < ll > vec;

bool poss(ll n)
{
	ll p[] = {6,10,14,15,21,22,26};

	vec.clear();

	for(ll i = 0; i < 7; i++)
	{
		for(ll j = i + 1; j < 7; j++)
		{
			for(ll k = j + 1; k < 7; k++)
			{
				ll sum = p[i] + p[j] + p[k];

				if(sum >= n) continue;

				ll x = n - sum;

				if(x == p[i] || x == p[j] || x == p[k]) continue;

				vec.push_back(x);
				vec.push_back(p[i]);
				vec.push_back(p[j]);
				vec.push_back(p[k]);

				return 1;
			}
		}
	}

	return 0;
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
		slld(n);

		if(poss(n))
		{
			cout << "YES\n";

			for(auto it: vec)
			{
				cout << it << " ";
			}

			cout << "\n";
		}
		else cout << "NO\n";
    }


}



