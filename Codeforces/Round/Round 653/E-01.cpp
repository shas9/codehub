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

vector < ll > ab, a, b, no;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n >> k >> m)
    {
		ab.clear();
		a.clear();
		b.clear();
		no.clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);
			slld(r);
			slld(q);

			if(r && q) ab.push_back(input);
			else if(r) a.push_back(input);
			else if(q) b.push_back(input);
			else no.push_back(input);
		}

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(ab.begin(),ab.end());

		ans = 0;
		ll idx = min(a.size(),b.size());

		idx = min(k,idx);

		for(ll i = 0; i < idx; i++)
		{
			ans += (a[i] + b[i]);
		}

		ll need = k - idx;

		if(need > ab.size())
		{
			cout << -1 << '\n';
			continue;
		}

		idx--;
		for(i = 0; i < need; i++)
		{
			ans += ab[i];
		}

		cout << ans << '\n';
    }


}




