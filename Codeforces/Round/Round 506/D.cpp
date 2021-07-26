#include <iostream>
#include <map>
#include <unordered_map>
#include <cstdio>

#define slld(longvalue) scanf("%llu", &longvalue)
#define plld(longvalue) printf("%llu\n", longvalue)

#define ll unsigned long long


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

unordered_map < ll, ll > rem[12];
ll arr[200005];
ll arrmul[200005][13];

ll getdig(ll x)
{
    ll ret = 0;

    while(x > 0) ret++, x/=10;

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    slld(n);
    slld(k);
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }


        ans = 0;

        for(i = 1; i <= n; i++)
        {
            flag = arr[i];
            for(j = 1; j <= 10; j++)
            {
                flag *= 10;

                arrmul[i][j] = flag;

                ll md = flag % k;

                rem[j][md]++;
            }


        }

        for(i = 1; i <= n; i++)
        {
            flag = arr[i];
            ll sz = getdig(flag);

            ll md = arr[i] % k;

            ll need = k - md;

            ans += rem[sz][need];

            flag = arrmul[i][sz];

            ll x = flag % k;

            if(md == 0)
            {
                ans += rem[sz][0];

                if(x == 0) ans--;
            }

            if(x == need) ans--;

        }

        plld(ans);
    }
}

