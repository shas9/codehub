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

    string s, t;

    ll change = 0;

    cin >> s >> t;

    ll sz = s.size();

    for(i = 0; i < sz; i++)
    {
        if(s[i] != t[i]) change++;
    }

    if(change % 2 == 1)
    {
        cout << "impossible" << endl;
        return 0;
    }

    change /= 2;

    for(i = 0; i < sz; i++)
    {
        if(change == 0) break;
        if(s[i] != t[i])
        {
            s[i] = t[i];
            change--;
        }
    }

    cout << s << endl;


}


