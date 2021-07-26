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

map < string, ll > mp;
map < ll, string > mp2;
bool on[10];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    mp["purple"] = 1;
    mp["green"] = 2;
    mp["blue"] = 3;
    mp["orange"] = 4;
    mp["red"] = 5;
    mp["yellow"] = 6;

    mp2[1] = "Power";
    mp2[2] = "Time";
    mp2[3] = "Space";
    mp2[4] = "Soul";
    mp2[5] = "Reality";
    mp2[6] = "Mind";

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        string in;

        cin >> in;

        on[mp[in]] = 1;
    }

    cout << 6 - testcase << endl;

    for(i = 1; i <= 6; i++)
        if(!on[i]) cout << mp2[i] << endl;


}


