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

vector < pair < ll, ll > > coins;

ll arr[2000000];

map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(testcase);

    while(testcase--)
    {

        mp.clear();
        memset(arr,0,sizeof arr);
        coins.clear();

        ll c;
        slld(c);
        slld(m);

        for(i = 1; i <= c; i++)
        {
            slld(input);

            mp[input] = 1;

            arr[input] += input;
        }


        map < ll, ll > :: iterator it;

        for(it = mp.begin(); it != mp.end(); it++)
        {
            ll x = it -> first;
            coins.pb(make_pair(arr[x],x));
        }

        sort(coins.begin(),coins.end());

        ll sz = coins.size();

        bool on = 0;

        ll sum = 0;

        vector < ll > v;
        v.clear();

        for(i = sz - 1; i >= 0; i--)
        {
            sum += coins[i].first;

            //cout << coins[i].first << " :: " << coins[i].second << endl;

            v.pb(coins[i].second);
            if(sum >= m) break;
        }

        //cout << sum << endl;

        if(sum < m)
        {
            cout << "Impossible" << endl;
            continue;
        }

        sort(v.begin(),v.end());
        sz = v.size();
        for(i = 0; i < sz; i++)
        {
            cout << v[i] << " ";
        }

        cout << endl;
    }




}

