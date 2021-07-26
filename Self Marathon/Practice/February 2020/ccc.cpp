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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "a", stdout);

    while(1)
    {
        string user;

        ll sth, stm;
        ll enh, enm;

        cout << "Enter User Name: ";
        cin >> user;

        cout << "Enter Start Time: ";
        cin >> sth >> stm;

        cout << "Enter End Time: ";
        cin >> enh >> enm;

        stm = stm * 100 / 60;
        enm = enm * 100 / 60;

        ll td = (enh * 100 + enm) - (sth * 100 + stm);

        td = td * 60 / 100;

        cout << "Total Hour: " << td / 60 << endl;
        cout << "Total Min: " << td % 60 << endl;


    }

}


