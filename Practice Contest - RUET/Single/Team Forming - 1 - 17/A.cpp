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

string x;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        if(cs == 1) getchar();
        getline(cin,x);


        ll sz = x.size();

        for(i = 0; i < sz - 2; i++)
        {
            if(x[i] == 'n' && x[i + 1] == 'o' && x[i + 2] == 't')
            {
                if(i + 3 == sz || x[i + 3] == ' ')
                {
                    if(i == 0 || x[i - 1] == ' ')
                    {
                        cout << "Real Fancy" << endl;
                        break;
                    }
                }
            }
        }

        if(i == sz - 2)
        {
            cout << "regularly fancy" << endl;
        }
    }


}



