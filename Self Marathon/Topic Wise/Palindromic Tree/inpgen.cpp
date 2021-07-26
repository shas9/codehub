// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

    freopen("input1.txt", "w", stdout);

    testcase = 100;

    srand(time(NULL));

    cout << testcase << endl;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		n = rand() % 50000 + 100000;

		for(ll i = 1; i <= n; i++)
		{
			if(rand() % 1000) cout << 'a';
			else cout << 'b';
		}

		cout << endl;

		n = rand() % 50000 + 100000;

		for(ll i = 1; i <= n; i++)
		{
			if(rand() % 1000) cout << 'a';
			else cout << 'b';
		}

		cout << endl;
    }

//    for(ll i = 1; i <= 200000; i++) cout << 'a';
//
//	cout << endl;
//
//	for(ll i = 1; i <= 200000; i++) cout << 'a';
//
//	cout << endl;

}


