 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll mod = 998244353;

ll ncr[200205][25];

ll nCr(ll n, ll r)
{
//    cout << n << " " << r << "\n";
    if(r == 0) return 1;

	if(r == 1) return n;

	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}

ll solve(ll num, ll m, ll n)
{
    vector < ll > vec;
    vec.push_back(1);
    ll x = num;

    while(num * x <= m)
    {
        num *= x;
        vec.push_back(num);
    }

    ll sz = vec.size();

    ll ret = 0;

    for(ll i = 0; i < (1LL << sz); i++)
    {
        ll cnt = 1;

        for(ll j = 0; j < sz; j++) cnt += check(i,j);

        if(cnt > n) continue;
        if(cnt == n)
        {
            ret++;
            continue;
        }


        ll baki = n - cnt;

//        cout << baki + cnt - 1 << " " << cnt - 1 << "\n";

        ret = (ret + nCr(n - 1, cnt - 1)) % mod;
    }

    return ret;
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(ncr,-1,sizeof ncr);

    while(cin >> n >> m)
    {
        ans = 1;

        for(ll i = 2; i <= m; i++)
        {
            ans = (ans + solve(i,m,n)) % mod;
        }

        cout << ans << "\n";
    }


}

