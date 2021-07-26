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

vector < ll > v[3];

ll a, b, c, d;

bool solve()
{


    for(ll i = 0; i < 3; i++) v[i].clear();

    if(a == b && a == 0)
    {
        if(abs(c - d) > 1) return 0;

        for(ll i = 0; i < c + d; i++)
        {
            if(i & 1)
            {
                if(c < d) v[0].pb(2);
                else v[0].pb(3);
            }
            else
            {
                if(c < d) v[0].pb(3);
                else v[0].pb(2);
            }
        }

        return 1;
    }

    if(c == d && c == 0)
    {
        c = a;
        d = b;

        if(abs(c - d) > 1) return 0;

        for(ll i = 0; i < c + d; i++)
        {
            if(i & 1)
            {
                if(c < d) v[0].pb(0);
                else v[0].pb(1);
            }
            else
            {
                if(c < d) v[0].pb(1);
                else v[0].pb(0);
            }
        }

        return 1;
    }


    if(a > b) return 0;
    if(d > c) return 0;

    bool on1 = 0, on2 = 0;

    if(a == b)
    {
        for(ll i = 0; i < a + b; i++)
        {
            v[0].pb(i % 2);
        }

        b = 0;
    }
    else
    {
        for(ll i = 0; i < a + a + 1; i++)
        {
            v[0].pb((i % 2) ^ 1);
        }

        b -= a + 1;

        on1 = 1;
    }

    if(c == d)
    {
        for(ll i = 0; i < c + d; i++)
        {
            v[2].pb((i % 2) + 2);
        }

        c = 0;
    }
    else
    {
        for(ll i = 0; i < d + d + 1; i++)
        {
            v[2].pb((i % 2) + 2);
        }

        c -= d + 1;

        on2 = 1;
    }

    if(abs(b - c) == 1)
    {
        if(b < c && on1)
        {
            v[0].erase(v[0].begin());
            b++;
        }
        else if(c < b && on2)
        {
            v[2].pop_back();
            c++;
        }
    }

    if(b != c) return 0;

    for(ll i = 0; i < b; i++) v[1].pb(2), v[1].pb(1);


    for(auto it: v[1]) v[0].pb(it);
    for(auto it: v[2]) v[0].pb(it);

    return 1;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> a >> b >> c >> d)
    {
        if(solve())
        {
            cout << "YES\n";
            for(auto it: v[0]) cout << it << " ";

            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


}


