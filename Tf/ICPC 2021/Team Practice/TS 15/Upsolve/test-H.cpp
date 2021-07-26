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
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        ll ans1 = 0;

        vector < ll > vec(n);

        for(auto &it: vec) cin >> it;

        {
            vector < ll > v;

            ans = 0;

            for(auto it: vec)
            {
                in = it;
                v.push_back(in);

                while(v.size() >= 2)
                {
                    ll a1 = v.back();
                    v.pop_back();
                    ll a2 = v.back();
                    v.pop_back();

                    if(a1 == a2) v.push_back(1), ans++;
                    else
                    {
                        v.push_back(a2);
                        v.push_back(a1);

                        break;
                    }
                }
            }

            ll mone = 0;

            for(auto it: v) mone += (it == -1);

            if(v.size() == 1);
            else if(mone % 2 == 0)
            {
                ans += v.size() - 1 - 2 * (mone / 2);
            }
            else
            {
                if(v.front() == -1 || v.back() == -1)
                {
                    ans += v.size() - 2 - 2 * (mone / 2);
                    // 1 -1
                    ans -= 1;
                }
                else
                {
                    if(v.size() == 3)
                    {
                        ans -= 2;

                    }
                    else
                    {
                        ans += v.size() - 3 - 2 * (mone / 2);
                        ans -= 2;
                    }
                }
            }

            ans1 = ans;
        }

        reverse(vec.begin(), vec.end());

        {
            vector < ll > v;

            ans = 0;

            for(auto it: vec)
            {
                in = it;
                v.push_back(in);

                while(v.size() >= 2)
                {
                    ll a1 = v.back();
                    v.pop_back();
                    ll a2 = v.back();
                    v.pop_back();

                    if(a1 == a2) v.push_back(1), ans++;
                    else
                    {
                        v.push_back(a2);
                        v.push_back(a1);

                        break;
                    }
                }
            }

            ll mone = 0;

            for(auto it: v) mone += (it == -1);

            if(v.size() == 1);
            else if(mone % 2 == 0)
            {
                ans += v.size() - 1 - 2 * (mone / 2);
            }
            else
            {
                if(v.front() == -1 || v.back() == -1)
                {
                    ans += v.size() - 2 - 2 * (mone / 2);
                    // 1 -1
                    ans -= 1;
                }
                else
                {
                    if(v.size() == 3)
                    {
                        ans -= 2;

                    }
                    else
                    {
                        ans += v.size() - 3 - 2 * (mone / 2);
                        ans -= 2;
                    }
                }
            }

            ans1 = max(ans1, ans);
        }
        cout << ans1 << "\n";
    }
}
