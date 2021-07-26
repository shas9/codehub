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
string name[15];
ll dp[11][23];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    for(i = 1; i <= 15; i++)
    {
        ll x = i / 3;
        x++;

        if(i % 3) x++;

        arr[i] = x;
    }

    j = 16;
    for(i = 1; i <= 3; i++)
    {
        if(i % 2)
        {
            for(k = 1; k <= 4; k++)
            {
                arr[j++] = i + 6;
            }
        }
        else
        {
            for(k = 1; k <= 3; k++)
            {
                arr[j++] = i + 6;
            }
        }
    }

    name[0] = "ZERO";
    name[1] = "ONE";
    name[2] = "TWO";
    name[3] = "THREE";
    name[4] = "FOUR";
    name[5] = "FIVE";
    name[6] = "SIX";
    name[7] = "SEVEN";
    name[8] = "EIGHT";
    name[9] = "NINE";


    slld(testcase);

    for(i = 0; i <= 9; i++)
    {

    }
    string in;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> in;
        slld(n);
        slld(k);
    }


}

