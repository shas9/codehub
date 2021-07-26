// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n")
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

string str[5005];

void solve()
{

    ll n = str[0].size();

    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            if(str[i][j] == '*')
            {
                for(ll k = 0; k < n; k++)
                {
                    for(ll l = 0; l < n; l++)
                    {
                        if(k == i && l == j) continue;

                        if(str[k][l] == '*')
                        {
                            if(i == k)
                            {
                                str[(i + 1) % n][j] = '*';
                                str[(k + 1) % n][l] = '*';
                            }
                            else if(j == l)
                            {
                                str[i][(j + 1) % n] = '*';
                                str[k][(l + 1) % n] = '*';
                            }
                            else
                            {
                                str[k][j] = '*';
                                str[i][l] = '*';
                            }

                            return;
                        }
                    }
                }
            }
        }
    }

    assert(0);
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

        for(ll i = 0; i < n; i++) cin >> str[i];

        solve();

//        bug(cs);

        for(ll i = 0; i < n; i++) cout << str[i] << "\n";
    }


}

