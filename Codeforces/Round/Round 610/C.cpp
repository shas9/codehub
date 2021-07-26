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

struct prob
{
    ll type, time;
    bool solved;
} arr[200005];

bool comp(prob a, prob b)
{
    return a.time < b.time;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll t, a, b;

        slld(n);
        slld(t);
        slld(a);
        slld(b);

        ll easy = 0;
        ll hard = 0;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].type);

            if(arr[i].type == 0) easy++;
            else hard++;
        }

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].time);
        }

        ll nowtime = 0;

        ans = 0;

        ll cnt = 0;

        sort(arr + 1, arr + 1 + n, comp);

//        for(i = 1; i <= n; i++)
//        {
//            cout << arr[i].type << " ";
//        }
//
//        cout << endl;
//
//        for(i = 1; i <= n; i++)
//        {
//            cout << arr[i].time << " ";
//        }
//
//        cout << endl;

        arr[n + 1].time = 1 + t;

        for(i = 1; i <= n; i++)
        {
            ll remaining = arr[i].time - nowtime - 1;
            ll need = 0;

            if(remaining > 0) ans = max(ans, min(cnt + min((remaining / a), easy),n));

            if(arr[i].type == 0) need = a, easy--;
            else need = b, hard--;

            nowtime += need;

            if(nowtime < arr[i + 1].time) cnt = i;

//            cout << nowtime << " ";

            ans = max(ans, cnt);
//            cnt++;
        }

        ans = max(ans,cnt);

        cout << ans << endl;

    }


}



