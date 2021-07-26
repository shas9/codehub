#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld", &n)
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define MOD 1000000007
#define inf 1000000000
#define limit 10001000

ll SQRT(ll n)
{
    ll low = 0, high = 1000000009, mid, ret;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid * mid > n)
            high = mid - 1;
        else if(mid * mid <= n)
        {
            ret = mid;
            low = mid + 1;
        }
           // low = mid + 1;
    }
    //cout << low << ' ' << high << ' ' << ret << ' ' << n << endl;
    return ret;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll tc, test, i, n, l, r, x, y;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &l, &r);

        ll s1=SQRT(l-1);
        ll s2=SQRT(r);

//        if(s1*s1==l && s1>0)
//            s1--;

        x=s2-s1;

        ll l2=(l-1)/2;
        ll r2=r/2;



        s1=SQRT(l2);
        s2=SQRT(r2);
       // cout << s1 << 'g' << s2 << endl;

//        if(s1*s1==l2 && l2*2>=l && s1>0)
//            s1--;

        y=s2-s1;

     //    cout<<x<<" "<<y<<endl;

         printf("Case %lld: %lld\n", tc, x+y);
    }


    return 0;
}

