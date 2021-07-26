/*

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
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
        string s, c;

        cin >> s >> c;

        bool done = 1;

        for(i = 0; i < min(s.size(), c.size()) && done; i++)
        {
            if(s[i] >= c[i])
            {
                for(j = i + 1; j < s.size(); j++)
                {
                    if(s[j] < c[i])
                    {
                        cout << j << " " << i << endl;
                        cout << s << " ";
                        swap(s[j],s[i]);

                        cout << s << endl;
                        done = 0;
                        break;
                    }
                }
            }
            else
            {
                cout << i << " ~~ " << endl;
                done = 0;
            }
        }

        if(done)
        {

            for(i = 0; i < min(s.size(), c.size()) && done; i++)
            {
                if(s[i] >= c[i])
                {
                    for(j = i + 1; j < s.size(); j++)
                    {
                        if(s[j] < c[i])
                        {
                            cout << j << " " << i << endl;
                            cout << s << " ";
                            swap(s[j],s[i]);

                            cout << s << endl;
                            done = 0;
                            break;
                        }
                    }

                    if(done)
                    {
                        for(j = i + 1; j < min(s.size(),c.size()); j++)
                        {
                            if(s[j] <= c[i] && s[i] < c[j])
                            {
                                bug;
                                swap(s[i],s[j]);
                                done = 0;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    cout << i << " ~~ " << endl;
                    done = 0;
                }
            }
        }

        if(!done)
        {
            cout << s << "\n";
        }
        else
        {
            cout << "---" << "\n";
        }
    }


}




