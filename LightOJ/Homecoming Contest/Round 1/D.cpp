 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

ll arr[100005];
map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        mp.clear();

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        ll ans = 0;

        for(ll i = n; i >= 1; i--)
        {
            if(mp.find(abs(arr[i])) == mp.end())
            {
                mp[abs(arr[i])] = 1;
                ans += arr[i];
            }
        }

        cout << "Case " << cs << ": " << ans << "\n";
    }


}



