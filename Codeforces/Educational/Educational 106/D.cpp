 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

#define mx 10000005

bool check(int n, int pos)
{
	return n & (1 << pos);
}

int Set(int n, int pos)
{
	return n = n | (1 << pos);
}

int status[(mx / 32) + 5];

vector < int > primes;

void sieve(int n)
{
    int i, j, sq;

    sq = int( sqrt(n) );

    for(i = 3; i <= sq; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            for(j = i * i; j <= n; j += (i << 1))
            {
                status[j >> 5] = Set(status[j >> 5], j & 31);
            }
        }
    }

    primes.clear();

    primes.pb(2);

    for(i = 3; i <= n; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            primes.pb(i);
        }
    }


}

unordered_map < ll, ll > mp;

ll calc(ll ab)
{
    if(mp.find(ab) != mp.end()) return mp[ab];
    ll ret = 0;

    for(auto it: primes)
    {
        if(it * it > ab) break;

        if(ab % it == 0)
        {
            ret++;

            while(ab % it == 0) ab /= it;
        }
    }

    if(ab != 1) ret++;

    return mp[ab] = (1LL << ret);
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


//    ans = 0;

//    for(ll i = 2; i * i <= 1e7; i++)
//    {
////        ans += 1e7 / i;
//
//        for(ll j = i; j <= 1e7; j += i)
//        {
//            dv[j].push_back(i);
//        }
//    }

//    cout << ans << "\n";

    sieve(10000000);

    fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll c, d, x;

        cin >> c >> d >> x;

        ans = 0;

        for(ll i = 1; i * i <= x; i++)
        {
            if(x % i == 0)
            {
                ll a = i;
                ll b = x / i;

                ll ab = (b + d);

                if(ab % c == 0)
                {
                    ab /= c;
                    ans += calc(ab);
                }

                if(a != b)
                {
                    ab = (a + d);

                    if(ab % c == 0)
                    {
                        ab /= c;
                        ans += calc(ab);
                    }
                }
            }
        }

        cout << ans << "\n";
    }


}


