 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld 1e16
#define mnlld -1e16

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

    while(cin >> n >> k)
    {
        ll mx = mnlld;
        ll mn = mxlld;

        for(ll i = 1; i <= n; i++)
        {
            string str;
            cin >> in >> str;

            if(str.front() == 'S') mx = max(mx, in);
            else mn = min(mn, in);
        }

//        cout << mx << " " << mn << '\n';

        if(abs(mx - mn) == 1)
        {
            cout << mn << " " << mx << "\n";
            continue;
        }

        if(mx == mnlld)
        {
            cout << 2 << " " << mn - 1 << "\n";
        }
        else if(mn == mxlld)
        {
            cout << mx + 1 << " " << k - 1 << "\n";
        }
        else
        {
            cout << mx + 1 << " " << mn - 1 << '\n';
        }
    }


}


