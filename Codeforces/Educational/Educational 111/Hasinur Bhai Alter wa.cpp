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

    cin >> testcase;

    assert(1 <= testcase && testcase <= 100000);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll x1, x2, x3, x4;
        ll y1, y2, y3, y4;

        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        cin >> x4 >> y4;

        assert(1 <= x1 && x1 <= 100000);
        assert(1 <= x2 && x2 <= 100000);
        assert(1 <= x3 && x3 <= 100000);
        assert(1 <= x4 && x4 <= 100000);

        assert(1 <= y1 && y1 <= 100000);
        assert(1 <= y2 && y2 <= 100000);
        assert(1 <= y3 && y3 <= 100000);
        assert(1 <= y4 && y4 <= 100000);


        if((x1 == x2 && y1 == y2))
        {
            cout << "no\n";
            continue;
        }

        if((x1 == x3 && y1 == y3))
        {
            cout << "no\n";
            continue;
        }

        if((x1 == x4 && y1 == y4))
        {
            cout << "no\n";
            continue;
        }

        if((x4 == x2 && y4 == y2))
        {
            cout << "no\n";
            continue;
        }

        if((x3 == x2 && y3 == y2))
        {
            cout << "no\n";
            continue;
        }

        if((x3 == x4 && y3 == y4))
        {
            cout << "no\n";
            continue;
        }


        if(x1 == x3) swap(x3, x2), swap(y3, y2);
        else if(x1 == x4) swap(x4, x2), swap(y4, y2);
        else if(x1 == x2);
        else
        {
            cout << "no\n";
            continue;
        }

        if(x3 != x4)
        {
            cout << "no\n";
            continue;
        }

        if(y1 == y4) swap(x3,x4), swap(y3,y4);

        if(y1 != y3)
        {
            cout << "no\n";
            continue;
        }

        if(y2 != y4)
        {
            cout << "no\n";
            continue;
        }


        cout << "yes\n";

    }


}

