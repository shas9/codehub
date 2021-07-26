#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long

using namespace std;


int main()
{

    ll testcase;

    cin >> testcase;

    ll x;
    ll n, m;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> x >> n >> m;

		while(x > 20 && n--)
		{
			x /= 2;
			x += 10;

			if(x <= 0) break;
		}

		if(x <= 0)
		{
			cout << "YES" << "\n";
			continue;
		}

		while(m--)
		{
			x-= 10;
		}

		if(x <= 0)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
    }



}




