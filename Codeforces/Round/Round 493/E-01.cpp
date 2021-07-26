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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll d;

    cin >> n >> d >> k;
    ll st = 2;
    ll st2 = 3;
    ll inc = (k) * 2;

    ll cnt = 0;
    ll cnt2 = 0;

    if(k > 1)
    while(st < n && st2 < n)
    {

        cnt++;
        cnt2++;

        if(cnt + cnt2 > d)
        {
            cout << "NO" << endl;
            return 0;
        }

        st *= (k - 1);
        st++;
        st2 *= (k - 1);
        st2++;
    }

    if(k == 1)
    {
        if(n > d + 1)
        {
            cout << "NO" << endl;
            return 0;
        }

        cout << "YES" << endl;

        for(i = 1; i < n; i++)
        {
            printf("%lld %lld\n", i, i + 1);
        }

        return 0;
    }

    cout << "YES" << endl;

    for(i = 2; i <= k + 1; i++)
    {
        cout << 1 << " " << i << endl;
    }

    for(i = 2; i <= n; i++)
    {
        for(j = i * (k - 1) + 1; j < (i + 1) * k && j <= n; j++)
        {
            printf("%lld %lld\n", i, j);
        }

        if(j > n) return 0;
    }






}

