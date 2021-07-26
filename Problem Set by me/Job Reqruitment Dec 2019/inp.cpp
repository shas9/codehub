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

void gen()
{
    ll t = rand() % 10;

    if(t == 0) t++;


    t = 10;
    cout << t << endl;

    ll n = 11;
    ll xx = 10000000000;
    while(t--)
    {
//        ll n = rand() % 12;
//
//        if(n == 0) n++;

        ll x = 10000000000;

        if(x == 0) x++;

        cout << n << " " << x << endl;

        for(ll i = 1; i <= n; i++)
        {


            xx -= 100000000;



            cout << abs(xx) << " ";
        }

        cout << endl;
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

    srand(time(NULL));

//    for(i = 5; i <= 9; i++)
    {
        string str = "input2";

        str += (i + '0');

        str += ".txt";

        char str2[30];
        for(j = 0; j < str.size(); j++)
        {
            str2[j] = str[j];
        }

        str2[j] = '\0';

        char *str3 = str2;

        freopen("input00.txt", "w", stdout);

        gen();


    }


}

