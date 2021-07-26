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

ll freq[200];

bool check(ll mid, ll n)
{
    ll cnt = 0;

    for(ll i = 1; i <= 100; i++)
    {
        cnt += (freq[i] / mid);
    }

    if(cnt >= n) return 1;
    else return 0;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    while(cin >> n >> k)
    {
        memset(freq,0,sizeof freq);

        for(i = 1; i <= k; i++)
        {
            slld(input);

            freq[input]++;
        }

        ll low = 1;
        ll high = k;

        ans = 0;
        while(low <= high)
        {
            ll mid = (low + high) / 2;

            //cout << mid << endl;

            if(check(mid, n))
            {
                low = mid + 1;
                ans = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }


}


