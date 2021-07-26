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

string a, b;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    ll pos = -1;

    cin >> a >> b;

    for(i = 0; i < n; i++) if(a[i] == '*') pos = i;

    if(pos == -1)
    {
        if(a == b)  cout << "YES";
        else cout << "NO";

        return 0;
    }

    if(n > m + 1)
    {
        cout << "NO" << endl;
        return 0;
    }


    for(i = 0; i < pos; i++)
    {
        if(a[i] != b[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(i = n - 1, j = m - 1; i > pos; i--, j--)
    {
        if(a[i] != b[j])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;


}


