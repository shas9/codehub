#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

struct pos
{
    ll x, y;
} arr[200005];

bool comp1(pos a, pos b)
{
    return a.x < b.x;
}

bool comp2(pos a, pos b)
{
    return a.y < b.y;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll sx, sy;
    ll tx, ty;

    while(cin >> n >> sx >> sy)
    {
        ans = 0;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].x);
            slld(arr[i].y);
        }

        sort(arr + 1, arr + 1 + n, comp1);

        ll bam = 1, dan = n;

        ll lo = 1;
        ll hi = n;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(arr[mid].x >= sx)
            {
                bam = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        lo = 1;
        hi = n;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(arr[mid].x >= sx)
            {
                dan = mid;
                hi = mid - 1;
            }
            else
            {

                lo = mid + 1;
            }
        }

        if(bam > 0 && arr[bam].x >= sx)bam--;

        if(dan > 0)
            if(arr[dan].x <= sx) dan = n - dan;
            else dan = n - dan + 1;

        ans = max(bam,dan);

        if(ans == bam)
        {
            tx = sx - 1;
            ty = sy;
        }

        if(ans == dan)
        {
            tx = sx + 1;
            ty = sy;
        }

        sort(arr + 1, arr + 1 + n, comp2);

        ll upor = n, nich = 1;

        lo = 1;
        hi = n;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(arr[mid].y >= sy)
            {
                nich = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        lo = 1;
        hi = n;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(arr[mid].y >= sy)
            {
                upor = mid;
                hi = mid - 1;
            }
            else
            {

                lo = mid + 1;
            }
        }

        if(nich > 0)
            if(arr[nich].y >= sy) nich--;

        if(upor > 0)
            if(arr[upor].y <= sy) upor = n - upor;
            else upor = n - upor + 1;

        ans = max(ans,max(nich,upor));

        if(ans == nich)
        {
            tx = sx;
            ty = sy - 1;
        }

        if(ans == upor)
        {
            tx = sx ;
            ty = sy + 1;
        }

        cout << ans << "\n" << tx << " " << ty << "\n";

    }


}


