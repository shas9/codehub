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

vector < ll > interval, period;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m)
    {
        interval.clear();
        period.clear();

        ll _gc = 0;

        for(i = 0; i < n; i++)
        {
            slld(input);

            interval.push_back(input);

            if(i)
            {
                _gc = __gcd(_gc, abs(input - interval[i - 1]));
            }
        }

        for(i = 0; i < m; i++)
        {
            slld(input);

            period.push_back(input);
        }

        for(i = 0; i < m; i++)
        {
            if(_gc % period[i] == 0)
            {
                cout << "YES" << endl;
                cout << interval[0] << " " << i + 1 << endl;
                break;
            }
        }

        if(i == m)
        {
            cout << "NO" << endl;
        }

    }


}


