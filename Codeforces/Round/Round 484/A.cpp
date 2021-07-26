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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

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
    string in;

    ll x;
    cin >> x >> in;

    bool ch = 1;

    if(x > 2)
    {
        for(i = 0; i < x; i++)
        {
            ll id = in[i] - '0';
            if(i == 0)
            {
                flag = id;
                continue;
            }

            if(id == flag && id == 1) ch = 0;

            flag = id;
        }

        //cout << ch << endl;

        for(i = 1; i < x - 1; i++)
        {
            if(in[i - 1] == in[i + 1] && in[i - 1] == '0' && in[i] == '0') ch = 0;
        }
        if((in[1] == '0' && in[0] == '0') || (in[x - 2] == '0' && in[x - 1] == '0')) ch = 0;
    }

    if(x == 2)
    {
        if(in[0] == in[1]) ch = 0;
    }

    if(x == 1)
        if(in[0] == '0') ch = 0;

    if(ch) cout << "Yes" << endl;
    else cout << "No" << endl;


}


