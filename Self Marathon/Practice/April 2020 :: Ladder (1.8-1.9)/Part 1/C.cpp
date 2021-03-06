#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long

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

ll arr[100005];
ll csum[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll ql, qr;

    while(cin >> n >> l >> r >> ql >> qr)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            csum[i] = arr[i] + csum[i - 1];
        }

        ans = mxlld;

        i = 1;
        j = n;

        ll sum = 0;
        while(i <= j)
        {
            if(i == j)
            {
//                cout << sum << " " << ans << endl;

                ans = min(ans, sum + min(arr[i] *l, arr[i] * r));
                break;
            }

            ans = min(ans, sum + (csum[j] - csum[i - 1]) * l + (j - i) * ql);
            sum += arr[i] * l;

            ans = min(ans, sum + (csum[j] - csum[i]) * r + (j - i - 1) * qr);

            sum += arr[j] * r;

            i++;
            j--;
        }

        i = 1;
        j = n;

        sum = 0;
        while(i <= j)
        {
            if(i == j)
            {
                ans = min(ans, sum + min(arr[i] *l, arr[i] * r));
                break;
            }

            ans = min(ans, sum + (csum[j] - csum[i - 1]) * r + (j - i) * qr);
            sum += arr[j] * r;

            ans = min(ans, sum + (csum[j - 1] - csum[i - 1]) * l + (j - 1 - i) * ql);

            sum += arr[i] * l;

            i++;
            j--;
        }

        cout << ans << endl;
    }


}


