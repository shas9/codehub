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

#define maxn 1000005

ll arr[maxn];
ll cnt[maxn];
ll mat[maxn];

bool check(ll n, ll m, ll posx, ll posy)
{
    if(posx <= 0 || posx > n || posy <= 0 || posy > m) return false;

    memset(mat,0,sizeof mat);

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            ll dis = abs(posx - i) + abs(posy - j);

            mat[dis]++;
        }
    }

    for(ll i = 1; i <= n  * m; i++)
    {
        if(cnt[i] != mat[i]) return false;
    }

    return true;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll t;
    slld(t);
    ll b = 0;

    for(i = 1; i <= t; i++)
    {
        slld(arr[i]);
        cnt[arr[i]]++;

        b = max(b,arr[i]);
    }

    if(cnt[0] != 1)
    {
        cout << -1 << endl;

        return 0;
    }

    ll posx = -1, posy = -1;


    for(i = 1; i <= t; i++)
    {
        if(cnt[i] != (4 * i))
        {
            posx = i;
            break;
        }
    }

    if(posx == -1)
    {
        cout << -1 << endl;

        return 0;
    }

    for(n = 1; n <= t; n++)
    {
        if(t % n) continue;

        m = t / n;

        posy = n + m - b - posx;

        if(check(n,m,posx,posy))
        {
            cout << n << " " << m << endl << posx << " " << posy << endl;
            return 0;
        }
    }

    cout << -1 << endl;

}

