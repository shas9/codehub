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

ll arr[100005];
unordered_map < ll, ll > cnt;

vector < ll > v;

ll disx[] = {-1,0,1};
ll n;

ll solve(ll pos, ll num, ll diff)
{
    ll i, j, k, l;

    if(pos > n)
    {
        return 0;
    }

    ll mn = mxlld;
    ll ans;
    ll flag = num + diff;

    //cout << pos << " " << flag << " ";

    if(abs(arr[pos] - flag) > 1) return -1;

    //cout << "Entered: ";

    ans = solve(pos + 1, flag, diff);

    //cout << ans << endl;

    if(ans == -1) return -1;

    if(flag == arr[pos]) return ans;

    return ans + 1;

}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    v.clear();

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        if(i == 1) continue;

        flag = arr[i] - arr[i - 1];

        for(j = flag - 2; j <= flag + 2; j++)
        {
            cnt[j]++;

            if(cnt[j] == n - 1)
            {
                //cout << j << endl;
                v.pb(j);
            }
        }
    }

    if(n == 1)
    {
        cout << 0 << endl;

        return 0;
    }

    ll sz = v.size();

    //cout << sz << endl;

    ans = -1;

    for(i = 0; i < sz; i++)
    {
        for(j = 0; j < 3; j++)
        {
            //cout << endl << "Starting Tree: " << arr[1] + disx[j] << " " << v[i] << ":" << endl;
            flag = solve(2, arr[1] + disx[j], v[i]);

            if(flag == -1) continue;

            //cout << v[i] << " : " << j << endl;

            if(j != 1) flag++;

            if(ans == -1) ans = flag;
            else ans = min(ans,flag);
        }
    }

    cout << ans << endl;







}


