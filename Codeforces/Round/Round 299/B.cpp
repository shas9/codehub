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
//    slld(testcase);

    string in;

    //while(1)
    {
    cin >> in;

    ll sz = in.size();

    ll cnt = 0;
    bool on = 1;
    bool off = 1;

    for(i = 1; i < sz; i++)
        cnt += (1 << i);

    for(i = 0; i < sz; i++)
    {
        if(in[i] == '7')
        {
            cnt += (1 << (sz - i - 1));
            continue;
            off = 0;
        }
        on = 0;

        //cnt += 1;
    }

    if(on || off) cnt++;

    cout << cnt << endl;
    }

}

