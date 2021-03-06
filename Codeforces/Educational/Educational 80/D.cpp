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

ll arr[300005][10];
ll n, m;


pair < ll, pair < ll, ll > > solve(ll mid)
{
    ll cnt = 0;
    ll dd = (1 << m) - 1;

    set < ll > st;
    map < ll, ll > mp;

    ll ind1 = 0, ind2 = 0;

    ll ok = 0;

//    cout << mid << endl;

    for(ll i = 1; i <= n; i++)
    {
        ll mask = 0;

        for(ll j = 1; j <= m; j++)
        {
            if(arr[i][j] >= mid)
            {
                mask = Set(mask,j - 1);
            }
        }

//        cout << mask << " ";

        st.insert(mask);
        mp[mask] = i;

        if(mask == dd)
        {
            return make_pair(1,make_pair(i,i));

        }
    }

//    cout << endl;

    ind1 = 0;
    ind2 = 0;

    for(ll i = 0; i <= dd; i++)
    {
        if(mp.find(i) == mp.end()) continue;

        ind1 = mp[i];

        for(auto it:st)
        {
            ind2 = mp[it];

//            cout << (it | i) << endl;

            if((it | i) == dd)
            {
//                bug;
                return make_pair(1,make_pair(ind1,ind2));
            }
        }
    }


    return make_pair(0,make_pair(1,2));

}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                slld(arr[i][j]);
            }
        }

        ll lo = 0;
        ll hi = 1000000000;
        pair < ll, pair < ll, ll > > anss;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            pair < ll, pair < ll, ll > > dd = solve(mid);

            if(dd.first == 1)
            {
                anss = dd;
                anss.first = mid;

                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

//        cout << anss.first << endl;

        cout << anss.second.first << " " << anss.second.second << endl;

//        cout << vec[0] << " " << vec[1] << endl;
    }

}



