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

string s1, s2;

ll solve(ll n)
{
    for(ll i = 0; i < n; i++)
    {
        if(s1[i] > s2[i]) return -1;
    }

    ll ret = 0;
    for(char c = 'a'; c <= 't'; c++)
    {
        char mn = 'z';

        for(ll i = 0; i < n; i++)
        {
			if(s1[i] == c && s2[i] != c) mn = min(mn, s2[i]);
        }

        for(ll i = 0; i < n; i++)
        {
			if(s1[i] == c && s2[i] != c) s1[i] = mn;
        }

        ret += mn != 'z';
    }

    return ret;
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
        cin >> n >> s1 >> s2;

        ans = solve(n);

        cout << ans << "\n";
    }


}


