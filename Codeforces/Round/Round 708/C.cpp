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

void solve(ll n)
{
	if(n & 1)
		{
			cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2 << "\n";
		}
		else if(n % 4 == 0)
		{
			cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
		}
		else
		{
			cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << "\n";
		}

		return;
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
		cin >> n >> k;

		if(k == 3)
		{
			solve(n);
			continue;
		}

		ll sz = 0;
		ll now = n / 2;
		ll sum = 0;
		if(now & 1) now--;
		v.clear();

		if(now <= 0) now = 1;

		while(sz < k)
		{
			sum += now;
			sz++;
			v.push_back(now);
			now -= 2;
			if(now <= 0) now = 1;
		}

		sum -= n;

		for(ll i = k - 1; i >= 0; i--)
		{
			ll diff = v[i] - 1;
			ll biyog = min(diff, sum);
			v[i] -= biyog;
			sum -= biyog;
		}

		for(ll i = k -1; i >= 0; i--)
		{
			if(sum < 0)
			{
				sum++;
				v[i]++;
			}
		}

		for(auto it: v) cout << it << " ";
		cout << "\n";
    }


}



