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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        if(input == 0)
        {
            cout << "1 1" << endl;
            continue;
        }

        ll sq = (int)sqrt(input);

        if(sq * sq == input)
        {
            cout << -1 << endl;
            continue;
        }

        flag = (sq + 1) * (sq + 1);
        flag -= input;

        //cout << flag << endl;

        ll sq1 = (int)sqrt(flag);

        if(sq1 * sq1 != flag)
        {
            cout << -1 << endl;
            continue;
        }

        cout << sq + 1 << " " << sq1 << endl;


    }


}

