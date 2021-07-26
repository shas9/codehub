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

deque < ll > dq1, dq2, dq3;
map < ll, ll > mp;

bool solve(ll n, ll m)
{
	ll cnt = 0;

	ll st = 1;

	ll k = mp.size();

	if((n - k) % (m * 2)) return 0;

	for(ll i = st; i <= n; i++)
	{
		if(mp[i]) continue;

		dq2.push_back(i);
	}

	for(ll i = st; i <= n; i++)
	{
		if(mp[i] == 1)
		{
			while(!dq2.empty() && dq2.front() < i)
			{
				dq1.push_back(dq2.front());
				dq2.pop_front();
			}

			if(dq1.size() >= m && dq2.size() >= m) return 1;
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
		cin >> n >> m >> k;

		m /= 2;

		mp.clear();
		dq1.clear();
		dq2.clear();

		for(ll i = 1; i <= k; i++)
		{
			cin >> input;
			mp[input] = 1;
		}

		if(solve(n, m)) cout << "YES\n";
		else cout << "NO\n";
    }


}



