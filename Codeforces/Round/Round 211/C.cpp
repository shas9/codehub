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

    string in, out;

    cin >> in;

    for(i = 0; i < in.size(); i++)
    {
        flag = 0;

        ll sz = out.size();

        if(sz > 1 && out[sz - 1] == out[sz - 2] && out[sz - 1] == in[i])
            flag = 1;

        if(sz > 2 && out[sz - 2] == out[sz - 3] && out[sz - 1] == in[i])
            flag = 1;

        if(flag == 0)
            out += in[i];
    }

    cout << out << endl;


}



