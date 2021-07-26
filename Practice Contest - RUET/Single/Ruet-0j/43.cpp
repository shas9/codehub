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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    vector < ll > A;
    vector < ll > B;

    slld(testcase);

    ll arrsize, Q;

    ll L, R;

    for(i = 1; i <= testcase; i++)
    {
        A.clear();
        B.clear();

        slld(arrsize);
        slld(Q);

        A.pb(1);
        B.pb(1);


        for(j = 1; j <= arrsize; j++)
        {
            slld(input);

            A.pb(input);

        }

        for(j = 1; j <= arrsize; j++)
        {
            slld(input);

            B.pb(input);
        }

        for(j = 1; j <= arrsize; j++)
        {
            A[j] *= A[j - 1];
            B[j] *= B[j - 1];
        }

        ll ans1, ans2;

        printf("Case %lld:\n", i);

        for(j = 1; j <= Q; j++)
        {
            slld(L);
            slld(R);

            ans1 = A[R] / A[L-1];
            ans2 = B[R] / B[L-1];

            //cout << ans1 << " " << ans2 << endl;

            if(ans1 == ans2)
            {
                cout << "=" << endl;
            }
            else if(ans1 > ans2)
            {
                cout << ">" << endl;
            }
            else
            {
                cout << "<" << endl;
            }
        }

    }


}

