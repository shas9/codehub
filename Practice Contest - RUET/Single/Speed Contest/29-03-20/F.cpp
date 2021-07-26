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

ll cumsum[100005];
string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
        memset(cumsum,0,sizeof cumsum);

        for(i = 1; i < str.size(); i++)
        {
            if(str[i] == str[i - 1]) cumsum[i]++;

            cumsum[i] += cumsum[i - 1];

//            cout << cumsum[i] << " ";
        }

        cumsum[str.size()] = cumsum[str.size() - 1];

//        cout << endl;

        slld(m);

        for(i = 1; i <= m; i++)
        {
            slld(l);
            slld(r);

            ans = cumsum[r] - cumsum[l - 1];

            if(r < str.size() && str[r] == str[r - 1]) ans--;

            cout << ans << endl;
        }
    }


}



