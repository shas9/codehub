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

    while(cin >> n)
    {
        ll t25 = 0, t50 = 0;

        bool on = 1;

        while(n--)
        {
            cin >> in;

            if(in == 25) t25++;
            else if(in == 50)
            {
                if(t25 == 0) on = 0;
                else t25--;
                t50++;
            }
            else
            {
                if(t25 == 0) on = 0;
                else
                {
                    t25--;

                    if(t50) t50--;
                    else if(t25 < 2) on = 0;
                    else t25 -= 2;
                }
            }
        }


            if(on) cout << "YES\n";
            else cout << "NO\n";
    }


}

