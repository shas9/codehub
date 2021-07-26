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

deque < ll > dq;
ll brr[1000006];
pll arr[1000006];

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

    dq.push_back(arr[1].second);
    dq.push_back(arr[n].second);

//    cout << arr[1].second << " " << arr[n].second

    ll sz = dq.size() - 1;
    ll last = 0;

    i = 2;
    j = n - 1;
    while(i <= j)
    {
        ll lft1 = abs(brr[dq[0]] - arr[i].first);
        ll lft2 = abs(brr[dq[0]] - arr[j].first);

        ll rgt1 = abs(brr[dq[sz]] - arr[i].first);
        ll rgt2 = abs(brr[dq[sz]] - arr[j].first);

        ll mx = max(lft1, max(lft2, max(rgt1,rgt2)));

        if(lft1 == mx) dq.push_front(arr[i].second), i++;
        else if(lft2 == mx) dq.push_front(arr[j].second), j--;
        else if(rgt1 == mx) dq.push_back(arr[i].second), i++;
        else if(rgt2 == mx) dq.push_back(arr[j].second), j--;
    }

    ll cnt = 0;

    for(i = 1; i < n; i++)
    {
        cnt += abs(brr[dq[i]] - brr[dq[i - 1]]);
    }

    cout << cnt << endl;

    for(i = 0; i < n; i++)
    {
        cout << dq[i] << " ";
    }

    cout << endl;

}



