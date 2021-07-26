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

vector < vector < ll > > vec;

ll ask(ll l, ll r)
{
	cout << "? " << (r - l + 1) << " ";

	for(ll i = l; i <= r; i++) cout << i << " ";

	cout << endl;

	ll ret;

	cin >> ret;

	return ret;
}

ll pr[10033];
void solve(ll n)
{
	ll l = 1, r = n;

	ll mx = ask(l,r);

	while(l < r)
	{
		ll mid = (l + r)/ 2;

		if(ask(l,mid) == mx) r = mid;
		else l = mid + 1;
	}

	ll idx = -1;

	for(ll i = 0; i < vec.size(); i++)
	{
		for(auto it: vec[i])
		{
			if(it == l) idx = i;
		}

		if(idx != i) pr[i] = mx;
	}

	if(idx != -1)
	{
		cout << "? " << n - vec[idx].size() << " ";

		for(ll i = 1; i <= n; i++)
		{
			bool ase = 0;

			for(auto it: vec[idx]) if(it == i)ase = 1;

			if(ase == 0) cout << i << " ";
		}

		cout << endl;

		cin >> pr[idx];
	}

	cout << "! ";

	for(ll i = 0; i < vec.size(); i++)
	{
		cout << pr[i] << " ";
	}

	cout << endl;

	string str;

	cin >> str;

	if(str[0] == 'I')
	{
		assert(0);
		exit(0);
	}
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
		vec.clear();
		cin >> n >> k;

		for(i = 0; i < k; i++)
		{
			slld(input);

			vec.push_back({});

			while(input--)
			{
				slld(m);
				vec.back().push_back(m);
			}
		}

		solve(n);
    }


}


