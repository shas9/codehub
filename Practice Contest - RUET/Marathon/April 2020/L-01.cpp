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
		slld(k);

		if(k <= 4 || n == k)
		{
			printf("-1\n");
			continue;
		}

		if(2 * (k - 2) > n)
		{
			k-=2;
			cout << string(k / 2, '(') << string(k / 2, ')') << string((n - k) / 2, '(') << string((n - k) / 2, ')');
			cout << "\n";
			continue;
		}

		ll d = (n / (k - 2));
		ll e = (n % (k - 2));

		cout << string(e/2,'(');
		for(i = 1; i <= d; i++)
		{
			cout << string((k - 2)/2, '(') << string((k - 2)/2, ')');
		}
		cout << string(e/2, ')');

		cout <<"\n";
    }


}



