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
#define eps 1e-6

#define mod 1000000009


using namespace std;


ll dp[50000];
ll coin[] = {0,10000,5000,2000,1000,500,200,100,50,20,10,5};

void solve()
{
    sort(coin + 1, coin + 12);


//    for(ll i = 0; i < 11; i++) cout << coin[i] << " ";
//    cout << endl;
    dp[0] = 1;

    ll k = 11;

    ll i, j;

    for(j = 1; j <= k; j++)
    for(i = 1; i <= 31000; i++)
    {
        {
            if(i >= coin[j])
            {
                dp[i] += dp[i - coin[j]];

//                if(i == 30)
//                cout << i - coin[j] << " : " << coin[j] << " : " << dp[i - coin[j]] << endl;
            }
        }
    }
}
int main()
{
    ll i, j, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    double x = 0.00;

    solve();
    flag = 0;

    while(1)
    {
        scanf("%lf", &x);

        //x += 0.05;
        if( abs(x - 0.0) <= eps) return 0;
        //if(x == 0.35) break;


        ll amount = x * 100.00;

        if(amount % 5) amount++;

        //cout << amount << endl;
        ans = dp[amount];
        printf("%6.2f", x);
        printf("%17lld\n", ans);
    }


}



