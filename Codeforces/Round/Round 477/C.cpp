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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e19
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll x1, y11, x2, y2;

ll cl, cv, v, q;

vector < ll > st, el;

ll uppst(ll n)
{
    ll high = st.size() - 1;
    ll low = 0;
    ll ans = high;

    while(low <= high)
    {
        ll mid = low + high;
        mid /= 2;

        if(st[mid] == n)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(st[mid] > n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
ll lowstt(ll n)
{
    ll high = st.size() - 1;
    ll low = 0;
    ll ans = 0;

    while(low <= high)
    {
        ll mid = low + high;
        mid /= 2;

        if(st[mid] == n)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(st[mid] > n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

ll uppell(ll n)
{
    ll high =  el.size() - 1;
    ll low = 0;
    ll ans = high;

    while(low <= high)
    {
        ll mid = low + high;
        mid /= 2;

        if(el[mid] == n)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(el[mid] > n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
ll lowell(ll n)
{
    ll high = el.size() - 1;
    ll low = 0;
    ll ans = 0;

    while(low <= high)
    {
        ll mid = low + high;
        mid /= 2;

        if(el[mid] == n)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(el[mid] > n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}
ll stt()
{

        ll up = uppst(y11);
        ll lo = lowstt(y11);

        ll mn;

            ll x = abs(st[up] - y2);
            ll y = abs(st[up] - y11);
            ll z = x + y;

            ll xx = abs(st[lo] - y2);
            ll yy = abs(st[lo] - y11);
            ll zz = xx + yy;

        mn = min(zz,z);

        up = uppst(y2);
        lo = lowstt(y2);

            x = abs(st[up] - y2);
            y = abs(st[up] - y11);
            z = x + y;

            xx = abs(st[lo] - y2);
            yy = abs(st[lo] - y11);
            zz = xx + yy;

        mn = min(z,mn);
        mn = min(zz,mn);

        //cout << mn << " --" << endl;

        ll ans = 0;

        ans = mn + abs(x1 - x2);

        //cout << ans << endl;

        return ans;
}

ll elt()
{
        ll up = uppell(y11);
        ll lo = lowell(y11);

        ll mn;

            ll x = abs(el[up] - y2);
            ll y = abs(el[up] - y11);
            ll z = x + y;

            ll xx = abs(el[lo] - y2);
            ll yy = abs(el[lo] - y11);
            ll zz = xx + yy;

        mn = min(zz,z);

        up = uppell(y2);
        lo = lowell(y2);

            x = abs(el[up] - y2);
            y = abs(el[up] - y11);
            z = x + y;

            xx = abs(el[lo] - y2);
            yy = abs(el[lo] - y11);
            zz = xx + yy;

        mn = min(zz,mn);
        mn = min(z,mn);

        //cout << mn << " - " << endl;

        ll ans = 0;

        ans = abs(x1 - x2) / v;

        if(abs(x1 - x2) % v != 0)
        {
            ans++;
        }

        ans += mn;

        return ans;

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    st.clear();
    el.clear();

    cin >> n >> m >> cl >> cv >> v;

    for(i = 0; i < cl; i++)
    {
        cin >> input;
        st.pb(input);
    }

    for(i = 0; i < cv; i++)
    {
        cin >> input;
        el.pb(input);
    }

    if(cl)
    sort(st.begin(),st.end());

    if(cv)
    sort(el.begin(),el.end());

    cin >> q;

    for(i = 1; i <= q; i++)
    {
        cin >> x1 >> y11 >> x2 >> y2;

        ans = mxlld;

        if(cl) ans = min(ans,stt());
        if(cv) ans = min(ans,elt());

        if(x1 == x2)
        {
            ans = abs(y11 - y2);
        }

        cout << ans << endl;
    }




}


