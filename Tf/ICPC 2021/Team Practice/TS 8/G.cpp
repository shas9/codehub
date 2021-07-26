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

vector < ll > dig;

void solve()
{
    reverse(dig.begin(), dig.end());

    for(ll i = 0; i < 9; i++)
    {
        if(dig[i] >= 5) cout << '0';
        else cout << '1';
    }

    cout << "\n";

    for(ll i = 0; i < 9; i++)
    {
        if(dig[i] < 5) cout << '0';
        else cout << '1';
    }

    cout << "\n";

    for(ll i = 0; i < 9; i++)
    {
        cout << '-';
    }

    cout << "\n";

    for(ll j = 0; j < 5; j++)
    {
        for(ll i = 0; i < 9; i++)
        {
            if(dig[i] % 5 == j) cout << '0';
            else cout << '1';
        }

        cout << "\n";
    }

    return;

}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        dig.clear();

        while(n)
        {
            dig.push_back(n % 10);
            n /= 10;
        }

        while(dig.size() < 9) dig.push_back(0);

        solve();

        cout << "\n";
    }


}

