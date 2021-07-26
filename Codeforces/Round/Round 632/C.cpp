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

ll csum[200005];
map < ll, ll > mp;
map < ll, ll > lastst, lasten;


void brute(ll n)
{
    ll cnt = 0;
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = i; j <= n; j++)
        {
            bool ok = 0;

            for(ll k = i; k <= j; k++)
            {
                ll sum = 0;
                for(ll l = k; l <= j; l++)
                {
                    sum += (csum[l] - csum[l - 1]);

                    if(sum == 0)
                    {
                        ok = 1;
                        break;
                    }
                }

                if(ok) break;
            }
            if(ok == 0) cnt++;
        }
    }

    cout << cnt << endl;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(csum[i]);

            csum[i] += csum[i - 1];
        }

//        brute(n);

        mp.clear();

        ans = (n * (n + 1)) / 2;

        ll last = n + 1;

        for(i = n; i >= 1; i--)
        {
            ll val = csum[i] - csum[i - 1];

            ll tmp = csum[i] - val;

            if(val == 0)
            {
                ans -= (i * (last - i));
                last = i;
//                continue;
            }
            else if(mp[tmp] != 0)
            {
                j = max(0LL,(last - mp[tmp]));

                if(j)
                {
                    ans -= (i * j);

                    last = mp[tmp];

                    mp[tmp] = 0;
                }

            }

            mp[csum[i]] = i;


        }


        cout << ans << endl;
    }


}



