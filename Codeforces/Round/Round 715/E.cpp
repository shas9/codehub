 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

ll arr[100005];
ll pwr[100];

bool solve(ll n, ll k, ll pos)
{
    if(n == 1)
    {
        arr[++pos] = pos;
        return 1;
    }

    if(pwr[n - 1] < k) return 0;

    ll sum = 0;
    ll cnt = 0;
    ll lim = pos;

    for(ll i = n - 2; i >= 0; i--)
    {
        if(sum + pwr[i] > k)
        {
            solve(n - cnt, k - sum, pos + cnt);
        }

        cnt++;
    }

    for(ll i = cnt; i >= 0; i--)
    {
        arr[++pos] = (i + lim);
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    pwr[0] = 1;

    for(ll i = 1; i <= 60; i++)
    {
        pwr[i] = 2 * pwr[i - 1];
    }

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> k;

        ll pos = 0;

        for(ll i = 1; i <= (n - 60); i++)
        {
            arr[++pos] = i;
        }

        n = n - max(0LL, n - 60);

        if(solve(n,k,pos))
        {
            for(ll i = 1; i <= n; i++)
            {
                cout << arr[i] << " ";
            }

            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }


}

