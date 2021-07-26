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

ll arr[400005];
ll bitc[400005][25];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        for(j = 0; j <= 24; j++)
        {
            if(check(arr[i],j))
                bitc[i][j] = 1;
            else
                bitc[i][j] = 0;
        }
    }

    for(i = 24; i >= 0; i--)
    {
        for(j = n; j >= 1; j--)
        {
            bitc[j][i] += bitc[j + 1][i];
        }
    }

    ans = 0;


    for(i = 1; i < n; i++)
    {
        ll xx = 0;
        ll pass = 0;


        for(j = 0; j < 25; j++)
        {
            ll cn = bitc[i + 1][j];
            cout << cn << " " << arr[i] << " " << j << endl;

            if(check(arr[i],j))
            {
                cn = (n - i) - cn;

                cn += pass;

                if(cn % 2)
                {
                    bug;
                    xx = Set(xx,j);
                }

                pass = bitc[i + 1][j];
            }
            else
            {
                cn += pass;

                if(cn % 2)
                {
                    bug;
                    xx = Set(xx,j);
                }

                if(bitc[i][j]) pass = 0;

            }
        }

        cout << xx << endl;
        ans ^= xx;
    }

    cout << ans << endl;


}



