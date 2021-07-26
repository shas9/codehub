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

bool poss(ll x, string &s, ll st)
{
    if(st == s.size()) return 1;

    ll y = 0;

    for(ll i = st; i < s.size(); i++)
    {
        y *= 10;
        y += s[i] - '0';
        if(y == 0) return 0;

        if(x < y)
        {
            if(x + 1 == y) return poss(y, s, i + 1);
            return 0;
        }
    }

    return 0;
}

bool yes(ll x)
{
    string s = "";

    while(x)
    {
        s += (x % 10) + '0';
        x /= 10;
    }

    reverse(s.begin(), s.end());

    ll num = 0;

    for(ll i = 0; i + 1 < s.size(); i++)
    {
        num *= 10;
        num += s[i] - '0';

        if(poss(num, s, i + 1))
        {
            return 1;
        }
    }

    return 0;
}

set < ll > st;

void gen()
{
    for(ll i = 100000; i <= 1000000; i++)
    {
        if(yes(i))
        {
            cout << i << "\n";
//            st.insert(i);
        }
    }
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


//    yes(120);
    gen();


    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        auto it = st.upper_bound(n);
        cout << "Case #" << cs << ": " << *it << '\n';
    }


}

