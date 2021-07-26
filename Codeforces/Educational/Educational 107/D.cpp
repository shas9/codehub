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

ll matched[30];

set < pll > st[30];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    fastio;
    while(cin >> n >> k)
    {
        memset(matched,0,sizeof matched);
        for(ll i = 0; i < k; i++) st[i].clear();

        for(ll i = 0; i < k; i++)
        {
            for(ll j = 0; j < k; j++)
            {
                st[i].insert({0,j});
            }
        }

        string s = "a";
        matched[0]++;

        for(ll i = 1; i < n; i++)
        {
            ll ch = s.back() - 'a';

            if(k == 1)
            {
                s.push_back(ch + 'a');
            }
            else
            {
                pll ask = {mxlld, 0};
                ll mm = mxlld;

                for(auto it: st[ch])
                {
                    if(it.first < ask.first)
                    {
                        ask.first = it.first;
                        mm = mxlld;
                    }

                    if(it.first == ask.first)
                    {
                        if(matched[it.second] <= mm)
                        {
                            mm = matched[it.second];
                            ask.second = it.second;
                        }

                    }
                }

//                cout << i << " " << mm << " " << tmm << " " << ask.second << "\n";

                s.push_back(ask.second + 'a');
                st[ch].erase(ask);
                ask.first++;
                st[ch].insert(ask);
                matched[ask.second]++;
            }
        }

        cout << s << "\n";
    }


}


