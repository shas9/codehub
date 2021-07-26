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

ll col[200005];
ll fig[200005];

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

        for(i = 1; i <= n; i++)
        {
            slld(fig[i]);
        }

        ll mx = 0;

        for(i = 1; i <= n; i++)
        {
            if(i == 1) col[i] = 1;
            else if(i == n)
            {
                if(fig[i - 1] != fig[1] && fig[1] != fig[i] && fig[i - 1] != fig[i])
                {
//                    cout << col[i - 1] << " " << col[i] << " " << col[1] << endl;
                    col[i] = 3;
                }
                else if(fig[1] != fig[n])
                {
                    if(col[1] == 1) col[n] = 2;
                    else col[n] = 1;
                }
                else if(fig[i - 1] != fig[i])
                {
                    if(col[i - 1] == 1) col[n] = 2;
                    else col[n] = 1;
                }
                else
                {
                    col[i] = col[i - 1];
                }
            }
            else
            {
                if(fig[i] == fig[i - 1]) col[i] = col[i - 1];
                else
                {
                    if(col[i - 1] == 1) col[i] = 2;
                    else col[i] = 1;
                }
            }

            mx = max(mx, col[i]);
        }

        cout << mx << endl;

        for(i = 1; i <= n; i++)
        {
            cout << col[i] << " ";
        }

        cout << endl;
    }



}



