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

ll arr[5];
ll brr[5];


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    for(i = 1; i <= 2; i++)
    {
        slld(arr[i]);
    }

    for(i = 1; i <= 2; i++)
    {
        slld(brr[i]);
    }

    for(i = 1; i <= 2; i++)
    {
        if(i == 1) j = 2;
        else j = 1;

            if(brr[j] >= arr[i] - 1)
            {
                ll x = brr[j];

                ll cnt = x / 2;

                if(x % 2 == 0) cnt--;

                if(cnt <= arr[i])
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }


    cout << "NO" << endl;
}


