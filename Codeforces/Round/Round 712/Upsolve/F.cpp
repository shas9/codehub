 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pll > v;

ll solve(ll n)
{
    priority_queue < pll > pq;

    map < ll, bool > mp;

    ll ret = 0;

    for(auto &it: v)
    {
        if(it.first <= n && it.second <= n) return -1;

        mp[it.second] = 1;

        if(it.second <= n)
        {
            swap(it.first, it.second);
        }

        pq.push({-it.first, it.second});
    }

    pll last = {mnlld, mxlld};

    while(!pq.empty())
    {
        pll top = pq.top();
        pq.pop();

        top.first *= -1;

//        cout << last.first << " " << last.second << " " << top.first << " " << top.second << "\n";

        if(top.first > last.first && last.second > top.second)
        {
            if(mp.find(top.first) != mp.end()) ret++;
            last = top;
        }
        else
        {
            swap(top.first, top.second);

            if(top.first <= n) return -1;

            top.first *= -1;

            pq.push(top);
        }
    }


    return min(ret, n - ret);


}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        v.resize(n);

        for(auto &it: v) cin >> it.first >> it.second;

        ans = solve(n);

        cout << ans << "\n";
    }


}
