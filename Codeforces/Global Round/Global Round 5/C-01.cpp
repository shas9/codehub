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

struct node
{
    ll id, x, y, z;

    ll dist;
};

vector < node > vec;

bool comp(node a, node b)
{
    return a.dist < b.dist;
}

ll calc(node xx)
{
    return (xx.x * xx.x) + (xx.y * xx.y) + (xx.z * xx.z);
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
        vec.clear();
        node xx;

        for(i = 1; i <= n; i++)
        {
            slld(xx.x);
            slld(xx.y);
            slld(xx.z);

            xx.id = i;

            xx.dist = calc(xx);

            vec.push_back(xx);
        }

        sort(vec.begin(),vec.end(),comp);

        for(i = 0; i < n; i += 2)
        {
            cout << vec[i].id << " " << vec[i + 1].id << endl;
        }
    }

}



