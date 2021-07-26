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

#define maxn 300005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll ud_dp[maxn];
ll arr[2][maxn];
ll du_dp[maxn];
ll dp3[maxn];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[0][i]);
    }

    for(i = 1; i <= n; i++)
    {
        slld(arr[1][i]);
    }

    ll flag1 = 0;
    ll flag2 = (n * 2) - 1;

    for(i = 1; i <= n; i++)
    {
        ud_dp[i] = (flag1 * arr[0][i]) + (flag2 * arr[1][i]);
        flag1++;
        flag2--;
    }

    flag1 = (n * 2) - 1;
    flag2 = 0;

    for(i = 1; i <= n; i++)
    {
        du_dp[i] = (flag1 * arr[0][i]) + (flag2 * arr[1][i]);
        flag1--;
        flag2++;
    }

    for(i = n - 1; i >= 1; i--)
    {
        ud_dp[i] += ud_dp[i + 1];
        du_dp[i] += du_dp[i + 1];
    }

//    for(i = 1; i <= n; i++)
//    {
//        cout << ud_dp[i] << " ";
//    }
//
//    cout << endl;
//    for(i = 1; i <= n; i++)
//    {
//        cout << du_dp[i] << " ";
//    }
//
//    cout << endl;

    for(i = n; i >= 1; i--)
    {
        dp3[i] = arr[0][i] + arr[1][i];
        dp3[i] += dp3[i + 1];
    }
    ans = 0;

    ans = ud_dp[1];

    ll cnt = 0;

    for(i = 1; i <= n; i++)
    {
        flag = ((i - 1) * 2);

        if(i % 2)
        {
            cnt += arr[0][i] * flag;
            cnt += arr[1][i] * (flag + 1);

            ans = max(cnt + du_dp[i + 1] + (dp3[i + 1] * i), ans);
        }s
        else
        {
            cnt += arr[0][i] * (flag + 1);
            cnt += arr[1][i] * flag;
            ans = max(cnt + ud_dp[i + 1] + (dp3[i + 1] * i), ans);
        }
    }

    plld(ans);


}


