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

bool solve()
{
    string str;
    ll l, r;
    cin >> str;

        l = r = -1;

        for(ll i = 0; i < str.size(); i++)
        {
            if(str[i] == 'a')
            {
                l = r = i;
            }
        }

    if(l == -1) return 0;

    for(ll i = 1; i < 26; i++)
    {
        if(l == 0 && r == str.size() - 1) break;

        char c = i + 'a';

        if(l && str[l - 1] == c)
        {
            l--;
        }
        else if(r + 1 < str.size() && str[r + 1] == c)
        {
            r++;
        }
        else return 0;
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
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }


}



