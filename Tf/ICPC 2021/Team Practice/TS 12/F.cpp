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

void test()
{
    double last = -100000.0;
    ll cnt = 0;

    for(ll i = -(1e7); i <= 1e7; i++)
    {
//        cout << i << " = " << sin(i) << " " << cos(i) << " " << sin(i) * cos(i) << "\n";
        if(last < sin(i) * cos(i))
        {
            last = sin(i) * cos(i);
            cnt++;
        }
    }

    cout << cnt << "\n";

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    test();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

    }


}

