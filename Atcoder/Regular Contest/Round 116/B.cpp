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

vector < ll > vec;
const ll mod = 998244353;

void test()
{
    ll a[] = {853983, 14095, 543053, 143209, 4324, 524361, 45154};

    ll sum = 0;

    for(ll i = 1; i < (1 << 7); i++)
    {
        ll mx = 0;
        ll mn = mxlld;

        for(ll j = 0; j < 7; j++)
        {
            if(check(i,j) == 0) continue;

            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
        }

        sum = (sum + mx * mn) % mod;
    }

    cout << sum << "\n";
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    test();

    while(cin >> n)
    {
        vec.resize(n);

        for(auto &it: vec) cin >> it;

        sort(vec.begin(), vec.end());

        ll gun = 0;
        ll ans = 0;

        for(ll i = n - 1; i >= 0; i--)
        {
            ans = (ans + (vec[i] * vec[i])) % mod;
            ans = (ans + (vec[i] * gun)) % mod;

            gun = ((gun * 2LL) + vec[i]) % mod;

//            cout << ans << " " << gun << "\n";
        }

        cout << ans << "\n";
    }

}

