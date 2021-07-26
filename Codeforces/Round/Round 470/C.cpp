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

    vector < ll > div;

    div.clear();

    cin >> n >> k;

    for(i = 1; i * i <= n; i++)
    {
        if(n % i != 0) continue;

        div.pb(i);

        if(i * i == n) continue;

        //cout << i << " " << n / i << endl;

        div.pb(n / i);
    }

    sort(div.begin(),div.end());
    if(k > div.size())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << div[k - 1] << endl;
    }

}

