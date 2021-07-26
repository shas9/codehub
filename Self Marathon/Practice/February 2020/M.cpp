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

vector < ll > v[3];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll num = 0;


    cin >> n;

    ll bit = 0;

    while((1 << bit) <= n)
    {
        bit++;
    }

    for(i = 1; i <= n; i++)
    {
        v[2].push_back(i);
    }

    for(i = 0; i < bit; i++)
    {
        ll bitt;

        for(j = 0; j < v[2].size(); j++)
        {
            cout << "? " <<  v[2][j] << " " << i << endl;
            cin >> input;

            v[input].push_back(v[2][j]);
        }

        if(v[2].size() % 2)
        {
            if(v[0].size() < v[1].size())
            {
                bitt = 0;
            }
            else
            {
                bitt = 1;
            }
        }
        else
        {
            if(v[0].size() == v[1].size())
            {
                bitt = 0;
            }
            else
            {
                bitt = 1;
            }
        }

//        cout <<  " -- " <<  bitt << endl;

        v[2].clear();
        for(j = 0; j < v[bitt].size(); j++)
        {
            v[2].push_back(v[bitt][j]);
        }

        v[0].clear();
        v[1].clear();

        if(bitt) num = Set(num,i);
    }

    cout << "! " << num << endl;

}


