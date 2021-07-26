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

vector < ll > v1, v2;

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
        cin >> n;
        v1.resize(n);
        v2.resize(n);

        for(auto &it: v1) cin >> it;

        for(ll i = 1; i < n; i++)
        {
            ll last = v1[i - 1] ^ v2[i - 1] ;

            if(last & v1[i] == last)
            {
                v2[i] = 0;
                continue;
            }

            ll need = last & (~(v1[i]));
            v2[i] = need;
        }

        for(auto it: v2) cout << it << " ";

        cout << "\n";

    }


}



