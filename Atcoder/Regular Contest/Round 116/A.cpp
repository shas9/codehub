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
    for(ll i = 1; i <= 100; i++)
    {
        ll cnt1 = 0, cnt2 = 0;

        for(ll j = 1; j * j <= i; j++)
        {
            if(j * j == i)
            {
                if(j & 1) cnt1++;
                else cnt2++;
            }
            else if(i % j == 0)
            {
                if(j & 1) cnt1++;
                else cnt2++;

                if((i / j) & 1) cnt1++;
                else cnt2++;
            }
        }

        cout << i << " = ";

        if(cnt1 > cnt2) cout << "ODD\n";
        else if(cnt1 == cnt2) cout << "SAME\n";
        else cout << "EVEN\n";
    }
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    test();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        n--;

        if(n % 4 == 0 || n % 4 == 2) cout << "Odd\n";
        else if(n % 4 == 1) cout << "Same\n";
        else cout << "Even\n";
    }


}
