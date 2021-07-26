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

string a, b;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> a;

    b = a;

    reverse(b.begin(),b.end());

    ll arr[30];

    memset(arr,0,sizeof arr);

    ll sz = a.size();
    for(i = 0; i < sz; i++)
    {
        ll id = a[i] - 'a';

        arr[id]++;
    }

    bool on = 0;

    ll odd = 0;

    for(i = 0; i < 30; i++)
    {
        if(arr[i] == 0) continue;

        if(arr[i] % 2) odd++;
    }


    if(b == a || odd <= 1)
    {
        ans = 1;
    }
    else
    {
        ll sz = a.size();

        if(sz % 2) ans = 1;
        else ans = 2;
    }

    if(ans == 1) cout << "First" << endl;
    else cout << "Second" << endl;


}


