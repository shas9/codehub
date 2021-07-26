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

string s[1000];

bool solve(ll n)
{
    for(ll i = 0; i < 26; i++)
    {
        ll cnt = 0;

        for(ll j = 0; j < n; j++) for(auto it: s[j]) cnt += (it == ('a' + i));

        if(cnt % n) return 0;
    }

    return 1;
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
        cin >> n;

        for(ll i = 0; i < n; i++) cin >> s[i];

        if(solve(n)) cout << "YES\n";
        else cout << "NO\n";
    }


}

