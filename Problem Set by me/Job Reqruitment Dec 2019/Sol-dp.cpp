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

ll arr[30];
ll n;
ll x;
ll arr2[30];

ll solve(ll pos)
{
    if(pos > n)
    {
        ll sum = 0;

        for(ll i = 1; i < n; i++)
        {
            for(ll j = i + 1; j <= n; j++)
            {
                sum += abs(arr2[i] - arr2[j]);
            }
        }

        return sum;
    }

    arr2[pos] = arr[pos] - x;
    ll a = solve(pos + 1);

    arr2[pos] = arr[pos];
    ll b = solve(pos + 1);

    arr2[pos] = arr[pos] + x;
    ll c = solve(pos + 1);

    return min(min(a,b),c);

}
void gen()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(x);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        ans = solve(1);

        cout << ans << endl;
    }
}
int main()
{

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    ll i, j;

//    for(ll k = 0; k <= 2; k++)
//        for(i = 0; i <= 9; i++)
//        {
//            string str = "input";
//
//            str += (k + '0');
//            str += (i + '0');
//
//            str += ".txt";
//
//            char str2[30];
//            for(j = 0; j < str.size(); j++)
//            {
//                str2[j] = str[j];
//            }
//
//            str2[j] = '\0';
//
//            char *str3 = str2;
//
//            freopen(str3, "r", stdin);
//
//            string sstr = "output";
//
//            sstr += (k + '0');
//            sstr += (i + '0');
//
//            sstr += ".txt";
//
//            char sstr2[30];
//            for(j = 0; j < sstr.size(); j++)
//            {
//                sstr2[j] = sstr[j];
//            }
//
//            sstr2[j] = '\0';
//
//            char *sstr3 = sstr2;
//
////            cout << str3 << " " << sstr3 << endl;
//
//            freopen(sstr3, "w", stdout);

            gen();


//        }



}

