#include <bits/stdc++.h>`

#define ll long long

using namespace std;


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, ans;

	cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ll a, b, c, d;

		cin >> n >> a >> b >> c >> d;

		if((n * (a + b)) >= (c - d) && (n * (a - b)) <= (c + d)) cout << "Yes" << endl;
		else cout << "No" << endl;



    }

}


