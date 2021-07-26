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

vector < pll > sq;
vector < ll > v;
ll freq[1000006];

bool solve(ll n, ll baad)
{
//	cout << baad << endl;

	for(auto it: v)
	{
		freq[it] = 0;
	}


	for(auto it: v)
	{
		freq[it]++;
	}

	freq[v[baad]]--;
	freq[v.back()]--;

	ll now = v.back();

	sq.clear();

	sq.push_back({v.back(), v[baad]});

	for(ll i = n - 1; i >= 0; i--)
	{
//		cout << now << "++\n";

		if(freq[v[i]] == 0) continue;

		freq[v[i]]--;

		ll need = now - v[i];

		if(freq[need] == 0) return 0;

		freq[need]--;

		sq.push_back({need, v[i]});

		now = v[i];
	}

//	bug;

	return 1;
}

ll calc(ll n)
{
	for(ll i = 0; i < n - 1; i++)
	{
		if(solve(n, i))
		{
			return v.back() + v[i];
		}
	}

	return -1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    memset(freq,0,sizeof freq);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		n *= 2;

		v.resize(n);

		for(auto &it: v) cin >> it;

		sort(v.begin(),v.end());

		ans = calc(n);

		if(ans != -1)
		{
			cout << "YES\n";
			cout << ans << "\n";

			for(auto it: sq)
			{
				cout << it.first << " " << it.second << "\n";
			}
		}
		else
		{
			cout << "NO\n";
		}

		for(auto it: v) freq[it] = 0;
    }


}


