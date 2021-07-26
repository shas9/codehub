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

map < ll, ll > mp;
vector < pair < ll, ll > > v;
map < ll, vector < ll > > mpv;
map < pair < ll, ll >,ll > mpi;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(input);
        mp[input]++;
    }

    v.clear();

    map < ll, ll > :: iterator it;

    for(it = mp.begin(); it != mp.end(); it++)
    {
        ll x = it -> second;
        ll y = it -> first;

        v.pb(make_pair(x,y));
    }

    sort(v.begin(),v.end());

    mpv.clear();

    slld(m);

    ll arr[m + 2];

    for(i = 1; i <= m; i++) slld(arr[i]);
    for(i = 1; i <= m; i++)
    {
        ll x, y;

        x = arr[i];
        cin >> y;

        mpv[x].pb(y);
        mpi[make_pair(x,y)] = i;

//        cout << x << " " << y <<
    }

    ll pos = 0;
    for(i = v.size() - 1; i >= 0;)
    {
        j = i;
        ll mx = -1;
        while(j >= 0)
        {
            if(v[i].first != v[j].first) break;

            ll d = v[j].second;
            ll sz = mpv[d].size();

            for(k = 0; k < sz; k++)
            {
                if(mx < mp[mpv[d][k]])
                {
                    mx = mp[mpv[d][k]];
                    pos = mpi[make_pair(d,mpv[d][k])];

//                    cout << d << " " << mpv[d][k] << " " << mx << endl;
                }
            }
            j--;
        }

        if(pos != 0) break;

        i = j;
    }

    if(pos != 0)
    {
        cout << pos << endl;
        return 0;
    }

    ll mx = -1;
    pos = 1;

    map < pair < ll , ll > , ll > :: iterator itp;

    for(itp = mpi.begin(); itp != mpi.end(); itp++)
    {
        pair < ll , ll > x = itp -> first;
        ll y = itp -> second;

        if(mp[x.second] > mx)
        {
            mx = mp[x.second];
            pos = y;
        }
    }

    cout << pos << endl;





}


