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

ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll now = 1;

    for(ll i = 17; i >= 1; i--)
    {
        for(ll j = 1; j * now <= 1e5; j += 2)
        {
            arr[j * now] = i;
        }

        now *= 2;
    }
    while(cin >> n)
    {
        for(ll i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << "\n";
    }


}

