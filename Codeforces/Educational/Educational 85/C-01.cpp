/*

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

pll arr[300005];
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
        ll tmp = 0;

        slld(n);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].first);
            slld(arr[i].second);
        }

        for(i = 1; i <= n; i++)
        {
            ll prv = i - 1;

            if(i == 1) prv = n;

            if(arr[prv].second < arr[i].first) tmp += arr[i].first - ar
        }
    }


}


