
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

vector < pair < ll, string > > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        ll mxx = (4 * n * m) - (2 * n) - (2 * m);

        if(mxx < k)
        {
            cout << "NO" << endl;
            continue;
        }

        vec.clear();

        cout << "YES" << endl;


        ll lim;

        bool left;
        for(i = 1; i < n; i++)
        {
            lim = (m - 1) * 3;
            left = 1;

//            cout << lim << " " << k << endl;

            if(lim <= k && (m - 1))
            {
                vec.push_back(make_pair(m-1,"RDU"));
            }
            else if((m - 1))
            {
                lim = k;

                ll md = k % 3;
                ll dv = k / 3;

                if(dv) vec.push_back(make_pair(dv, "RDU"));

                md = min(md,m - 1 - dv);

                if(md) vec.push_back(make_pair(md,"R"));

                lim = (3 * dv) + md;
            }

            left = 0;

            k -= lim;

            if(k == 0) break;

            lim = (m - 1);

            if(lim <= k && (m - 1))
            {
                vec.push_back(make_pair(m-1,"L"));
            }
            else if((m - 1))
            {
                lim = k;
                vec.push_back(make_pair(k,"L"));
            }

            k -= lim;

            if(k == 0) break;

            vec.push_back(make_pair(1,"D"));
            k--;

            left = 1;
        }

        if(i == n && k)
        {
            lim = (m - 1);

            if(lim <= k && (m - 1) && k)
            {
                vec.push_back(make_pair(m-1, "R"));
            }
            else if((m - 1)  && k)
            {
                lim = k;
                vec.push_back(make_pair(k, "R"));
            }
            else
            {
                lim = 0;
            }

            k -= lim;

            lim = (m - 1);

            if(lim <= k && (m - 1) && k)
            {
                vec.push_back(make_pair(m-1, "L"));
            }
            else if((m - 1) && k)
            {
                lim = k;
                vec.push_back(make_pair(k, "L"));
            }
            else
            {
                lim = 0;
            }

            k -= lim;

            lim = (n - 1);

            if(lim <= k && (n - 1) && k)
            {
                vec.push_back(make_pair(n-1, "U"));
            }
            else if((n - 1) && k)
            {
                lim = k;
                vec.push_back(make_pair(k, "U"));
            }
            else
            {
                lim = 0;
            }

            k -= lim;
        }

        cout << vec.size() << endl;

        for(i = 0; i < vec.size(); i++)
        {
            cout << vec[i].first << " "  << vec[i].second << endl;
        }
    }


}

