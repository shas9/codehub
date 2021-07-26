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

vector < ll > st, en;

ll cumsum[2][300005];

ll mxans, n;
ll mxst;

bool chk(ll mid, ll xx)
{
    ll stt, enn;

    ll cost = 0;

    ll j = 1, k = 1;

    for(ll i = 1; i <= n; i++)
    {
        stt = st[i];
        enn = stt + mid;

        while(j < en.size() && en[j] <= enn)
        {
            j++;
        }

        if(en[j] > enn) j--;

        while(k < st.size() && st[k] <= stt)
        {
            k++;
        }

        cost = ((mxst-stt) * (n - k + 1)) - (cumsum[1][k]) + (enn * j) - cumsum[0][j];

//        if(xx == 9)
//        cout << st[i] << " & " << mid << " & " << cost << endl;

        if(cost <= xx)
        {
//            cout << mxst - stt << " ~ " << (n - k + 1) << " ~ " << cumsum[1][k] <<  endl;
//            cout << k << " || " <<  j << endl;
//            cout << ((mxst-stt) * (n - k + 1)) - (cumsum[1][k]) << "  && " << (enn * j) - cumsum[0][j] << endl;
//            cout << mid << " " << xx << " " << st[i] << " " << cost << endl;
            return 1;
        }
    }

    j = 1, k = 1;

    cost  = 0;
    for(ll i = 1; i <= n; i++)
    {
        enn = en[i];
        stt = enn - mid;

        while(j < en.size() && en[j] <= enn)
        {
            j++;
        }

        if(en[j] > enn) j--;

        while(k < st.size() && st[k] <= stt)
        {
            k++;
        }


        cost = ((mxst-stt) * (n - k + 1)) - (cumsum[1][k]) + (enn * j) - cumsum[0][j];

        if(cost <= xx) return 1;
    }

//    cout << mid << " " << cost << endl;

    return 0;
}

ll solve(ll xx)
{
    ll lo = 0;
    ll hi = mxans;
    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(chk(mid,xx))
        {
            ret = mid;
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
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    memset(cumsum,0,sizeof cumsum);

    mxans = mxlld;
    mxst = mnlld;

    for(i = 1; i <= n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        mxans = min(mxans, abs(u - v));

        mxst = max(mxst, u);
        st.push_back(u);
        en.push_back(v);

    }

    st.push_back(-1);
    en.push_back(-1);

    sort(st.begin(),st.end());
    sort(en.begin(),en.end());

    slld(m);

    for(i = 1; i <= n; i++)
    {
        cumsum[0][i] = en[i] + cumsum[0][i - 1];

//        cout << cumsum[0][i] << " ";
    }

//    cout << endl;

    for(i = n; i >= 1; i--)
    {
        cumsum[1][i] = (mxst - st[i]) + cumsum[1][i + 1];

//        cout << cumsum[1][i] << " ";
    }

//    cout << endl;

    for(i = 1; i <= m; i++)
    {
        slld(input);

        ans = solve(input);

//        cout << "-- ";
        plld(ans);
    }
}


