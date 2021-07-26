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

#define maxn 1000006
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll A[maxn];
ll M[maxn];
ll id[maxn];
ll p[maxn];

void print(ll en)
{
    if(en < 0) return;
    print(p[en]);

    printf("%lld\n", A[en]);
}


int main()
{

    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    l = 0;
    ll en = 0;

    i = 0;
    while(cin >> input)
    {
        A[i] = input;

        ll pos = lower_bound(M,M+l,A[i]) - M;

        M[pos] = A[i];
        id[pos] = i;

        if(pos > 0) p[i] = id[pos - 1];
        else p[i] = -1;

        if(pos == l)
        {
            l++;
            en = i;
        }
        i++;
    }

    printf("%lld\n-\n",l);

    print(en);

}

