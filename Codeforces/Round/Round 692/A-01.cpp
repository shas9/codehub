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

bool row[100005];
bool col[100005];
vector < pll > v;

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
		cin >> n >> m;

		v.resize(m);

		for(ll i = 1; i <= n; i++) row[i] = col[i] = 0;

		ans = 0;

		for(auto &it: v)
		{
			cin >> it.first; // row;
			cin >> it.second; // col;

			row[it.first] = 1;
			col[it.second] = 1;

			ans += it.first != it.second;
		}

		sort(v.begin(),v.end());

		for(auto it: v)
		{
			if(it.first == it.second) continue;

			if(row[it.second] == 0)
			{
				row[it.first] = 0;
				row[it.second] = 1;
				continue;
			}

			if(col[it.first] == 0)
			{
				col[it.second] = 0;
				col[it.first] = 1;
				continue;
			}

			col[it.second] = 0;
			col[it.first] = 1;

			ans++;
		}

		cout << ans << "\n";
    }


}


