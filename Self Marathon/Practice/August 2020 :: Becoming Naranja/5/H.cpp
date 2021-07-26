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

vector < pll > vec;
ll m, k;

ll solve(ll x, ll pr = 1)
{
	ll cnt = 0;

	ll iv = m / 2 - k;

	ll a = lower_bound(vec.begin(), vec.end(), make_pair(x,mnlld)) - vec.begin();


	if(pr == 0) cout << x << " : ";
	if(pr == 0) cout << a << endl;
	ll y = (x + iv) % m;

	if(pr == 0) cout << y << " : ";
	if(y >= x)
	{
		ll b = upper_bound(vec.begin(), vec.end(), make_pair(y, mxlld)) - vec.begin();
		cnt += (b - a);


	if(pr == 0) cout << b << " ";
	}
	else
	{
		cnt += (vec.size() - a);

		ll b = upper_bound(vec.begin(), vec.end(), make_pair(y, mxlld)) - vec.begin();


	if(pr == 0) cout << b << " ";
		cnt += b;
	}


	if(pr == 0) cout << cnt << endl;

	return cnt;
}

bool inside(ll a, ll b)
{
	ll iv = m / 2 - k;
	ll nxt = m / 2;

	ll l = a;
	ll r = (l + iv) % m;

//	cout << l << " " << r << endl;

	if(l < r)
	{
		if(l <= b && b <= r) return 0;
	}
	else
	{
		if(b >= l || r >= b) return 0;
	}

	l = (a + nxt) % m;

	r = (l + iv) % m;

	if(l < r)
	{
		if(l <= b && b <= r) return 0;
	}
	else
	{
		if(b >= l || r >= b) return 0;
	}

	return 1;
}


int main()
{
    ll i, j, l, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	ll h;

    while(cin >> n >> h >> m >> k)
    {
		vec.resize(n);

		for(ll i = 0; i < n; i++)
		{
			cin >> input >> vec[i].first;
			vec[i].second = i + 1;

		}

		sort(vec.begin(),vec.end());

		ans = 0;
		ll pos = 0;

		for(ll i = 0; i < n; i++)
		{
			ll calc = solve(vec[i].first) + solve((vec[i].first + (m / 2)) % m);

			if(ans < calc)
			{
				ans = calc;
				pos = vec[i].first;
			}
		}

		ll t = pos % (m / 2);

		cout << n - ans << " " << t << "\n";

		for(ll i = 0; i < n; i++)
		{
			if(inside(pos, vec[i].first)) cout << vec[i].second << " ";
		}

		cout << "\n";
    }


}



