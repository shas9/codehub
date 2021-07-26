 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

vector < string > o, z;

void solve1()
{
    string s = "";

    ll p1 = 0, p2 = 0;
    ll z1 = 0, z2 = 0;
    ll sz = o.front().size();

    while(p1 < sz || p2 < sz)
    {
        while(p1 < sz && o.front()[p1] == '0')
        {
            z1++;
            p1++;
        }

        while(p2 < sz && o.back()[p2] == '0')
        {
            z2++;
            p2++;
        }

        for(ll i = 0; i < max(z1, z2); i++) s += '0';

        if(p1 < sz || p2 < sz) s += '1';

        z1 = 0;
        z2 = 0;

        p1++;
        p2++;
    }

    cout << s << "\n";
}

void solve0()
{
    string s = "";

    ll p1 = 0, p2 = 0;
    ll z1 = 0, z2 = 0;
    ll sz = z.front().size();

    while(p1 < sz || p2 < sz)
    {
        while(p1 < sz && z.front()[p1] == '1')
        {
            z1++;
            p1++;
        }

        while(p2 < sz && z.back()[p2] == '1')
        {
            z2++;
            p2++;
        }

        for(ll i = 0; i < max(z1, z2); i++) s += '1';

        if(p1 < sz || p2 < sz) s += '0';

        z1 = 0;
        z2 = 0;

        p1++;
        p2++;
    }

    cout << s << "\n";
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
        o.clear();
        z.clear();

        for(ll i = 1; i <= 3; i++)
        {
            string s;
            cin >> s;

            ll one = 0;

            for(auto it: s) one += it == '1';

            ll zero = 2 * n - one;

            if(one >= n) o.push_back(s);
            if(zero >= n) z.push_back(s);
        }

        if(o.size() >= 2)
        {
            solve1();
        }
        else
        {
            solve0();
        }
    }


}

