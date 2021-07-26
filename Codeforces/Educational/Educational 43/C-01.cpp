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

#define maxn 10000000000


using namespace std;

map < pair < ll, ll > , ll > mp;
vector < pair < ll, ll > > v;

pair < ll, ll > ans;

ll lb(ll high, ll n)
{
    ll low = 0;
    ll ans = 0;

    while(low <= high)
    {
        ll mid = high + low;
        mid /= 2;

        if(v[mid].first == n)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(v[mid].first > n)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }

    return ans;
}

ll check(ll pos)
{
    ll x = v[pos].first;
    ll y = v[pos].second;
    //ll b = lb(v.size() - 1,x);

    ll sz = v.size();

    for(ll i = 0; v[i].first <= x && i < sz; i++)
    {
        if(i == pos) continue;

        //cout << y << " " << v[i].first << " " << v[i].second << endl;
        if(y <= v[i].second)
        {
            return i;
        }
    }

    return -1;
}

void solve()
{
    ll i, j, k;

    ll sz = v.size();
    for(i = 0; i <= sz - 1; i++)
    {
        j = check(i);
        //cout << i << " " << j << endl;
        if(j != -1)
        {

            ans.first = mp[v[i]];
            ans.second = mp[v[j]];

            if(ans.first == ans.second)
            {
                ans.first = mp[make_pair(v[i].first + maxn, v[i].second)];
            }
            return;
        }
    }

    ans.first = -1;
    ans.second = -1;
}
int main()
{
    ll i, j, k, l, m, n, o, r;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    v.clear();
    mp.clear();


    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(l);
        slld(r);

        if(mp[make_pair(l,r)])
        {
            mp[make_pair(l + maxn,r)] = cs;
        }
        else mp[make_pair(l,r)] = cs;
        v.pb(make_pair(l,r));
        //cout << " - " << v[cs - 1].first << " " << v[cs - 1].second << endl;
    }

    sort(v.begin(),v.end());

    solve();

    cout << ans.first << " " << ans.second << endl;

}


