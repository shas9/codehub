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

vector < string > s, t;

string inn;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> inn;

        s.push_back(inn);
    }

    for(i = 0; i < m; i++)
    {
        cin >> inn;

        t.push_back(inn);
    }

    slld(q);

    while(q--)
    {
        slld(input);

        ll ii = input / n;
        ll jj = input / m;

        ii = input - (ii * n);
        jj = input - (jj * m);

        ii--, jj--;

        if(ii < 0) ii = n - 1;
        if(jj < 0) jj = m - 1;

        string outt = s[ii];

        for(i = 0; i < t[jj].size(); i++)
        {
            outt += t[jj][i];
        }

        cout << outt << endl;
    }


}


