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

string str;



int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    assert(1 <= testcase & testcase <= 500);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> str;

        assert(str.size() == n);

        assert(1 <= n && n <= 3000);

        ll ans = 0;

        for(ll i = 0; i < n; i++)
        {
            assert('a' <= str[i] && str[i] <= 'z');

            for(ll j = i; j < n; j++)
            {

                ll vowel = 0;
                for(ll k = i; k <= j; k++)
                {
                    if(str[k] == 'a') vowel++;
                    if(str[k] == 'e') vowel++;
                    if(str[k] == 'i') vowel++;
                    if(str[k] == 'o') vowel++;
                    if(str[k] == 'u') vowel++;
                }


                ll nonvowel = (j - i + 1) - vowel;

                if(vowel + 1 == nonvowel) ans++;
            }
        }

        cout << ans << "\n";
    }

    while(cin >> str)
    {
        assert(0);
    }


}


