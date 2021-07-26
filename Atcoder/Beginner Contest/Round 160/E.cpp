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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

multiset < ll > red, green;
vector < ll > r, g, cc;

bool comp(ll a, ll b)
{
    return a > b;
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll x, y, a, b, c;

    cin >> x >> y >> a >> b >> c;

    for(i = 0; i < a; i++)
    {
        slld(input);
        r.push_back(input);
    }

    for(i = 0; i < b; i++)
    {
        slld(input);
        g.push_back(input);
    }

    for(i = 0; i < c; i++)
    {
        slld(input);
        cc.push_back(input);
    }

    sort(r.begin(),r.end(),comp);
    sort(g.begin(),g.end(),comp);
    sort(cc.begin(),cc.end(),comp);

    for(i = 0; i < x; i++)
        red.insert(r[i]);

    for(i = 0; i < y; i++)
        green.insert(g[i]);

//    bug;
    for(i = 0; i < c; i++)
    {
        set < ll > :: iterator it1, it2;

        it1 = red.begin();
        it2 = green.begin();


        if((*it1) < (*it2))
        {
//            bug;
            if((*it1) < cc[i])
            {
                red.erase(it1);
                red.insert(cc[i]);
            }
        }
        else
        {
            if((*it2) < cc[i])
            {
                green.erase(it2);
                green.insert(cc[i]);
            }
        }
    }

    ll sum = 0;

    for(set < ll > ::iterator it = red.begin(); it != red.end(); it++) sum += (*it);
    for(set < ll > ::iterator it = green.begin(); it != green.end(); it++) sum += (*it);

    cout << sum << endl;


}



