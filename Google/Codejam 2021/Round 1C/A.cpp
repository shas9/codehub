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

set < ll > st;

ll dx[] = {1,-1};

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
        st.clear();

        cin >> n >> k;

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            st.insert(in);
        }

        ll mx = 0;

        for(auto it: st)
        {
            for(auto jt: st)
            {
                for(ll i = 0; i < 2; i++)
                {
                    for(ll j = 0; j < 2; j++)
                    {
                        ll x = it + dx[i];
                        ll y = jt + dx[j];

                        if(x <= 0 || y <= 0) continue;
                        if(x > k || y > k) continue;

                        if(st.find(x) != st.end()) continue;
                        if(st.find(y) != st.end()) continue;

//                        cout << x << " " << y << "\n";

                        if(x == y) continue;

                        ll cnt = 0;

                        auto xt = st.upper_bound(x);
                        auto yt = st.upper_bound(y);


                        if(xt == yt)
                        {
                            if(xt == st.end()) assert(0);

                            cnt = max(x,y) - min(x,y) + 1;
                        }
                        else
                        {
                            if(i == 0)
                            {
                                auto kt = st.upper_bound(x);

                                ll val = k + 1;

                                if(kt != st.end())
                                {
                                    val = *kt;

                                    ll dist = val - x;

                                    cnt += (dist + 1) / 2;
                                }
                                else
                                {
                                    ll dist = val - x;

                                    cnt += dist;
                                }
                            }
                            else if(i)
                            {
                                auto kt = st.lower_bound(x);

                                ll val = 0;

                                if(kt != st.begin())
                                {
                                    kt--;
                                    val = *kt;

                                    ll dist = x - val;
                                    cnt += (dist + 1) / 2;
                                }
                                else
                                {
                                    ll dist = x - val;
                                    cnt += dist;
                                }
                            }


//                            cout << cnt << "\n";
                            if(j == 0)
                            {
                                auto kt = st.upper_bound(y);

                                ll val = k + 1;

                                if(kt != st.end())
                                {
                                    val = *kt;

                                    ll dist = val - y;

                                    cnt += (dist + 1) / 2;
                                }
                                else
                                {
                                    ll dist = val - y;

                                    cnt += dist;
                                }
                            }
                            else if(j)
                            {
                                auto kt = st.lower_bound(y);

                                ll val = 0;

                                if(kt != st.begin())
                                {
                                    kt--;
                                    val = *kt;

                                    ll dist = y - val;
                                    cnt += (dist + 1) / 2;
                                }
                                else
                                {
                                    ll dist = y - val;
                                    cnt += dist;
                                }
                            }

                        }

//                        cout << cnt << "\n";

                        mx = max(mx, cnt);

                    }
                }
            }
        }

        for(auto it: st)
        {
            for(ll i = 0; i < 2; i++)
            {
                ll x = it + dx[i];

                if(x <= 0) continue;
                if(x > k) continue;

                if(st.find(x) != st.end()) continue;

//                cout << x << " ";

                ll cnt = 0;

                auto xt = st.upper_bound(x);

                if(i == 0)
                {
                    auto kt = st.upper_bound(x);

                    ll val = k + 1;

                    if(kt != st.end())
                    {
                        val = *kt;

                        ll dist = val - x;

                        cnt += (dist + 1) / 2;
                    }
                    else
                    {
                        ll dist = val - x;

                        cnt += dist;
                    }
                }
                else if(i)
                {
                    auto kt = st.lower_bound(x);

                    ll val = 0;

                    if(kt != st.begin())
                    {
                        kt--;
                        val = *kt;

                        ll dist = x - val;
                        cnt += (dist + 1) / 2;
                    }
                    else
                    {
                        ll dist = x - val;
                        cnt += dist;
                    }
                }

//                cout <<cnt << "\n";

                mx = max(mx, cnt);
            }
        }

//        cout << mx << "\n";

        double ans = (mx / (k * 1.0));

        cout << "Case #" << cs << ": " << setprecision(8) << fixed << ans << '\n';
    }


}

