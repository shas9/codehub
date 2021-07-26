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

string a, b, c, d;
vector < ll > ans;
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> a >> b)
    {
        c = a;
        d = b;

        sort(c.begin(),c.end());
        sort(d.begin(),d.end());

        if(c != d)
        {
            cout << -1 << endl;
            continue;
        }

        ans.clear();

        ll sz = c.size();

        for(i = 0; i < sz; i++)
        {
            if(a[i] == b[i]) continue;

            char c = b[i];

            for(j = i; j < sz; j++)
            {
                if(c == a[j]) break;
            }

            for(k = j; k > i; k--) ans.push_back(k);

            for(k = j; k >= i; k--)
            {
                a[k] = a[k - 1];
            }

            a[i] = b[i];

            //cout << a << " " << b << endl;
        }

        if(ans.size() > 10000)
        {
            cout << -1 << endl;
            continue;
        }

        cout << ans.size() << endl;

        for(i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }


        cout << endl;


    }
}

