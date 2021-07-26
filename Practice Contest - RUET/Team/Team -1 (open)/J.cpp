#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;


    ll mod = 30000000;

    ll arr[30000000 + 5];
    ll sum[30000000 + 5];

ll srch(ll input)
{
    ll high = 30000000 + 4;
    ll low = 0;

    ll mid;

    while(high > low)
    {
        mid = (high + low) / 2;

        if(sum[mid] >= input)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return high;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input;

    ll q;

    scanlld(n);
    scanlld(m);
    scanlld(q);

    for(i = 0; i < m; i++)
    {
        scanlld(input);
        arr[i] = input;
        sum[arr[i]]++;

        printf("1: here arr[%lld] = %lld, sum[%lld] = %lld\n", i, arr[i], arr[i], sum[arr[i]]);
    }

    for(i = m; i < n; i++)
    {
        arr[i] = (arr[i - m] + arr[i - m + 1]) % mod;
        sum[arr[i]]++;

        printf("2: here i = %lld arr[%lld] = %lld, sum[%lld] = %lld\n",i, i, arr[i], arr[i], sum[arr[i]]);
    }

    for(i = 1; i < mod; i++)
    {
        sum[i] += sum[i - 1];
        printf("3: here i = %lld Sum[%lld] = %lld\n",i, arr[i], sum[arr[i]]);
    }

    for(i = 0; i < 50; i++)
    {
        printf("3: here i = %lld Sum[%lld] = %lld\n",i, i, sum[i]);
    }

    for(i = 0; i < q; i++)
    {
        scanf("%d", &input);
        ll ans = srch(input);
        printlld(ans);
    }


}

