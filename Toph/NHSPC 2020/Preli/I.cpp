// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

deque < ll > dq[4];
string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
        for(ll i = 0; i < 4; i++) dq[i].clear();

        for(ll i = 0; i < n; i++)
        {
            if(str[i] == 'c') dq[0].pb(i);
            else if(str[i] == 'o') dq[1].pb(i);
            else if(str[i] == 'd') dq[2].pb(i);
            else if(str[i] == 'e') dq[3].pb(i);
        }

        ans = 0;
        while(!dq[0].empty() && !dq[1].empty() && !dq[2].empty() && !dq[3].empty())
        {
            ll x = dq[3].front();
            dq[3].pop_front();

            if(x < dq[2].front()) continue;

            x = dq[2].front();
            dq[2].pop_front();

            if(x < dq[1].front()) continue;

            x = dq[1].front();
            dq[1].pop_front();

            if(x < dq[0].front()) continue;

            dq[0].pop_front();
            ans++;
        }

        printf("%lld\n", ans);
    }




}



