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

vector < ll > divi;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll gcd, lcm, r, a, b, cnt = 0;

    cin >> l >> r >> gcd >> lcm;

    for(i = 1; i * i <= lcm; i++)
    {
        if(lcm % i == 0)
        {
            flag = lcm / i;

            divi.pb(i);

            if(flag != i) divi.pb(flag);
        }
    }

    sort(divi.begin(),divi.end());

    i = 0;

    while(divi[i] < l)
    {
        i++;
    }

    for(; i < divi.size() && divi[i] <= r; i++)
    {
        a = divi[i];

        b = (lcm * gcd) / a;

        if(__gcd(a,b) != gcd) continue;

        if(b > r || b < l) continue;

        cnt++;
    }

    cout << cnt << endl;





}


