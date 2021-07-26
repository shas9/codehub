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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

vector < ll > arr;
bool vis[500005];

ll solve(ll num, ll high)
{
    ll low = 0;
    ll mid;
    ll ans = -1;

    while(low <= high)
    {
        mid = high + low;
        mid /= 2;

        if(vis[mid] == true)
        {
            high = mid - 1;
        }
        else if(arr[mid] * 2 <= num)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(ans >= 0)
    {
        vis[ans] = true;
    }
    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    memset(vis,false,sizeof vis);
    arr.clear();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        arr.pb(input);
    }

    sort(arr.begin(),arr.end());

    ans = testcase;
    for(i = testcase - 1; i >= 1; i--)
    {
        //if(vis[i] == true) continue;
        ll x = solve(arr[i], i - 1);

        if(x == -1) break;

//        for(j = 0; j <= testcase; j++)
//        {
//            cout << vis[j] << " ";
//        }
//
//        cout << endl;
//
        //cout << i << " " << arr[i] << "-" << x << endl;
        ans--;
    }

    ll temp = testcase / 2;

    if(testcase % 2 != 0) temp++;

    ans = max(ans,temp);

    cout << ans << endl;


}

