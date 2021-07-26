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

ll arr[1000];

double tmp[1000];

void brute(ll n)
{
    for(ll i = 1; i <= n; i++) tmp[i] = arr[i];

    for(ll i = 1; i <= n; i++)
    {
        double sum = 0;
        double mx = 1000000;
        ll r = 0;

        for(ll j = i; j <= n; j++)
        {
            sum += tmp[j];

            double avv = (sum / (j - i + 1));

            if(avv < mx) mx = avv, r = j;
        }

        for(ll j = i; j <= r; j++)
        {
            tmp[j] = mx;
        }
    }

    for(ll i = 1; i <= n; i++)
    {
        printf("%.10f ", tmp[i]);
    }

    printf("\n");
}

void chk()
{
    while(1)
    {
        cin >> l >> r;

        if(l == 0) return;

        ll sum = 0;

        for(ll i = l; i <= r; i++) sum += arr[i];

        double d = (sum*1.0) / (r - l + 1.0);

        printf("%.10f\n", d);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
            slld(arr[i]);

        brute(n);
        chk();


    }


}

