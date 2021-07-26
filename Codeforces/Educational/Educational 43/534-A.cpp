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

    cin >> n;

    if(n == 2)
    {
        cout << 1 << endl << 1 << endl;
        return 0;
    }

    if(n == 4)
    {
        cout << 4 <<endl << "3 1 4 2" << endl;
        return 0;
    }
    ll cnt = 0;

    cnt += (n / 2);

    if(n % 2) cnt++;

    if(n % 2)
    {
        if(n != 3)
        {
           cnt += (n / 2);
        }
    }
    else
    {
        if((n - 1) != 3)
        {
            cnt += (n / 2);
        }
    }

    cout << cnt << endl;

    for(i = 1; i <= n; i++)
    {
        if(i % 2)
        {
            cout << i << " ";
            ans = i;
        }
    }

    if(ans == 3) return 0;

    for(i = 2; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            cout << i << " ";
            ans = i;
        }
    }

    cout << endl;


}


