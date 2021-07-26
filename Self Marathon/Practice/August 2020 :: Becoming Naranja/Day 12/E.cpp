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

string str;

ll solve()
{
    for(ll i = 0; i < str.size(); i++)
    {
        for(ll j = i + 1; j < str.size(); j++)
        {
            for(ll k = j + 1; k < str.size(); k++)
            {
                ll num = (str[i] - '0') * 100 + (str[j] - '0') * 10 + str[k] - '0';

                if(num % 8 == 0) return num;
            }
        }
    }

    for(ll i = 0; i < str.size(); i++)
    {
        for(ll j = i + 1; j < str.size(); j++)
        {
            ll num = (str[i] - '0') * 10 + (str[j] - '0');

            if(num % 8 == 0) return num;
        }
    }

    for(ll i = 0; i < str.size(); i++)
    {
        ll num = (str[i] - '0');

        if(num % 8 == 0) return num;

    }

    return -1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
        ll ans = solve();

        if(ans != -1) cout << "YES\n" << ans << "\n";
        else cout << "NO\n";
    }


}



