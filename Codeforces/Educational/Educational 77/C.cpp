#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

void brute(ll r, ll b)
{
//	if(r > b) swap(r,b);
    ll cntr = 0, cntb = 0;

    ll mx = 0;
    for(ll i = min(r,b); i <= min(r,b) + 1000; i++)
    {
        if(!(i % r) && !(i % b))
        {
//            cout << 2 << " ";
//            if(cntr) cout << cntr << " ";
            cntr = 0;
            cntb++;
        }
        else if(!(i%r))
        {
//            cout << "r ";
//            if(cntb) cout << (cntb) << " ";
            cntb = 0;
            cntr++;
        }
        else if(!(i%b))
        {
//            cout <<  "b ";
//            if(cntr) cout << cntr << " ";
            cntr = 0;
            cntb++;
        }

        mx = max(mx, max(cntb,cntr));
    }

    cout << mx;
//    bug;
}

void solve(ll n, ll m)
{
    ll k;
//    slld(k);

//    cout << n << " " << m << endl;

    if(n > m) swap(n,m);

    ll gap = (m / n);

    if(m % n == 0) gap--;

    ll x = (m % n);

    if(x > 1)
    {
        if(x > n) gap++;

        if(n % x == 0) gap--;
    }

    cout << gap;

//    if(gap >= k)
//    {
//        printf("REBEL\n");
//    }
//    else
//    {
//        printf("OBEY\n");
//    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    slld(testcase);
//
//    for(ll cs = 1; cs <= testcase; cs++)
    {
//        slld(n);
//        slld(m);

        for(i = 1; i <= 100; i++)
        {
            for(j = i; j <= 100; j++)
            {
				cout << i << " " << j << ": ";
                brute(i,j);
                cout << " && ";
                solve(i,j);
                cout << endl;
            }
        }
    }


}



