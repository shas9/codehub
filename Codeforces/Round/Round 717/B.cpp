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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > v;

bool solve()
{
    ll odd = 0;
    ll even = 0;


    for(ll i = 0; i < 32; i++)
    {
        ll cnt = 0;

        for(auto it: v)
        {
            if(check(it,i)) cnt++;
        }

        if(cnt)
        {
            if(cnt & 1) odd++;
            else even++;

            if(cnt == 1) return 0;
        }
    }

    return 1;
}

bool solve1()
{
    ll xxor = 0;

    for(auto it: v) xxor ^= it;

    return xxor == 0;
}

bool solve2()
{
    ll xxor = 0;

    for(auto it: v) xxor ^= it;

    ll n = v.size();

    for(ll i = 0, pxor = 0; i + 1 < n; i++)
    {
        pxor ^= v[i];

        if(pxor == (pxor ^ xxor)) return 1;
    }

    for(ll i = 0, pxor = 0; i + 2 < n; i++)
    {
        pxor ^= v[i];

        for(ll j = i + 1, qxor = 0; j + 1 < n; j++)
        {
            qxor ^= v[j];

            if(pxor == qxor)
            {
                if(pxor == xxor) return 1;
            }
        }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        v.resize(n);

        for(auto &it: v) cin >> it;

        if(solve2()) cout << "YES\n";
        else cout << "NO\n";
    }


}


