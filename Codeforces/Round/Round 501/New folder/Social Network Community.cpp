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

#define maxn 100005

using namespace std;

ll pep[maxn], sz[maxn];

ll fnd(ll n)
{
    if(pep[n] == n) return n;

    //cout << pep[n] << " " << n << endl;

    return pep[n] = fnd(pep[n]);
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        pep[i] = i;
        sz[i] = 1;
    }

    ll q;
    slld(q);

    for(i = 1; i <= q; i++)
    {
        char c;

        cin >> c;

        if(c == 'S')
        {
            slld(input);

            input = fnd(input);

            plld(sz[input]);

            continue;
        }

        slld(j);
        slld(k);

        j = fnd(j);
        k = fnd(k);

        if(c == 'E')
        {

            if(j == k)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }

            continue;
        }

        if(sz[j] + sz[k] <= m)
        sz[j] += sz[k], pep[k] = j;
    }
}


