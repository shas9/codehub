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

ll arr[200005];
ll csum[200005];

ll bs(ll lo, ll hi, ll val)
{
//    cout << lo << " " << hi << " " << val <<endl;
    ll ret = lo - 1;

    ll st = lo - 1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if((csum[mid] - csum[st]) <= val)
        {
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret - st;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        slld(k);

        for(i = 1; i <= n; i++) slld(arr[i]);

        sort(arr + 1, arr + 1 + n);

        for(i = 1; i <= n; i++)
        {
            csum[i] = csum[i - 1] + arr[i];
        }

        ans = 0;

        ll sum = 0;

        for(i = 0; i <= n; i++)
        {

            sum += arr[i];

            ll lft = m - sum;

            if(lft < 0) break;

            ll pos = i + k;
            ll tmp = 0;


            if(arr[pos] > lft || pos > n) pos = i;
            else tmp = bs(pos + 1, n, lft - arr[pos]);

            ans = max(ans, i + (pos - i) + tmp);
        }

        cout << ans << endl;
    }


}



