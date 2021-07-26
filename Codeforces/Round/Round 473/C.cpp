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

void incorrect(ll n)
{
    if(n == 2 || n == 3 || n == 4 || n == 5)
    {
        cout << -1 << endl;
        return;
    }


    for(ll i = 2; i <= n - 2; i++)
    {
        cout << "1 " << i << endl;
    }

    cout << "2 " << n - 1 << endl;
    cout << "2 " << n << endl;
}

void correct(ll n)
{
    for(ll i = 2; i <= n; i++)
    {
        cout << "1 " << i << endl;
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(n);

    incorrect(n);
    correct(n);


}

