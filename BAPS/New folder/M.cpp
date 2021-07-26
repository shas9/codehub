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

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

vector < ll > v;
vector < ll > a;
vector < ll > I;
vector < ll > seq;
ll n;
ll inf = 2000000000;

ll lisnlogk()
{
    ll i;

    I = vector < ll > (n + 1, inf);

    I[0] = -inf;
    //for(i = 1; i <= n; i++) I[i] = inf;

    ll len = 0;

    for(i = 0; i < n; i++)
    {
        ll lo = 0;
        ll hi = len;
        ll mid;

        while(lo <= hi)
        {
            mid = (lo + hi) / 2;

            if(I[mid] < a[i]) lo  = mid + 1;
            else hi = mid - 1;
        }

        I[lo] = a[i];

        if(len < lo) len = lo;
        v.pb(lo);

    }

    return len;


}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

////    freopen("in.txt", "r", stdin);
////    freopen("out.txt", "w", stdout);

    v.clear();
    while(scanf("%lld", &input) != EOF)
    {
        a.pb(input);
    }

    n = a.size();

    ll len = lisnlogk();
    cout << len << endl;
    cout << "-" << endl;

//    for(i = 0; i < I.size(); i++)
//    {
//        cout << I[i] << endl;
//    }
//
    seq = vector < ll > (len);

    for(i = n - 1; i >= 0; i--)
    {
        if(len == v[i]) break;
        ll top = len - 1;

        seq[top] = a[i];

        for(j = i - 1; j >= 0; j--)
        {
            if(v[j] == v[i] - 1 && a[j] < a[i])
            {
                seq[--top] = a[j];
                i = j;
            }
        }
    }

    for(i = 0; i < len; i++)
    {
        cout << seq[i] << endl;
    }



}

