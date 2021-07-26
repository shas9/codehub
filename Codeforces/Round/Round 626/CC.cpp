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

vector < ll > aa, bb;

bool comp(ll a, ll b)
{
    return a > b;
}

ll solve1(ll num)
{
    ll lo = 0;
    ll hi = aa.size() - 1;

    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(aa[mid] >= num)
        {
            ret = mid + 1;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}
ll solve2(ll num)
{
    ll lo = 0;
    ll hi = bb.size() - 1;

    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(bb[mid] >= num)
        {
            ret = mid + 1;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        aa.clear();
        bb.clear();

        for(i = 1; i <= n; i++)
        {
            slld(input);

            if(i == 1)
            {
                aa.push_back(input);
            }
            else if(input == 1)
            {
                aa.push_back(aa[aa.size() - 1] + 1);
            }
            else
            {
                aa.push_back(0);
            }
        }

        for(i = 1; i <= m; i++)
        {
            slld(input);

            if(i == 1)
            {
                bb.push_back(input);
            }
            else if(input == 1)
            {
                bb.push_back(bb[bb.size() - 1] + 1);
            }
            else
            {
                bb.push_back(0);
            }
        }

        ans = 0;

        sort(aa.begin(),aa.end(),comp);
        sort(bb.begin(),bb.end(),comp);

//        for(i = 0; i < aa.size(); i++)
//            cout << aa[i] << " ";
//        cout << endl;


        for(i = 1; i * i <= k; i++)
        {
            if(k % i) continue;

            j = k / i;

//            cout << i << " " << j << endl;

            ans += solve1(i) * solve2(j);

//            cout << solve1(i) << " " << solve2(j) << endl;
//
//            cout << ans << " ";

            if(i != j)
            {
                ans += solve1(j) * solve2(i);
            }


//            cout << ans << endl;


        }

        cout << ans << endl;
    }


}


