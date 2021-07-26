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

pll arr[1000006];
ll brr[1000006];
deque < ll > dq;

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
        slld(brr[i]);

        arr[i] = make_pair(brr[i],i);
    }

    sort(arr + 1, arr + 1 + n);

    for(i = 1, j = n; i < j; i++, j--)
    {
        if(i % 2) dq.push_back(arr[i].second), dq.push_front(arr[j].second);
        else dq.push_back(arr[j].second), dq.push_front(arr[i].second);
    }

    if(n % 2)
    {
        i = (n / 2) + 1;

        ll mx = max(abs(brr[dq[0]] - arr[i].first), abs(brr[dq[dq.size() - 1]] - arr[i].first));

        if(mx == abs(brr[dq[0]] - arr[i].first)) dq.push_front(arr[i].second);
        else dq.push_back(arr[i].second);
    }

    ll sum = 0;

    for(i = 1; i < n; i++)
    {
        sum += abs(brr[dq[i]] - brr[dq[i - 1]]);
    }

    cout << sum << endl;

    for(i = 0; i < n; i++)
        cout << dq[i] << " ";

    cout << endl;


}



