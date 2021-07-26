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

ll child[5003];
ll par[5003];
ll lev[5003];

bool chk(ll n, ll m)
{
    ll ub = (n * (n - 1)) / 2;
    ll lb = 0;
    ll cnt = 2;
    ll sum = 0;

    for(ll i = 1; i <= n; i++)
    {
        if(i == cnt)
        {
            cnt *= 2;
            sum += 1;
        }

        lb += sum;
    }

    if(lb <= m && m <= ub) return 0;

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

//        cout << n << " " << m << endl;

        if(chk(n,m))
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for(i = 1; i <= n; i++) par[i] = i - 1;

        for(i = 1; i <= n; i++)
        {
            lev[i] = i - 1;

            if(i < n) child[i] = 1;
            else child[i] = 0;
        }

        ll cnt = (n * (n - 1)) / 2;

        ll last = n;
        while(cnt > m)
        {
//            bug;

//            if(n == 12 && m == 25)
//            {
//                cout << last << endl;
//
//                for(i = 1; i <= n; i++)
//                {
//                    cout << par[i] << " ";
//                }
//
//                cout << endl;
//            }
            ll levl = lev[last];

            bool on = 1;

            for(i = 1; i <= n; i++)
            {
                if(lev[i] + 2 == levl && child[i] < 2)
                {
                    child[par[last]]--;
                    par[last] = i;
                    child[i]++;
                    lev[last]--;
                    on = 0;
                    break;
                }
            }

            if(on) last--;
            else cnt--;
        }

        for(i = 2; i <= n; i++) cout << par[i] << " ";

        cout << endl;
    }


}

