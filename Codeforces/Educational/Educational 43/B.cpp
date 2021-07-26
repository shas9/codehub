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

    cin >> n >> m;

    while(1)
    {
    cin >> k;

    ll posx = 1, posy = 1;

    if(k < n)
    {
        posx += k;

        cout << posx << " " << posy << endl;

        continue;
    }

    k -= n - 1;

    if(k < m)
    {
        posx = n;
        posy += k;

        cout << posx << " " << posy << endl;

        continue;
    }

    k -= m - 1;

    //cout << k << endl;

    ll temp = k % (m - 1);

    if(temp == 0) temp = m - 1;
    ll temp1 = k / (m - 1);

    if(k % (m - 1)) temp1++;

    //cout << k << endl;
    posx = n - (temp1);

    if(n % 2 == 0)
    {
        if(posx % 2)posy = m - temp + 1;
        else posy = m - temp - 1;
    }
    else
    {
        if(posx % 2 == 0)posy = m - temp + 1;
        else posy = m - temp - 1;
    }


    cout << posx << " " << posy << endl;

    }
}


