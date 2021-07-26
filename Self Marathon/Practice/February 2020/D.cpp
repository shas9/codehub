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

vector < ll > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll a, b;

    while(cin >> n >> a >> b >> k)
    {
        vec.clear();

        for(i = 1; i <= n; i++)
        {
            slld(input);

            ll x = input % (a + b);

            if(x == 0) x = (a + b);

            ll y = x / a;

            if(x % a) y++;
            y--;

//            cout << y << endl;

            vec.push_back(y);
        }

        sort(vec.begin(),vec.end());

        for(i = 0; i < vec.size(); i++)
        {
            if(k < vec[i]) break;

            k -= vec[i];
        }

        cout << i << endl;
    }

}


