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

pll ven[3][100005];
ll ss[6][100005];
ll n;
map < ll, ll > mp[6];

ll chk(ll vv, ll pos)
{
    ll start = ven[vv][pos].first;
    ll finish = ven[vv][pos].second;

    ll lo = 1;
    ll hi = n;

    if(mp[vv][start] > 1) return 1;
//    cout << vv << " - " << pos << endl;
//    cout << start << " & " << finish << endl;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(ss[vv][mid] <= start)
        {
            lo = mid + 1;
        }
        else if(ss[vv][mid] > finish)
        {
            hi = mid - 1;
        }
        else
        {
//            cout << ss[vv][mid] << " " << mid << endl;
            return 1;
        }
    }

    lo = 1;
    hi = n;

    if(mp[vv + 2][finish] > 1) return 1;
//    cout << vv << " - " << pos << endl;
//    cout << start << " & " << finish << endl;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(ss[vv + 2][mid] < start)
        {
            lo = mid + 1;
        }
        else if(ss[vv + 2][mid] >= finish)
        {
            hi = mid - 1;
        }
        else
        {
//            cout << ss[vv][mid] << " " << mid << endl;
            return 1;
        }
    }

    return 0;
}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n)
    {
//        cout << n << endl;

        mp[1].clear();
        mp[2].clear();
        mp[3].clear();
        mp[4].clear();

        for(i = 1; i <= n; i++)
        {
            slld(ven[1][i].first);
            slld(ven[1][i].second);

            slld(ven[2][i].first);
            slld(ven[2][i].second);

            ss[1][i] = ven[1][i].first;
            ss[2][i] = ven[2][i].first;

            ss[3][i] = ven[1][i].second;
            ss[4][i] = ven[2][i].second;

            mp[1][ss[1][i]]++;
            mp[2][ss[2][i]]++;

            mp[3][ss[3][i]]++;
            mp[4][ss[4][i]]++;

        }

        sort(ss[1] + 1, ss[1] + 1 + n);
        sort(ss[2] + 1, ss[2] + 1 + n);
        sort(ss[3] + 1, ss[3] + 1 + n);
        sort(ss[4] + 1, ss[4] + 1 + n);

//        for(i = 1; i <= 2; i++)
//        {
//            for(j = 1; j <= n; j++)
//            {
//                cout << ss[i][j] << " ";
//            }
//
//            cout << endl;
//        }


        for(i = 1; i <= n; i++)
        {
//            cout << chk(1,i) << " " << chk(2,i) << endl;
            if((chk(1,i) || chk(2,i)))
            {
                cout << "NO" << endl;

//                cout << i << endl;
                break;
            }
        }

        if(i > n)
        {
            cout << "YES" << endl;
        }
    }


}

