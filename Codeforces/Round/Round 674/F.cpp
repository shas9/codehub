// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

string str;

const ll mod = 1e9 + 7;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
        ll a = 0;
        ll b = 0;
        ll ans = 0;

        for(auto it: str)
        {
            if(it == 'a') a++;
            else if(it == 'b') b += a;
            else if(it == 'c') ans += b;
            else
            {
                ans += b;
                b += a;
                a++;
            }

            a %= mod;
            b %= mod;
            ans % mod;
        }

        cout << ans << "\n";
    }

}

