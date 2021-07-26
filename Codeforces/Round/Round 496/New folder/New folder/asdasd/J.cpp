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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

vector < pair < ll , ll > > v;

bool cmp(pair< ll,ll >a, pair< ll, ll >b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second<b.second;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll x, y, a, b;

    cin >> x >> y >> a >> b;

    v.clear();

    for(i = b; i <= y; i++)
    {
        for(j = max(a,i + 1); j <= x; j++)
        {
            v.push_back(make_pair(i,j));
        }
    }

    sort(v.begin(),v.end(),cmp);

    cout << v.size() << endl;

    ll sz = v.size();
    for(i = 0; i < sz; i++)
    {
        cout << v[i].second << " " << v[i].first << endl;
    }

}


