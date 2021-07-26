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

ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    ll num[5];
    ll tot = 0;
    for(i = 0; i <= 3; i++)
    {
        slld(input);

        tot += input;

        num[i] = input;
    }

    ll ind = 0;

    for(i = 0; i <= 2; i++)
    {
        if(ind == 0)
        {
            if(num[i + 1] <= num[i]) arr[++ind] = i, num[i]--;
            else arr[++ind] = i + 1, num[i + 1]--;
        }

        if(num[i] == 0) continue;

        while(num[i] && num[i + 1])
        {
            ind++;

            if(arr[ind - 1] == i) arr[ind] = i + 1, num[i + 1]--;
            else arr[ind] = i, num[i]--;
        }

//        if(num[i] && num[i + 1] == 0 && i != 2)
//        {
//            cout << "NO" << endl;
//            return 0;
//        }
    }

    if(num[1])
    {
        if(num[1] > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        else ind++, arr[ind] = 1;
    }

    if(num[2])
    {
        if(num[2] > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        else ind++, arr[ind] = 2;
    }

    if(num[3])
    {
        if(num[3] > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        else ind++, arr[ind] = 3;
    }

    if(ind != tot)
    {
        cout << "NO" << endl;
        return 0;
    }

    for(i = 1; i <= ind - 1; i++)
    {
        if(abs(arr[i] - arr[i + 1]) > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    for(i = 1; i <= tot; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;



}



