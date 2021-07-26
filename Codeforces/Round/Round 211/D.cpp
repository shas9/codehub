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

vector < ll > pers;
vector < ll > bikes;
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;
    ll a;

    // freopen("in.txt", "r", stdin);

    cin >> n >> m >> a;

    for(i = 1; i <= n; i++)
    {
        slld(input);
        pers.pb(input);
    }

    for(i = 1; i <= m; i++)
    {
        slld(input);
        bikes.pb(input);
    }

    sort(pers.begin(),pers.end());
    sort(bikes.begin(),bikes.end());

    ll cnt = 0;
    ll spend = 0;
    j = 0;
    for(i = 0; i < n; i++)
    {
        if(j == m) break;
        if(pers[i] >= bikes[j])
        {
            cnt++;
            spend += bikes[j];
            j++;
            continue;
        }

        if((a - abs(pers[i] - bikes[j])) < 0)
        {
            continue;
        }

        a -= abs(pers[i] - bikes[j]);

        spend += pers[i];

        cnt++;
        j++;

        //cout << cnt << " : " << a << endl;
    }

    spend -= a;

    if(spend < 0) spend = 0;

    cout << cnt << " " << spend << endl;


}



