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

vector < ll > vec;

const ll mod = 1000000007;

ll ncr[1001][1001];

ll nCr(ll n, ll r)
{
	if(r == 1) return n;

	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

	memset(ncr,-1,sizeof ncr);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m;

		vec.resize(n);

		for(auto &it: vec) cin >> it;

		sort(vec.rbegin(), vec.rend());

		ll num = vec[m - 1];
		ll cnt = 0;
		ll cnt2 = 0;

		for(auto it: vec)
		{
			cnt += it == num;
		}

		for(ll i = 0; i < m; i++)
		{
			cnt2 += vec[i] == num;
		}

		ans = nCr(cnt, cnt2);

		cout << ans << "\n";



    }


}


