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


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    ll x1, x2, y1, y2;
    while(cin >> x1 >> y1 >> x2 >> y2)
    {
        if(x1 == x2)
        {
            ll dist = abs(y1 - y2);

            cout << x1 - dist << " " << y1 << " " << x2 - dist << " " << y2 << "\n";
        }
        else if(y1 == y2)
        {
            ll dist = abs(x1 - x2);

            cout << x1 << " " << y1 - dist << " " << x2 << " " << y2 - dist << "\n";
        }
        else
        {
            if(abs(x1 - x2) != abs(y1 - y2))
            {
                cout << -1 << "\n";
                continue;
            }

            cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
        }
    }



}


