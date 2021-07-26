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

ll mp[1003];

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
		memset(mp,0,sizeof mp);

		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			ll x;
			cin >> x;

			mp[x]++;
		}

		for(ll i = 1000; i >= 1; i--)
		{

			if(mp[i] <= 0) continue;
			while(mp[i]> 0)
			{
				cout << i << " ";

				mp[i]--;
			}

			vector < ll > vec;


			for(ll j = 1; j * j <= i; j++)
			{
				if(i % j == 0)
				{
					for(ll k = (1000 / (i / j)) * (i / j); k > 1; k -= (i / j))
					{
						while(mp[k] > 0)
						{
							vec.push_back(k);
							mp[k]--;
						}
					}
				}
			}

			for(ll j = sqrt(i); j >= 1; j--)
			{
				if(i % j == 0)
				{
					for(ll k = (1000 / j) * j; k >= j; k -= j)
					{
						while(mp[k] > 0)
						{
							vec.push_back(k);
							mp[k]--;
						}
					}
				}
			}

			for(auto it: vec) cout << it << " ";
		}

		cout << "\n";
    }
}



