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

vector < string > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    vec.clear();
    slld(n);

    bool on = 1;
    string x;
    for(i = 1; i <= n; i++)
    {
        cin >> x;

        if(x[0] == 'O' && x[1] == 'O') on = 0;
        if(x[3] == 'O' && x[4] == 'O') on = 0;

        vec.push_back(x);
    }

    if(on) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;

        bool off = 1;
        for(i = 0; i < n; i++)
        {
            x = vec[i];

            if(!off)
            {
                cout << x << endl;
                continue;
            }

            if(x[0] == 'O' && x[1] == 'O' && off == 1)
            {
                cout << "++|" << x[3] << x[4] << endl;
                off = 0;
            }
            else if(x[3] == 'O' && x[4] == 'O' && off == 1)
            {
                cout  << x[0] << x[1] << "|++" << endl;
                off = 0;
            }
            else
            {
                cout << x << endl;
            }
        }
    }



}


