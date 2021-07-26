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

//		cout << n << " ";
		m = (n - 1) / 3 + 1;

		ll st = 1;
		ll tot = 1;

		while(tot < m)
		{
			st *= 4;
			tot += st;
		}

		tot -= st;

//		cout << m <<  " ";

		ll a = st + (m - tot - 1);
		ll b = 0;

//		cout << a << " ";

		for(i = 0; i <= 60; i += 2)
		{
			if(check(a,i) && check(a,i+1)) b = Set(b,i);
			else if(check(a,i) && !check(a,i+1)) b = Set(b,i + 1);
			else if(!check(a,i) && check(a,i+1)) b = Set(b,i), b = Set(b,i+1);
		}

		ll c = a ^ b;

		cout << n << " " << m << " ";

		if(n % 3 == 1) cout << a;
		else if(n % 3 == 2) cout << b;
		else cout << c;

		cout << "\n";








    }


}



