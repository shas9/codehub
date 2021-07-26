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

vector < ll > vec1, vec2;

bool solve(ll mid, ll l, ll r, ll mx,ll tmx, ll lim)
{
	ll sum = vec2[mid];

	ll tot = (lim - mid + 1);

	if(lim + 1 < vec2.size()) sum -= vec2[lim + 1];

//	cout << mid << ": ";
//	cout << sum << " ";
	sum += (tmx - mx) * tot;
//	cout << sum << " ";
	sum += (l - tmx) * tot;
//	cout << sum << endl;


	return sum <= r;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
		slld(input);
		vec1.push_back(input);
    }

    sort(vec1.begin(),vec1.end());

    ll mx = vec1.back();

    for(auto it: vec1) vec2.push_back(mx - it);

    for(ll i = vec2.size() - 2; i >= 0; i--)
    {
		vec2[i] += vec2[i + 1];
    }
//
//	cout << endl;
//    for(auto it: vec1) cout << it << " ";
//    cout << endl;
//
//    for(auto it: vec2) cout << it << " ";
//
//    cout << endl;

    slld(m);

    for(i = 1; i <= m; i++)
    {
		slld(l);
		slld(r);

		if(vec1.front() >= l)
		{
			printf("%lld\n", n);
			continue;
		}

		auto it = lower_bound(vec1.begin(),vec1.end(),l);
		it--;

		ll lim = it - vec1.begin();

		ll tmx = vec1[lim];

		ll lo = 0;
		ll hi = lim;
		ans = lim + 1;

//		cout << lim << endl;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid,l,r,mx,tmx,lim))
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

		ans = (n - ans);

		cout << ans << '\n';
    }



}



