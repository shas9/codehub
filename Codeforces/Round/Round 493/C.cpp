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

ll arr[10000];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(k);

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];

        arr[i] += arr[i - 1];
    }

    double av, mx = 0;

    for(i = 1; i <= n; i++)
    {
        av = 0;
        double sum = arr[i + k - 2] - arr[i - 1];

        //cout << sum << endl;
        for(j = i + k - 1; j <= n; j++)
        {
            sum += arr[j] - arr[j - 1];
            av = sum / (j - i + 1);

            //cout << i << " " << j << " : " << sum << " " << av << endl;
            mx = max(av,mx);
        }
    }

    printf("%.10f\n", mx);


}

