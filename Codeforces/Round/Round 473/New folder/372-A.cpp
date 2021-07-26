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

ll getnum(ll n)
{
    ll high = arr.size();
    ll low = 0;
    ll ans = -1;

    while(low <= high)
    {
        ll mid = (low + high) / 2;

        if(arr[mid] * 2 <= n && vis[mid] == 0)
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
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    arr.clear();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        arr.pb(input);
    }

    memset(vis,false,sizeof(vis));

    ans = 0;

    sort(arr.begin(),arr.end());
    for(i = testcase - 1; i >= 0; i--)
    {
        ll num = arr[i];

        //cout << num << " - ";
        if(vis[num] == 0)
        {
            vis[num] = 1;

            n = getnum(num);

            if(n == -1)
            {
                break;
            }

            //cout << arr[n] << endl;
            ans++;

            vis[n] = 1;
        }
    }

    flag = arr.size() / 2;

    if(arr.size() % 2 != 0) flag++;
    cout << max(flag, arr.size() - ans) << endl;




}

