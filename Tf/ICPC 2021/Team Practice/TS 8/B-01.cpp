 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

vector < ll > vec;

bool solve()
{
    map < ll, ll > mp;

    for(auto it: vec) mp[it]++;

    ll processed = 0;
    ll extra = 0;

    ll ptr = 0;

    for(auto it: mp)
    {
        ll node = (it.second) / (it.first + 1);
        processed += node * (it.first * (it.first + 1) / 2);

        ll rem = (it.second % (it.first + 1));

        if(rem == 0) continue;

        processed += (rem * (rem - 1) / 2);

        ll hand = it.first - rem + 1;
        ll thand = hand;

//        cout << hand << " " << processed << " " << it.first << " " << it.second << "\n";

        for(ll i = 1; i <= rem; i++)
        {
            ll x = min(hand, extra);

            hand -= x;
            extra -= x;

            x = min(hand / 2, processed);

            hand -= (x * 2);
            processed += (thand - hand);

            extra += hand;
        }
    }

    if(extra & 1) return 0;

    return 1;
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
        cin >> n;
        vec.resize(n);

        for(auto &it: vec) cin >> it;

        if(solve()) cout << "Y\n";
        else cout << "N\n";
    }


}


