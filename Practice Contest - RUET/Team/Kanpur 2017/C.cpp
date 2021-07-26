#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

ll g[1000006];
ll s[1000006];
ll cnt[1000006];

int main()
{
    ll t;

    ll a, b;

    ll n;

    cin >> t;

    for(ll cs = 1; cs <= t; cs++)
    {
        cin >> a >> b;

        a *= b;

        cin >> n;

        for(ll i = 1; i <= n; i++) cin >> g[i];
        for(ll i = 1; i <= n; i++) cin >> s[i];

        sort(g + 1, g + 1 + n);
        sort(s + 1, s + 1 + n);

        ll i = 1, j = n;


        while(i <= n)
        {
            while(j >= 1 && (s[j] * g[i] > a))
            {
                j--;
            }

            cnt[i] = (n - j);

            i++;
        }

//        for(i = 1; i <= n; i++)
//            cout << cnt[i] << endl;

        ll ans = 1;

        for(i = 1; i <= n; i++)
        {
            ans = (ans * (cnt[i] - i + 1)) % mod;
        }

        printf("Case %lld: %lld\n", cs, ans);
    }
}
