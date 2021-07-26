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
ll dp[103][103][5];

ll solve(ll pos, ll tana, ll num)
{
	ll &ret = dp[pos][tana][num];

	if(ret != -1) return ret;

	ret = 0;

	if(pos == vec.size()) ret = tana / 2;
	else if(vec[pos] == 0) ret = solve(pos + 1, 0, 4) + 1 + (tana / 2);
	else if(vec[pos] == num) ret = solve(pos + 1, tana + 1, num);
	else if(vec[pos] == 1 || vec[pos] == 2) ret = solve(pos + 1, 1, vec[pos]) + tana / 2;
	else ret = min(solve(pos + 1, tana + 1, num), solve(pos + 1, 1, num == 1 ? 2 : 1) + tana / 2);

//	cout << pos << " " << tana << " " << num << " : " << ret << endl;

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.resize(n);
		memset(dp,-1,sizeof dp);

		for(auto &ut: vec) cin >> ut;

		ans = solve(0,0,4);

		cout << ans << "\n";
    }

}



