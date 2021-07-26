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

ll dp[1010][1010][2];
ll n, k;
const ll mod = (1e9 + 7);

ll solve(ll pos, ll age, bool dir)
{
//    cout << pos << " " << age << " " << dir << "\n";
    ll &ret = dp[pos][age][dir];

    if(ret != -1) return ret;

    if(pos == 0) return ret = 0;
    if(age == 1) return ret = 0;
    if(pos > n) return ret = 0;

    ret = 0;

    if(dir == 0) ret = solve(pos + 1, age, 0) + 1 + solve(pos - 1, age - 1, 1);
    else ret = solve(pos - 1, age, 1) + 1 + solve(pos + 1, age - 1, 0);

    ret = (ret % mod);

//    cout << pos << " " << age << " " << ret << "\n";

    return ret;
}

int main()
{
    ll i, j, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> k;

        for(ll i = 0; i <= n + 5; i++) for(ll j = 0; j <= k; j++) dp[i][j][0] = dp[i][j][1] = -1;

        ans = solve(1,k,0);

        cout << ans + 1 << "\n";
    }


}


