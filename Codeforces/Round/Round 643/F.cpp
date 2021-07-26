// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

const ll maxn  = 1000;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
            for(ll j = i * i; j <= maxn; j += i)
            {
                vis[j] = 1;
            }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
            primes.pb(i);
    }

}

ll ask(ll x)
{
    cout << "? " << x << endl;
    cin >> x;

//    bug;

    return x;
}

void solve()
{
    ll lim = (1e9) / 4;

//    cout << lim << " " << (1e9) / 4 << endl;
    vector < ll > pr, cur;

    ll gun = 1;
    ll mxlld = 1e18;

    for(auto it: primes)
    {
        ll tmp = lim;

        tmp /= (it * it * it);

        if(tmp == 0) break;

        if(mxlld / it < gun)
        {
            ll gcd = ask(gun);

            while(!cur.empty())
            {
                if(gcd % cur.back() == 0)
                {
                    pr.push_back(cur.back());

                    if(pr.size() <= 2) lim *= 2;
                    lim /= cur.back();
                }

                cur.pop_back();
            }

            gun = 1;
        }

        gun = (gun * it);
        cur.push_back(it);
    }

    if(!cur.empty())
    {
        ll gcd = ask(gun);

        while(!cur.empty())
        {
            if(gcd % cur.back() == 0)
            {
                pr.push_back(cur.back());
                lim /= cur.back();
            }

            cur.pop_back();
        }
    }

    if(pr.size() & 1) pr.push_back(pr.back());

    ll ans = 2;

    for(ll i = 0; i < pr.size(); i += 2)
    {
		ll p1 = pr[i];
		ll p2 = pr[i + 1];

		ll num1 = 1, num2 = 1;

		while(p1 * num1 <= (1e9)) num1 *= p1;
		while(p2 * num2 <= (1e9)) num2 *= p2;

		ll gcd = ask(num1 * num2);

		ll cnt1 = 0, cnt2 = 0;

		while(gcd % p1 == 0) cnt1++, gcd /= p1;
		while(gcd % p2 == 0) cnt2++, gcd /= p2;

		ans = ans * (cnt1 + 1) * (cnt2 + 1);
	}

	printf("! %lld\n", max(8LL, ans));
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        solve();
    }


}


