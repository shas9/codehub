 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

string str;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
        vector < ll > vec;
        vec.assign(30,0);

        for(auto it: str) vec[it - 'a']++;

        sort(vec.begin(),vec.end());

        ll cnt = 0;

        for(auto it: vec) if(it) cnt++;

        ans = 0;

        for(auto it: vec)
        {
            if(cnt <= 2) break;

            if(it == 0) continue;

            cnt--;
            ans += it;
        }

        cout << ans << "\n";
    }


}


