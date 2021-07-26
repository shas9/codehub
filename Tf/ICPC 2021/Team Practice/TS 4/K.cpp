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

vector < ll > v;

ll solve()
{
	ll ret = 1;

	sort(v.begin(),v.end());

	for(ll i = 2; i < v.size(); i++)
	{
		ret *= i;
		ll cnt = 0;

		for(ll j = i; j >= v[i]; j--)
		{
			cnt += v[i] == v[j];
		}

		cout << i << " : " << cnt << "\n";

		ret /= cnt;
	}

	return ret;
}

void brute()
{
	ll n;
	while(cin >> n)
	{
		v.clear();
		v.push_back(-1);

		for(ll i = 1; i <= n; i++)
		{
			ll x;
			cin >> x;
			v.push_back(x);
		}

		cout << solve() << endl;

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
		cin >> n;
		v.clear();
		v.push_back(-1);

		ll now = 2;

		while(n)
		{
			v.push_back(n % now);

			n /= now;

			now++;
		}

		cout << solve() << "\n";
    }


}


