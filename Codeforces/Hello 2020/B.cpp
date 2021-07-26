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

vector < ll > seq[100005];

ll mnmx[100005][3];

vector < ll > mnn, mxx;
bool cc[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    ll dd = 0;
    for(i = 1; i <= n; i++)
    {
        ll mn = mxlld;
        ll mx = 0;
        ll len;

        slld(len);

        for(j = 0; j < len; j++)
        {
            slld(input);

            seq[i].push_back(input);

            if(mn < input) cc[i] = 1;

            mn = min(input,mn);
            mx = max(input,mx);
        }

        mnmx[i][0] = mn;
        mnmx[i][1] = mx;

        if(cc[i])
        {
            dd++;
            continue;
        }

        mnn.push_back(mn);
        mxx.push_back(mx);
    }

    sort(mnn.begin(),mnn.end());
    sort(mxx.begin(),mxx.end());

    ll cnt = 0;
    ans = 0;

//    cout << dd << endl;
    for(i = 1; i <= n; i++)
    {
        if(cc[i] == 1) cnt += n;
        else
        {
            ll lo = 0;
            ll hi = mxx.size() - 1;
            ans = -1;
            while(lo <= hi)
            {
                ll mid = (lo + hi) / 2;

                if(mxx[mid] <= mnmx[i][0])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                    ans = mid;
                }
            }

            if(ans == -1) ans = 0;
            else ans = mxx.size() - ans;

            cnt += ans;

            cnt += dd;
        }

//        cout << ans << " ";
//        cout << cnt << endl;
    }

    cout << cnt << endl;



}


