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

string X;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    X.clear();

    for(i = 0; i < n; i++)
    {
        X += 'a';
    }

    cout << "? "<<  X << endl;

    cin >> flag;

    for(i = 0; i < n; i++)
    {
        X[i] = 'z';

        cout << "? " << X << endl;

        cin >> ans;

        ll diff = abs(flag - ans);

        if(ans < flag)
        {
            ll __x = ((('z' - 'a') + ('a' - 'a') + diff) / 2);
            X[i] = __x + 'a';

//            cout << __x << " -- " << endl;
        }
        else
        {
            ll __x = (('z' - 'a') + ('a' - 'a') - diff) / 2 ;
            X[i] = __x + 'a';

//            cout << __x << " -- " << endl;
        }

        flag = flag - (X[i] - 'a');

//        cout << flag << endl;
    }

    cout << "! " << X << endl;



}



