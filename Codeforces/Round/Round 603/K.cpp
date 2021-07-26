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

#define mod 2000004109
#define base 11867

using namespace std;

ll fh[1000005];
ll rh[1000005];
ll ans_i[1000005];
ll base_i[1000005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    base_i[0] = 1;

    for(i = 1; i <= 1000000; i++) base_i[i] = (base_i[i - 1] * base) % mod;

    cin >> n;
    ll pos = 0;
    fh[0] = 1;

    while(n--)
    {
        ll type;

        slld(type);

        if(type == 1)
        {
            pos++;
            slld(input);

            input++;

			fh[pos] = ((fh[pos - 1] * base) + input) % mod;
			rh[pos] = ((input * base_i[pos]) + rh[pos - 1]) % mod;

            ll prvans = ans_i[pos - 1];

            ans_i[pos] = ans_i[pos - 1];

            r = pos - prvans;

            if(r > 0)
            {
                ll xx = ((fh[pos] - ((fh[r - 1] * base_i[pos - r + 1]) %mod) + mod) % mod * base_i[r]) % mod;
                ll yy = (rh[pos] - rh[r - 1] + mod) % mod;

                if(xx == yy) ans_i[pos] = max(ans_i[pos], prvans + 1);

                r = pos - prvans - 1;

                if(r > 0)
                {
                    ll xx = ((fh[pos] - ((fh[r - 1] * base_i[pos - r + 1]) %mod) + mod) % mod * base_i[r]) % mod;
					ll yy = (rh[pos] - rh[r - 1] + mod) % mod;

					if(xx == yy) ans_i[pos] = max(ans_i[pos], prvans + 2);
                }
            }
        }
        else
        {
            fh[pos] = 0;
            rh[pos] = 0;
            ans_i[pos] = 0;

            pos--;
            pos = max(pos,0LL);
        }

        printf("%lld\n", ans_i[pos]);
    }


}



