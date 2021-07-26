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

    for(ll cs = 1; cs <= testcase; cs++)
    {
        string s;
        cin >> n >> s;

        ll z = 0;

        for(auto it: s) z += (it == '0');

        string t = s;

        reverse(t.begin(), t.end());

        if(s == t)
        {
            if(z == 1 || z % 2 == 0) cout << "BOB\n";
            else cout << "ALICE\n";
        }
        else
        {
            ll z1 = 0;

            for(ll i = 0, j = n - 1; i <= n / 2; i++, j--)
            {
                z1 += s[i] != s[j];
            }

            if(z == 2 && z1 == 1) cout << "DRAW\n";
            else
            {
                cout << "ALICE\n";
            }
        }
    }


}


