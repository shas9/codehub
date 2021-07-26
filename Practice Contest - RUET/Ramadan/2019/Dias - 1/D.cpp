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

vector < pair < ll, ll > > vec;

ll dist(ll i, ll j)
{
    return (((vec[i].first - vec[j].first) * (vec[i].first - vec[j].first)) + ((vec[i].second - vec[j].second) * (vec[i].second - vec[j].second) ));
}

bool vis[10];
ll arr[10];
bool flag;

void solve(ll pos)
{
    if(pos == 8 )
    {
        if(flag)
        if(dist(arr[1],arr[2]) == dist(arr[1],arr[3]) && dist(arr[1],arr[2]) == dist(arr[2],arr[4]) && dist(arr[1],arr[2]) == dist(arr[4],arr[3]) && dist(arr[1],arr[4]) == dist(arr[3],arr[2]))
            if(dist(arr[5],arr[7]) == dist(arr[6],arr[8]) && dist(arr[5],arr[6]) == dist(arr[7],arr[8]) && dist(arr[5],arr[8]) == dist(arr[6],arr[7]))
            {
                cout << "YES" << endl;

                cout << arr[1] + 1 << " " << arr[2] + 1 << " " << arr[3] + 1 << " " << arr[4] + 1 << endl;
                cout << arr[5] + 1 << " " << arr[6] + 1 << " " << arr[7] + 1 << " " << arr[8] + 1 << endl;

                flag = 0;
            }
    }

    for(ll i = 0; i < 8; i++)
    {
        if(!vis[i])
        {
            arr[pos + 1] = i;
            vis[i] = 1;

            solve(pos + 1);

            vis[i] = 0;
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m)
    {
        vec.clear();

        vec.push_back(make_pair(n,m));

        for(i = 1; i < 8; i++)
        {
            cin >> n >> m;

            vec.push_back(make_pair(n,m));
        }

        memset(vis,0,sizeof vis);
        flag = 1;

        solve(0);

        if(flag)
        {
            cout << "NO" << endl;
        }

    }


}




