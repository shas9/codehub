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

    //freopen("in.txt", "r", stdin);
    slld(testcase);

    vector < pair < ll, ll > >v;

    v.clear();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> i >> j;

        v.pb(make_pair(i,j));
    }

    ll last = 0;
    ll cnt = 1;
    for(i = 0; i < testcase - 1; i++)
    {
        if(i == 0)
        {
            last = v[i].first;
            cnt++;
            continue;
        }

        if(last + v[i].second < v[i].first)
        {
            cnt++;

            //cout << v[i].first << " " << last << " " << v[i].second << endl;
            last = v[i].first;

            continue;
        }

        if(v[i].first + v[i].second < v[i + 1].first)
        {
            cnt++;
            //cout << v[i].first << " " << last << " " << v[i].second << endl;
            last = v[i].first + v[i].second;
            continue;
        }

        last = v[i].first;
    }

    cout << cnt << endl;


}


