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

map < ll, bool > mp;
ll arr[100005];

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

        ll a, b;

        slld(a);
        slld(b);

        sort(arr + 1, arr + 1 + n);

        arr[0] = 0;
        for(i = 1; i <= n; i++)
        {
            if(arr[i] == arr[i - 1]) continue;

            ll st = b / arr[i];

            if(b % arr[i]) st++;

            for(j = st; j * arr[i] <= a; j++)
            {
                mp[j * arr[i]] = 1;
            }
        }

        ans = 0;
        ll last = a;

        for(i = a - 1; i >= b; i--)
        {
            if(mp.find(i) == mp.end()) continue;

            ans++;
            last = i;

            cout << last << " && ";
        }

        cout << endl;

        ans += (last - b);

        plld(ans);
    }


}


