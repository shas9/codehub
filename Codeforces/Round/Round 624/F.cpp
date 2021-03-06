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

struct node{

    ll pos, speed;
};

node arr[200005];
vector < ll > ox;
map < ll, ll > mp;

bool comp(node a, node b)
{
    if(a.speed == b.speed) return a.pos < b.pos;
    return a.speed < b.speed;
}

ll tree[200005];
ll tree2[200005];

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

ll query2(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree2[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update2(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree2[idx]+=x;
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

    while(cin >> n)
    {
        memset(tree,0,sizeof tree);
        ox.clear();
        mp.clear();
        memset(tree2,0,sizeof tree2);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].pos);

            ox.push_back(arr[i].pos);
        }

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].speed);
        }

        sort(ox.begin(),ox.end());
        sort(arr + 1, arr + 1 + n, comp);

        for(i = 0; i < ox.size(); i++)
        {
            mp[ox[i]] = i + 1;
        }

        ans = 0;

        update(mp[arr[1].pos],arr[1].pos,n);
        update2(mp[arr[1].pos],1,n);

//        cout << mp[arr[1].pos] << endl;

        for(i = 2; i <= n; i++)
        {
            ans += (arr[i].pos * query2(mp[arr[i].pos])) - query(mp[arr[i].pos]);
//
//            cout << mp[arr[i].pos] << endl;
//
//            cout << ans << " ~ " << query2(mp[arr[i].pos]) << " " << query(mp[arr[i].pos]) << endl;

            update(mp[arr[i].pos],arr[i].pos,n);
            update2(mp[arr[i].pos],1,n);

        }

//        bug;

        cout << ans << endl;
    }


}


