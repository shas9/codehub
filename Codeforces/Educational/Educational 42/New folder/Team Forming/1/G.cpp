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

string in;
 ll sz;

 string a, b;

bool check(ll pos)
{
    b = "";

    ll z = 0;

    for(ll i = pos; i < sz; i++)
    {
        if(z++ == pos) break;
        b += in[i];
    }

    if(a == b) return true;
    else return false;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> sz >> in;

    ans = 0;

    a = "";
    for(i = 1; i < sz; i++)
    {
        a += in[i - 1];

        if(check(i))
        {
            //cout << i << endl;
            ans = i - 1;
        }
    }

    cout << sz - ans << endl;


}


