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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct info
{
	ll ans;
	ll par_node;
	ll avail_col;
	ll freq;
} arr[1000005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    arr[1].ans = 0;
    arr[1].par_node = 0;
    arr[1].avail_col = 1;
    arr[1].freq = 0;

    ll idx = 1;

    ans = 0;

    for(ll i = 2; i <= n + 1; i++)
    {
		ll par;

		slld(par);

		if(arr[par].freq == 2)
		{
			arr[par].avail_col = ++idx;
			arr[par].freq = 0;
		}

		arr[i].par_node = arr[par].avail_col;
		arr[par].freq++;
		arr[i].avail_col = arr[par].avail_col;
		arr[i].freq = 1;
		arr[i].ans = arr[par].ans;

		if(arr[par].par_node != arr[i].par_node) arr[i].ans++;

		ans = max(ans,arr[i].ans);

		printf("%lld ", ans);
    }

    printf("\n");


}


