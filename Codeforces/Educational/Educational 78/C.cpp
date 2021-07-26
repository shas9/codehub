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

ll arr[2][100005];
map < ll, ll > csum;

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
        csum.clear();

        slld(n);

        for(i = n; i >= 1; i--)
        {
            slld(arr[0][i]);

            if(arr[0][i] == 2) arr[0][i] = -1;
        }

        ll sum = 0;
        for(i = 1; i <= n; i++)
        {
            slld(arr[1][i]);

            if(arr[1][i] == 2) arr[1][i] = -1;
        }

        ans = 2 * n;

        for(i = n; i >= 1; i--)
        {
            sum += arr[1][i];

            csum[sum] = i;

            if(sum == 0) ans = min(ans, n + i - 1);
        }



        sum = 0;


        for(i = n; i >= 1; i--)
        {
            sum += arr[0][i];

            if(csum.find(sum * (-1)) != csum.end())
            {
//                cout << i << " " << csum[sum * -1] << " " << sum << endl;
                ans = min(ans, (i - 1) + (csum[sum * (-1)] - 1));
            }

            if(sum == 0) ans = min(ans, n + i - 1);
        }

//        if(sum == 0) ans = min(ans,n);

        cout << ans << endl;


    }


}


