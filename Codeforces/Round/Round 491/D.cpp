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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> a >> b;

    ll sz = a.size();

    ll cnt = 0;

    for(i = 0; i < sz - 1; i++)
    {
        if(a[i] == '0' && a[i + 1] == '0')
        {
            if(b[i] == '0')
            {
                cnt++;

                a[i] = a[i + 1] = b[i] = 'X';
            }
            else if(b[i + 1] == '0')
            {
                cnt++;

                a[i] = a[i + 1] = b[i + 1] = 'X';
            }
        }

        if(b[i] == '0' && b[i + 1] == '0')
        {
            if(a[i] == '0')
            {
                cnt++;

                b[i] = b[i + 1] = a[i] = 'X';
            }
            else if(a[i + 1] == '0')
            {
                cnt++;

                b[i] = b[i + 1] = a[i + 1] = 'X';
            }
        }
    }

    cout << cnt << endl;


}


