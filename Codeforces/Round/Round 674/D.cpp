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

map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        mp.clear();

        ll sum = 0;

        ans = 0;

        mp[0] = 1;

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;

            if(mp.find(sum + in) != mp.end())
            {
                ans++;
                mp.clear();
                sum = 0;
                mp[0] = 1;
            }

            sum += in;
            mp[sum] = 1;
        }

        cout << ans << "\n";
    }

}

