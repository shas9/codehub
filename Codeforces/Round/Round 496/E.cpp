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

ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    ll st = 0;

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        if(arr[i] == m)
        {
            st = i;
        }
    }

    ll small = 0;
    ll great = 0;

    ll choto, boro;

    ll cnt = 0;

    //cout << st << endl;

    for(i = st; i <= n; i++)
    {
        if(arr[i] > m) great++;
        else if(arr[i] < m) small++;

        choto = 0;
        boro = 0;
        for(j = st; j >= 1; j--)
        {
            //cout << i << " " << j << endl;
            if(arr[j] < m) choto++;
            else if(arr[i] > m) boro++;

            if((boro + great) == (small + choto)) cnt++;
            if((boro + great) - (small + choto) == 1) cnt++;

            //cout << cnt << endl;
        }
    }

    cout << cnt << endl;

}


