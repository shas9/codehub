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

multiset < ll > mt;

pll arr[200005];

map < ll, bool > vis;

bool comp(pll a, pll b)
{
    if(a.first != b.first) return a.first < b.first;

    return a.second > b.second;
}

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
    }

    for(i = 1; i <= n; i++)
    {
        slld(arr[i].second);
    }

    sort(arr + 1, arr + 1 + n);

    ans = 0;
    ll sum = 0;

    arr[n + 1].first = mxlld;

    for(i = 1; i <= n; i++)
    {
        mt.insert(arr[i].second);
        sum += arr[i].second;

        j = arr[i].first;

        while(!mt.empty() && j < arr[i + 1].first)
        {
            if(j > arr[i].first) ans += sum;

            multiset < ll > :: iterator it;

            it = mt.end();
            it--;

            sum -= (*it);
            mt.erase(it);

            j++;
        }

        if(j != arr[i].first) ans += sum;
    }

    cout << ans << endl;

}



