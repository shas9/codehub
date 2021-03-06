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

ll arr[500005];
ll arr2[500005];
ll sum[500005];
ll sum2[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    ll mn = mxlld;

    stack < pll > dq;

    dq.push({0LL,0LL});

    for(i = 1; i <= n; i++)
    {
        pll top;

        while(1)
        {
            top = dq.top();

            if(arr[i] >= top.first) break;

            dq.pop();
        }

//        cout << top.first << " " << top.second << " ";
        sum[i] = sum[top.second] + (i - top.second) * arr[i];

        dq.push({arr[i], i});

//        cout << sum[i] << endl;
    }

    while(!dq.empty()) dq.pop();

    dq.push({0LL,n + 1});

    ans = mnlld;
    ll idx = 0;
    for(i = n; i >= 1; i--)
    {
        pll top;

        while(1)
        {
            top = dq.top();

            if(arr[i] >= top.first) break;

            dq.pop();
        }

        sum2[i] = sum2[top.second] + abs(i - top.second) * arr[i];

//        cout << sum2[i] << endl;

        ans = max(ans, sum2[i] + sum[i] - arr[i]);

        if(ans == sum[i] + sum2[i] - arr[i]) idx = i;

        dq.push({arr[i], i});
    }

//    cout << ans << endl;

    arr2[idx] = arr[idx];

    for(i = idx - 1; i >= 1; i--)
    {
        arr2[i] = min(arr2[i + 1], arr[i]);
    }

    for(i = idx + 1; i <= n; i++)
    {
        arr2[i] = min(arr2[i - 1], arr[i]);
    }

    for(i = 1; i <= n; i++) cout << arr2[i] << " ";

    cout << endl;
}



