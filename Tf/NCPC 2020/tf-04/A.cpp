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

#define ll int
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

struct node
{
    ll first;
    ll second;
};

ll divv1[100005];
ll divv3[100005][129];
node tree[129][300005];

node max(node a, node b)
{
    if(a.first == b.first)
        if(a.second > b.second) return a;
        else return b;

    if(a.first > b.first) return a;
    return b;
}

void precalc()
{
    memset(divv1,0,sizeof divv1);
    memset(divv3,0,sizeof divv3);

    divv1[1] = 1;

    divv3[1][1] = 1;
    for(ll i = 2; i <= 100000; i++)
    {
        for(ll j = 1; j * j <= i; j++)
        {
            if(i % j) continue;

            ll x = j;
            ll y = i / j;


            if(divv1[x] <= 128)
            {
                if(divv3[i][divv1[x]] != 0) divv3[i][divv1[x]] = -1;
                else
                divv3[i][divv1[x]] = x;
            }

            divv1[i]++;

            if(x == y) continue;

            divv1[i]++;

            if(x == i || y == i) continue;

            if(divv1[y] <= 128)
            {
                if(divv3[i][divv1[y]] != 0) divv3[i][divv1[y]]  = -1;
                else
                divv3[i][divv1[y]] = y;
            }


        }
        if(divv1[i] <= 128)
        {
            if(divv3[i][divv1[i]] != 0) divv3[i][divv1[i]] = -1;
            divv3[i][divv1[i]] = i;
        }


    }

//    ll mx = 0;
//    for(ll i = 1; i <= 100000; i++)
//
//        cout << mx << endl;
}


//ll solve(ll l, ll r, ll k)
//{
//    ll x = divv[r][k] - divv[l - 1][k];
//
////    cout << x << endl;
//
//    if(x) return x;
//
//    return -1;
//}

void init(ll node, ll b, ll e, ll k)
{
    if(b == e)
    {
        tree[k][node].first = divv3[b][k];
        tree[k][node].second = b;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid, k);
    init(right, mid + 1, e, k);

    tree[k][node] = max(tree[k][left], tree[k][right]);
}

node sum(ll node, ll b, ll e, ll i, ll j, ll k)
{
    if(i > e || j < b)
    {
        return {-1,-1};
    }

    if(b >= i && e <= j)
    {
        return tree[k][node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    node p1, p2;

    p1 = sum(left, b, mid, i, j, k);
    p2 = sum(right, mid + 1, e,i, j, k);

    return max(p1,p2);


}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    slld(testcase);

    for(i = 1; i <= 128; i++)
    {
        init(1,1,100000,i);
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> l >> r >> k;

//        ll num = solve(l,r,k);
//
////        cout << num << endl;
//
//        if(num == -1)
//        {
////            bug;
//            cout << -1 << endl;
//            continue;
//        }

//        cout << divv3[r][k].second << " " << divv3[r][k].first << endl;

//        bug;

//        for(i = 1; i <= 10; i++)
//        {
//            cout << divv3[i][k] << " ";
//        }
//
//        cout << endl;
        node numm = sum(1,1,100000,l,r,k);

//        bug;

//        cout << divv3[r][k] << endl;

        if(numm.first == 0)
        {
            cout << -1 << endl;
            continue;
        }
        cout <<numm.second << " " << numm.first << endl;
    }


}


