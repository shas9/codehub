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

ll arr[300005];
string str;
ll cnt[30];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(cnt,0,sizeof cnt);

        slld(n);
        slld(m);

        for(i = 0; i <= n; i++) arr[i] = 0;

        cin >> str;

        for(i = 1; i <= m; i++)
        {
            slld(input);

            arr[input - 1]++;
        }

        arr[n] = 1;
        for(i = n - 1; i >= 0; i--)
        {
            arr[i] += arr[i + 1];
        }



        for(i = 0; i < n; i++)
        {
            ll nn = str[i] - 'a';

            cnt[nn] += arr[i];
        }

        for(i = 0; i < 26; i++)
        {
            cout << cnt[i] << " ";
        }

        cout << endl;
    }


}



