#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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

ll arr[100005];
ll bit[40];

void brute(ll n)
{
    ll ret = mxlld;
    ll ret1 = 0;
    ll i, j;

    for(i = 0; i <= 50; i++)
    {
        ll mx = 0;

        for(j = 1; j <= n; j++)
        {
            mx = max(arr[j]^i,mx);
        }

        ret = min(mx,ret);

        if(ret == mx)
        {
            ret1 = i;
        }

        cout << mx  << " " << i << endl;
    }

    cout << ret1 << " ~~ " << ret << endl;
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
            slld(arr[i]);
        }

        memset(bit,0,sizeof bit);

        ans = 0;

        for(i = 1; i <= n; i++)
        {
            for(j = 0; j <= 32; j++)
            {
                if(check(arr[i],j)) bit[j]++;
            }

            ans = max(ans,arr[i]);
        }

        ll mask = 0;

        for(i = 0; i <= 31; i++)
        {
//            ll mxbit = 0;
//            ll bpos = 0;
//            ll cnt = 0;
//
//            for(j = 0; j <= 31; j++)
//            {
//                if(mxbit < bit[j])
//                {
//                    mxbit = bit[j];
//                    bpos = j;
//                    cnt = 0;
//                }
//
//                if(mxbit == bit[j]) cnt++;
//            }
//
//            if(mxbit == 0) break;

//            if(cnt > 1)

            ll bpos;
            {
                ll mn = mxlld;
                for(j = 0; j <= 30; j++)
                {
                    ll tmask = Set(mask,j);
                    ll mx = 0;
                    for(k = 1; k <= n; k++)
                    {
                        mx = max(mx,arr[k] ^ tmask);
                    }

                    mn = min(mx,mn);

                    if(mn == mx)
                    {
                        bpos = j;
                    }
                }
            }

            ll tmask = Set(mask,bpos);

            ll tans = 0;

            for(j = 1; j <= n; j++)
            {
                tans = max(tans,arr[j] ^ tmask);
            }

//            cout << tans << " " << tmask << endl;

            ans = min(ans,tans);
            mask = tmask;

            bit[bpos] = 0;
        }

//        brute(n);

        cout << ans << endl;


    }


}



