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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[500];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll a, b, x;

    slld(a);
    slld(b);
    slld(x);

    swap(a,b);

    n = a + b;

    if(x == 1)
    {
        for(i = 1; i <= a; i++) cout << 1;
        for(i = 1; i <= b; i++) cout << 0;

        cout << endl;
        return 0;
    }
    if(a < b)
    {
        arr[1] = 0;
        arr[2] = 1;
        x--;
         a--;
            b--;

        for(i = 3; x > 1; x--)
        {
            if(arr[i - 1] == 1)
            {
                arr[i] = 0;
                b--;
            }
            else
            {
                arr[i] = 1;
                a--;
            }
            i++;
        }
    }
    else
    {
        arr[1] = 1;
        arr[2] = 0;
        x--;
        a--;
            b--;

        for(i = 3; x > 1; x--)
        {
            if(arr[i - 1] == 1)
            {
                arr[i] = 0;
                b--;
            }
            else
            {
                arr[i] = 1;
                a--;
            }
            i++;
        }
    }

    if(arr[i - 1] == 1)
    {
        while(a--)
        {
            arr[i++] = 1;
        }

        while(b--)
        {
            arr[i++] = 0;
        }
    }
    else
    {
        while(b--)
        {
            arr[i++] = 0;
        }
        while(a--)
        {
            arr[i++] = 1;
        }
    }

    for(i = 1; i <= n; i++) cout << arr[i];

    cout << endl;



}


