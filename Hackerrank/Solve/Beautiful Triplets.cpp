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

vector < ll > graph[100000];

ll bame(ll idx, ll lim)
{
	if(graph[idx].empty()) return 0;

	if(graph[idx].back() < lim) return graph[idx].size();

	ll ret = upper_bound(graph[idx].begin(), graph[idx].end(), lim) - graph[idx].begin();

	return ret;

}

ll dane(ll idx, ll lim)
{
	if(graph[idx].empty()) return 0;

	if(graph[idx].front() > lim) return graph[idx].size();

	ll ret = upper_bound(graph[idx].begin(), graph[idx].end(), lim) - graph[idx].begin();

	return graph[idx].size() - ret - 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    slld(m);

    for(i = 1; i <= n; i++)
    {
		slld(input);

		graph[input].push_back(i);
    }

    ans = 0;

    for(i = m; i <= 20000; i++)
    {
		ll lf = i - m;
		ll rg = i + m;

		for(auto it: graph[i])
		{
			ans += (bame(lf,it) * dane(rg,it));
		}
    }

    printf("%lld\n", ans);


}



