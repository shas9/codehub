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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

map < ll, ll > mp;
deque < ll > dq;

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

		dq.clear();

		slld(n);

		dq.push_back(1);
		dq.push_front(2);

		ll last = 2;

		ll sz = 2;

		ll even = 2, odd = 1;

		while(sz < n)
		{
			ll diff = (even - odd);

			if(diff > 0)
			{
				dq.push_front(last + 2);
				dq.push_back(last + 3);
			}
			else
			{
				dq.push_front(last + 3);
				dq.push_back(last + 2);
			}

			even += dq.front();
			odd += dq.back();

			last = max(dq.front(),dq.back());

			sz += 2;
		}

		if(even != odd)
		{
			cout << "NO" << "\n";
			continue;
		}

		cout << "YES" << "\n";

		for(auto it: dq) cout << it << " ";

		cout << "\n";
    }


}



