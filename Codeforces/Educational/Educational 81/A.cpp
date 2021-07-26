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

ll arr[10];
ll ans[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    arr[6] = 0;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = 5;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 6;
    arr[7] = 3;
    arr[8] = 7;
    arr[9] = 6;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        ll sz = 1;

        while(input)
        {
            if(input % 2)
            {
                cout << 7;
                input -= 3;
            }
            else
            {
                cout << 1;
                input -= 2;
            }

        }
        cout << endl;


    }


}



