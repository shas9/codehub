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

vector < ll > mat[200005];

ll chk[200005];


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        mat[i].push_back(0);

        for(j = 1; j <= m; j++)
        {
            slld(input);

            mat[i].push_back(input);
        }
    }

    ll cnt = 0;
    ll done = 0;

    for(i = 1; i <= m; i++)
    {
        for(j = 0; j <= n; j++) chk[j] = 0;

        for(j = 1; j <= n; j++)
        {
            ll xx = mat[j][i];

            xx -= i;

            if(xx % m) continue;

//            cout << i << " - " << j << endl;

            ll pos = xx / m;

            pos++;

            if(pos <= j)
            {
                chk[abs(pos - j)]++;
            }
            else
            {
                chk[abs(n - pos) + j]++;
            }
        }
        ll mx = 0;
        ll mxpos = 0;

        for(j = 0; j <= n; j++)
        {
            ll _xx = chk[j] - j;

//            cout << i << " " << j << " " << _xx << endl;
            if(mx < _xx)
            {
                mx = _xx;
                mxpos = j;

//                if(m == 2)
//                    cout << "MX: " << mx << " " << mxpos << endl;
            }
        }

        cnt += mxpos;
        done += chk[mxpos];
    }

//    cout << cnt << " " << done << endl;
//
//    if(m == 2)
//    {
//        cout << "Done: " << done << endl;
//    }
    cnt += (n * m) - done;

    cout << cnt << endl;

}



