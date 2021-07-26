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
vector < ll > vec1;

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
		cin >> n;

		vec.resize(n);
		vec1.resize(n);

		for(auto &it: vec) cin >> it.first >> it.second;
		for(auto &it: vec1) cin >> it;

		ll now = 0;

		for(ll i = 0; i < n; i++)
		{
			now += vec1[i] + vec[i].first;

			now -= i ? vec[i - 1].second : 0;

			if(i == (n - 1)) break;

			ll diff = vec[i].second - vec[i].first;

			now += (diff + 1) / 2;

			now = max(now, vec[i].second);
		}

		cout << now << "\n";
    }


}



