 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll mx = 2e7;

ll dv[mx + 7];
ll mind[mx + 7];

void precalc()
{
    memset(mind,-1,sizeof mind);

    for(ll i = 2; i <= mx; i++)
    {
        if(mind[i] == -1)
        {
            for(ll j = i; j <= mx; j += i)
            {
                dv[j]++;
                if(mind[j] == -1) mind[j] = i;
            }
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll c, d, x;

        cin >> c >> d >> x;

        long long ans = 0;

        for(ll i = 1; i * i <= x; i++)
        {
            if(x % i == 0)
            {
                ll ab = (i + d);

                if(ab % c == 0)
                {
                    ans += (1LL << dv[ab / c]);
                }

                if(i != (x / i))
                {
                    ab = (x / i) + d;

                    if(ab % c == 0)
                    {
                        ans += (1LL << dv[ab / c]);
                    }
                }

            }
        }

        cout << ans << "\n";
    }


}

