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

vector < ll > vec;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll mx = 0;

        cin >> n;
        vec.resize(n);

        for(auto &it: vec)
        {
            cin >> it;
            mx = max(mx, it);
        }

        ll idx = -1;

        for(ll i = 0; i < n; i++)
        {
            if(vec[i] == mx)
            {
                if(i)
                {
                    if(vec[i - 1] != mx)
                    {
                        idx = i + 1;
                    }
                }

                if(i + 1 < n)
                {
                    if(vec[i + 1] != mx)
                    {
                        idx = i + 1;
                    }
                }
            }
        }

        cout << idx << "\n";
    }


}

