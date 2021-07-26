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

ll arr[100];
vector < ll > v1, v2;

ll solve(ll l, ll r)
{
	ll ret = 0;

	for(auto it: v1)
	{
		if(it > r) continue;

		ll tl = l - it;
		ll tr = r - it;

		ll pos = upper_bound(v2.begin(),v2.end(),tr) - v2.begin();
		pos--;

		ll pos2 = lower_bound(v2.begin(),v2.end(),tl) - v2.begin();

		if(pos < 0) continue;

		ret += (pos - pos2 + 1);
	}

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 0; i < n; i++) slld(arr[i]);

    ll lft = n / 2;
    ll rgt = n - (n / 2);

    for(i = 1; i < (1 << lft); i++)
    {
		ll sum = 0;

		for(ll j = 0; j < lft; j++)
		{
			if(check(i,j)) sum += arr[j];
		}

		v1.push_back(sum);
    }

    v1.push_back(0);
    v2.push_back(0);

    for(i = 1; i < (1 << rgt); i++)
    {
		ll sum = 0;

		for(ll j = 0; j < rgt; j++)
		{
			if(check(i,j)) sum += arr[j + lft];
		}

		v2.push_back(sum);
    }

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

//	for(auto it: v1) cout << it << " ";
//	cout << endl;
//	for(auto it: v2) cout << it << " ";
//	cout << endl;

    slld(m);

    for(i = 1; i <= m; i++)
    {
		slld(l);
		slld(r);

		ans = solve(l,r);

		printf("%lld\n", ans);
    }


}



