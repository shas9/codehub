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

ll bs(ll b, ll idx)
{
    ll lo = idx;
    ll hi = b;

    ll ret = mxlld;

//    cout << b << " " << idx << endl;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        ll tmp = (mid * (mid + 1))/ 2;

//        if(b == 20) cout << tmp << " ~~ ";
        tmp -= (idx * (idx + 1)) / 2;

//        if(b == 20) cout << tmp << endl;

//        if(b == 20)
//        {
//            cout << mid << " " << tmp << " " << idx << " " << endl;
//        }

        if(tmp == b)
        {
            return mid;
        }

        if(tmp < b)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll a, b;

        cin >> a >> b;

        if(a > b) swap(a,b);

        ans = 2 * abs(b - a);

        for(i = 0; i <= 100000; i++)
        {
            ll tmp = (i * (i + 1)) / 2;

            ll cost = 2 * abs((a + tmp) - b) + i;

            ans = min(ans,cost);
        }

        b -= a;
        a = 0;

//        cout << a << " " << b << endl;

        for(i = 1; i <= 10000; i++)
        {
            b += i;

            ans = min(ans, bs(b,i));
        }

        cout << ans <<endl;
    }


}



