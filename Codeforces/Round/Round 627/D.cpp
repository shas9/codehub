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

ll tree[500005];
map < ll, ll > mp;
ll arr[200005];
ll brr[200005];
vector < ll > vec;

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

bool comp(ll a, ll b)
{
    return a > b;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    for(i = 1; i <= n; i++)
    {
        slld(brr[i]);
    }

    ll ind = 0;

    for(i = 1; i <= n; i++)
    {
        ll x = arr[i] - brr[i];
        ll y = (x * -1) + 1;

        vec.push_back(x);
        vec.push_back(y);
    }

    sort(vec.begin(),vec.end(),comp);

    ll cnt = 0;

    mp[vec[0]] = ++cnt;

    for(i = 1; i < vec.size(); i++)
    {
        if(vec[i] == vec[i - 1]) continue;

        mp[vec[i]] = ++cnt;
    }

    ans = 0;

    for(i = 1; i <= n; i++)
    {
        ll x = arr[i] - brr[i];
        ll y = (x * (-1)) + 1;

        ans += query(mp[y]);

        update(mp[x],1,cnt);
    }

    cout << ans << endl;


}


