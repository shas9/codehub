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

struct node
{
    ll x;
    ll y;
    ll ind;
};

vector < node > v;


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;


    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        node a;

        cin >> a.x >> a.y;
        a.ind = cs;

        v.push_back(a);
    }

    sort(v.begin(),v.end(),comp);

    ll mx = v[0].y;
    ll pos = v[0].ind;

    for(i = 1; i < testcase; i++)
    {
        if(v[i].y <= mx)
        {
            cout << v[i].ind << " " << pos << endl;
            return 0;
        }
        if(mx < v[i].y)
        {
            mx = v[i].y;
            pos = v[i].ind;
        }
    }

    cout << "-1 -1" << endl;

}


