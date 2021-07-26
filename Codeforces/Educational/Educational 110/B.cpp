// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll input, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        vector < ll > v1, v2, v;

        while(n--)
        {
            cin >> input;

            if(input & 1) v1.push_back(input);
            else v2.push_back(input);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        ans = 0;

        for(auto it: v2) v.push_back(it);
        for(auto it: v1) v.push_back(it);

        for(ll i = 0; i < v.size(); i++)
        {
            for(j = i + 1; j < v.size(); j++)
            {
                if(__gcd(v[i], v[j] * 2) != 1) ans++;
            }
        }

        cout << ans << "\n";
    }


}

