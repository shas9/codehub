#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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


ll fig[200005];
ll col[200005];
set < ll > st;

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
        slld(n);

        st.clear();

        bool dd = 0;

        for(i = 1; i <= n; i++)
        {
            slld(fig[i]);

            st.insert(fig[i]);

            if(i > 1)
            {
                if(fig[i] == fig[i - 1]) dd = 1;
            }
        }

        if(fig[1] == fig[n]) dd = 1;

        if(st.size() == 1)
        {
            cout << 1 << endl;
            for(i = 1; i <= n; i++) cout << 1 << " ";
            cout << endl;
            continue;
        }

        if(n % 2 == 0)
        {
            cout << 2 << endl;

            for(i = 1; i <= n; i++)
            {
                if(i % 2) cout << 1 << " ";
                else cout << 2 << " ";
            }

            cout << endl;

            continue;
        }

        if(dd)
        {
            cout << 2 << endl;
            for(i = 1; i <= n; i++)
            {
                if(i == n && dd)
                {
                    if(fig[i] == fig[i - 1])
                    {
                        if(i % 2 == 0) cout << 1 << " ";
                        else cout << 2 << " ";
                    }
                    else cout << 1 << " ";
                }
                else if(i > 1 && dd && fig[i] == fig[i - 1])
                {
                    if(i % 2 == 0) cout << 1 << " ";
                    else cout << 2 << " ";
                    dd = 0;
                }
                else if(dd)
                {
                    if(i % 2) cout << 1 << " ";
                    else cout << 2 << " ";
                }
                else
                {
                    if(i % 2 == 0) cout << 1 << " ";
                    else cout << 2 << " ";
                }
            }

            cout << endl;

            continue;
        }

        cout << 3 << endl;

        for(i = 1; i <= n; i++)
        {
            ll x = i % 3;
            x++;

            if(i == n && (n % 3 == 1))
            {
                x++;
            }

            cout << x << " ";
        }

        cout << endl;
    }


}



