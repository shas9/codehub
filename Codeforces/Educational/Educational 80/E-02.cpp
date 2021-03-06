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

ll tree[600005];
ll pos[300005];
ll mx[300005];
ll mn[300005];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);
    slld(m);

    for(i = 1, j = n; i <= n; i++, j--)
    {
        pos[i] = j;
        update(j,1,n + m);

        mx[i] = mn[i] = i;
    }

    for(i = 1; i <= m; i++)
    {
        slld(input);

        mn[input] = 1;

        mx[input] = max(mx[input], query(n + m) - query(pos[input] - 1));

        update(pos[input],-1,n+m);

        pos[input] = n + i;

        update(pos[input],1,n+m);
    }

    for(i = 1; i <= n; i++)
    {
        mx[i] = max(mx[i], query(n + m) - query(pos[i] - 1));
    }

    for(i = 1; i <= n; i++)
    {
        cout << mn[i] << " " << mx[i] << endl;
    }


}



