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

ll arr[5000005];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll x;
    cin >> q >> x;

    ans = 0;

    for(i = 1; i <= q; i++)
    {
        slld(input);

        ll dist = abs(ans - input);

        ll div = dist / x;

        ll z;

        if(ans == input)
        {
            arr[input]++;
        }
        else if(ans > input)
        {
            if((div * x) + input == ans)
            {
                z = ans;
            }
            else
            {
                div++;
                z = input + (div * x);
            }

            if(z <= 5000000)
            arr[z]++;
        }
        else
        {
            z = input - (div * x);

            if(z <= 5000000)
            arr[z]++;
        }

        while(arr[ans])
        {
            if(arr[ans] > 1)
            {
                ll dd = ans + x;

                if(dd <= 5000000)
                {
                    arr[dd] += (arr[ans] - 1);
                    arr[ans] = 1;
                }
            }
            ans++;
        }

        cout << ans << endl;


    }


}



