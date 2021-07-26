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
    ll input, flag, tag, ans, rep;

    // freopen("in.txt", "r", stdin);

    string in;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ans = 0;
        cin >> in;

        ll sz = in.size();


        rep = 0;

        for(i = 0; i < sz; i++)
        {
            if(in[i] == '0')
            {
                flag = rep * (rep + 1);
                flag /= 2;

                ans += flag;
                rep = 0;
            }
            else rep++;
        }

        flag = rep * (rep + 1);
                flag /= 2;

                ans += flag;
                rep = 0;
        cout << ans << endl;
    }


}


