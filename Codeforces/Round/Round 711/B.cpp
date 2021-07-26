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

multiset < ll > mt;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;
        mt.clear();

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            mt.insert(-in);
        }

        ans = 0;

        while(!mt.empty())
        {
            ans++;

            ll sum = 0;

            while(!mt.empty())
            {
                ll baki = sum - m;

                auto it = mt.lower_bound(baki);

                if(it == mt.end()) break;

                sum -= *it;
                mt.erase(it);
            }
        }

        cout << ans << "\n";
    }


}


