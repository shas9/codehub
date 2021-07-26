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

void conv(string &s, string &t, ll n)
{
    s = "";
    ll x = t.size();

    for(ll i = 0; i < n; i++)
    {
        s.push_back(t[i % x]);
    }

    return;
}

void comp(string &s, string &t)
{
    ll n = s.size();

    for(ll i = 0; i < n; i++)
    {
        if(s[i] < t[i]) return;
        if(s[i] > t[i])
        {
            s = t;
            return;
        }
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        string org, tmp;
        string s;

        cin >> s;

        conv(org, s, m);

        while(--n)
        {
            s.pop_back();

            conv(tmp, s, m);
            comp(org, tmp);
        }

        cout << org << "\n";
    }


}

