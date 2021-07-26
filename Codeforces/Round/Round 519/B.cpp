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

ll arr[2000];
ll diff[2000];
vector < ll > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }
        vec.clear();

        diff[1] = arr[1];

        for(i = 2; i <= n; i++)
        {
            diff[i] = arr[i] - arr[i - 1];
        }

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                ll id = j % i;

                if(id == 0) id = i;

                if(diff[j] != diff[id]) break;
            }

            if(j > n) vec.push_back(i);
        }

        cout << vec.size() << endl;

        for(i = 0; i < vec.size(); i++) cout << vec[i] << " ";

        cout << endl;

    }


}



