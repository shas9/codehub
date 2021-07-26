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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999




using namespace std;


int main()
{
    ll i, j, k, l, o, m, n, p, q, r;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll ans = 0;

    bool row[11];
    bool col[11];

    ll mat[11][11];

    ll high, low, mid;
    for(i = 1; i <= testcase; i++)
    {
        slld(n);
        slld(m);

        for(j = 1; j <= n; j++)
        {
            for(k = 1; k <= m; k++)
            {
                slld(input);

                mat[j][k] = input;
            }
        }

        ans = -1;

        vector < ll > tri;
        ll a, b, c;

        for(j = 1; j <= n; j++)
        {
            for(k = 1; k <= m; k++)
            {
                for(o = 1; o <= n; o++)
                {
                    if(o != j)
                    {
                        for(p = 1; p <= m; p++)
                        {
                            if(p != k)
                            {
                                for(q = 1; q <= n; q++)
                                {
                                    if(q != j && q != o)
                                    {
                                        for(r = 1; r <= m; r++)
                                        {
                                            tri.clear();
                                            if(r != p && r != k)
                                            {
                                                a = mat[j][k];
                                                b = mat[o][p];
                                                c = mat[q][r];

                                                tri.pb(a);
                                                    tri.pb(b);
                                                        tri.pb(c);

                                                        sort(tri.begin(),tri.end());
                                                        //cout << ans << "---" << a << " " << b << " " << c << endl;

                                                        if(tri[0] + tri[1] > tri[2])
                                                        {
                                                            ans = max(ans,a + b + c);
//                                                            cout << ans << "---" << a << " " << b << " " << c << endl;
//                                                            cout << j << "-" << o << "-" << q << "-" << k << "-" << p << "-" << r << endl;
                                                        }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if(ans == -1)
        {
            cout << "RUETOJ ROCKS" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }


}

