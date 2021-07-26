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

ll arr[10005];

char c[10005];

bool f;

ll n;
void solve(ll pos, ll ans)
{
    //cout << ans << endl;

    if(ans % 101 == 0)
    {
        f = 1;
        return;
    }

    if(pos > n)
    {
        return;
    }
    c[pos-1] = '+';
    solve(pos + 1, ans + arr[pos]);

    if(f) return;

    c[pos-1] = '-';
    solve(pos + 1, ans - arr[pos]);

    if(f) return;

    c[pos-1] = '*';
    solve(pos + 1, ans * arr[pos]);



}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    f = 0;
    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
        c[i] = 'N';
    }

    solve(2,arr[1]);

    for(i = 1; i < n; i++)
    {
        cout << arr[i];

        //cout << f << endl;
        if(c[i] == 'N')
        {
            //bug;
            cout << '*';
        }
        else cout << c[i];
    }


    cout << arr[n];

    cout << endl;






}



