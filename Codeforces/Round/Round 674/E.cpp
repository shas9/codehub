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

ll arr[2][3];

ll minwin()
{
    ll tarr[2][3];

    for(ll i = 0; i < 2; i++)
    {
        for(ll j = 0; j < 3; j++) tarr[i][j] = arr[i][j];
    }

    ll baad = min(tarr[0][0], tarr[1][2]);

    tarr[0][0] -= baad;
    tarr[1][2] -= baad;

    baad = min(tarr[0][0], tarr[1][0]);

    tarr[0][0] -= baad;
    tarr[1][0] -= baad;

    baad = min(tarr[0][1], tarr[1][0]);

    tarr[0][1] -= baad;
    tarr[1][0] -= baad;

    baad = min(tarr[0][1], tarr[1][1]);

    tarr[0][1] -= baad;
    tarr[1][1] -= baad;

    baad = min(tarr[0][2], tarr[1][1]);

    tarr[0][2] -= baad;
    tarr[1][1] -= baad;

    baad = min(tarr[0][2], tarr[1][2]);

    tarr[0][2] -= baad;
    tarr[1][2] -= baad;

    return tarr[0][0] + tarr[0][1] + tarr[0][2];
}

ll maxwin()
{
    ll tarr[2][3];

    for(ll i = 0; i < 2; i++)
    {
        for(ll j = 0; j < 3; j++) tarr[i][j] = arr[i][j];
    }

    ll baad = min(tarr[0][0], tarr[1][1]);

    tarr[0][0] -= baad;
    tarr[1][1] -= baad;

    baad = min(tarr[0][1], tarr[1][2]);

    tarr[0][1] -= baad;
    tarr[1][2] -= baad;

    baad = min(tarr[0][2], tarr[1][0]);

    tarr[0][2] -= baad;
    tarr[1][0] -= baad;

    ll ret =  tarr[0][0] + tarr[0][1] + tarr[0][2];

//    cout << ret << "\n";

    return ret;
}

ll minwin2()
{
    ll tarr[2][3];

    for(ll i = 0; i < 2; i++)
    {
        for(ll j = 0; j < 3; j++) tarr[i ^ 1][j] = arr[i][j];
    }

    ll baad = min(tarr[0][0], tarr[1][1]);

    tarr[0][0] -= baad;
    tarr[1][1] -= baad;

    baad = min(tarr[0][1], tarr[1][2]);

    tarr[0][1] -= baad;
    tarr[1][2] -= baad;

    baad = min(tarr[0][2], tarr[1][0]);

    tarr[0][2] -= baad;
    tarr[1][0] -= baad;

    for(ll i = 0; i < 3; i++)
    {
        ll baad = min(tarr[0][i], tarr[1][i]);
        tarr[0][i] -= baad;

        cout << tarr[0][i] << " ";
    }

    ll ret =  tarr[0][0] + tarr[0][1] + tarr[0][2];


    return ret;
}

void shift()
{
    ll tarr[2][3];

    for(ll i = 0; i < 2; i++)
    {
        for(ll j = 0; j < 3; j++)
        {
            tarr[i][(j + 1) % 3] = arr[i][j];
        }
    }

    for(ll i = 0; i < 2; i++)
    {
        for(ll j = 0; j < 3; j++)
        {
            arr[i][j] = tarr[i][j];

//            cout << arr[i][j] << " ";
        }

//        cout << "\n";
    }

    return;
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(ll i = 0; i < 2; i++)
        {
            for(ll j = 0; j < 3; j++) cin >> arr[i][j];
        }

        ll mn = mxlld;
        ll mx = mnlld;

        for(ll i = 0; i < 3; i++)
        {
            mn = min(mn, minwin());
            mx = max(mx, n - maxwin());

            shift();
        }

        cout << mn << " " << mx << "\n";
    }


}

