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

//        cout << n << " " << m << " " << k << endl;
//
//        for(i = 1; i <= n; i++) cout << arr[i] << " ";
//        cout << endl;

        ans = 0;

        ll sum = 0;

        arr[0] = 0;

        for(i = 0; i <= n; i++)
        {
            sum += arr[i];

//            ll lo = i + 1;
//            ll hi = i + k;


            ll lft = m - sum;

            if(lft < 0) break;

//            ans = max(ans,i);
//            if(i < k) continue;

//            ll pos = i;
//
//            while(lo <= hi)
//            {
//                ll mid = (lo + hi) / 2;
//
//                if(arr[mid] <= lft)
//                {
//                    pos = mid;
//                    lo = mid + 1;
//                }
//                else
//                {
//                    hi = mid - 1;
//                }
//            }



            ll pos = i + k;

            if(arr[pos] > lft || pos > n) pos = i;

//            cout << i << " " << pos - i << endl;

            ans = max(ans, i + (pos - i));
        }

        m -= arr[k];

        if(m > 0) ans = max(ans,k);

        for(i = k + 1; i <= n; i++)
        {
            m -= arr[i];

            if(m < 0) break;

            ans = max(ans,i);
        }

        cout << ans <<endl;
    }


}



