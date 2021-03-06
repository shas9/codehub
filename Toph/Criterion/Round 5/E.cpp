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

pll arr[200005];
ll brr[200005];
ll ans1[200005];
ll ans2[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i].first);

        brr[i] = arr[i].first;
        arr[i].second = i;
    }

    sort(arr + 1, arr + 1 + n);

    ll cnt1 = 0, cnt2 = 0;

    i = 1, j = n, k = 1;

    while(i <= j)
    {
        if(k % 2) ans1[k] = arr[i].second, i++;
        else ans1[k] = arr[j].second, j--;

        k++;
    }

    i = 1, j = n, k = 1;

    while(i <= j)
    {
        if(k % 2 == 0) ans2[k] = arr[i].second, i++;
        else ans2[k] = arr[j].second, j--;

        k++;
    }

    for(i = 1; i < n; i++)
        cnt1 += abs(brr[ans1[i]] - brr[ans1[i + 1]]);

    for(i = 1; i < n; i++)
        cnt2 += abs(brr[ans2[i]] - brr[ans2[i + 1]]);


    printf("%lld\n", max(cnt1,cnt2));

    if(cnt1 >= cnt2)
    {
        for(i = 1; i <= n; i++)
        {
            if(i > 1) printf(" ");

            printf("%lld", ans1[i]);
        }
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            if(i > 1) printf(" ");

            printf("%lld", ans2[i]);
        }
    }

    printf("\n");




}



