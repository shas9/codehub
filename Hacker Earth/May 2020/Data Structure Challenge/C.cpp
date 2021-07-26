// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

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
pll cnt[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++) slld(arr[i]);

        ans = 1;

        arr[0] = 0;
        cnt[0] = {0,0};

        for(i = 1; i <= n; i++)
        {
            cnt[i] = {1,1};

            if(arr[i] > arr[i - 1])
            {
                cnt[i] = cnt[i - 1];

                cnt[i].first++;
                cnt[i].second++;
            }

            if(i > 1 && arr[i] > arr[i - 2])
            {
                cnt[i].second = max(cnt[i - 2].first + 1, cnt[i].second);
            }

//            cout << cnt[i].first << " " << cnt[i].second << endl;
        }

        for(i = 1; i <= n; i++)
        {
            ans = max(ans, max(cnt[i].first,cnt[i].second));
        }

        cout << ans << "\n";
    }


}



