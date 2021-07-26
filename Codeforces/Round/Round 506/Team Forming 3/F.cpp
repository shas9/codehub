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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

vector < pll > vec, qq;
ll arr[100005];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll odd = 0;

    for(i = 0; i <= 29; i++)
    {
        odd = Set(odd,i);
    }
    ll even = 0;

    for(i = 1; i <= 29; i++)
    {
        even = Set(even,i);
    }

    while(cin >> n >> m)
    {
        vec.clear();
        qq.clear();
        memset(arr,0,sizeof arr);

        for(i = 1; i <= m; i++)
        {
            slld(l);
            slld(r);
            slld(q);

            vec.push_back(make_pair(l,r));
            qq.push_back(make_pair(l,q));
        }

        sort(vec.begin(),vec.end());
        sort(qq.begin(),qq.end());

        ll lastr = vec[0].second;
        ll lastq = qq[0].second;
        for(i = 1; i < m; i++)
        {
            if(vec[i].first <= lastr && qq[i].second != lastq)
            {
                cout << "NO" << endl;
                return 0;
            }

            if(lastr > vec[i].second)
            {
                lastr = vec[i].second;
                lastq = qq[i].second;
            }
        }

        cout << "YES" << endl;

        for(i = 0; i < m; i++)
        {
            arr[qq[i].first] = qq[i].second;

            for(j = vec[i].first; j <= vec[i].second; j++)
            {
                if(qq[i].second % 2)
                arr[j] = odd;
                else arr[j] = even;
            }
        }

        for(i = 1; i <= n; i++)
        {
            if(arr[i] == 0) cout << odd << endl;

            cout << arr[i] << " ";
        }

        cout << endl;
    }


}

