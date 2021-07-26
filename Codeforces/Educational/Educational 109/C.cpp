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

ll ans[300005];
char str[300005];

void solve(vector < pll > &v, ll m)
{
    sort(v.begin(), v.end());

    stack < pll > st;

    for(auto &it: v)
    {
        if(str[it.second] == 'R')
        {
            st.push(it);
        }
        else
        {
            if(st.empty()) st.push(it);
            else
            {
                pll top = st.top();
                st.pop();

                if(str[top.second] == 'R')
                {
                    ll x = (it.first - top.first) / 2;

                    ans[it.second] = x;
                    ans[top.second] = x;
                }
                else
                {
                    ll t = top.first;
                    it.first -= top.first;
                    t += it.first / 2;

                    ans[it.second] = t;
                    ans[top.second] = t;
                }
            }
        }
    }

    while(!st.empty())
    {
        pll top1 = st.top();
        st.pop();

        if(st.empty()) return;

        pll top2 = st.top();
        st.pop();

        ll t = m - top1.first;

        if(str[top2.second] == 'R') t += (top1.first - top2.first) / 2;
        else
        {
            top1.first = m;

            if(top2.first > t)
            {
                top2.first -= t;
                t += top2.first;
                top1.first -= top2.first;
                top2.first = 0;
            }
            else
            {
                top2.first -= t;
                top2.first = abs(top2.first);
            }


            t += (top1.first - top2.first) / 2;
        }

        ans[top1.second] = ans[top2.second] = t;
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        vector < pll > v1, v2;

        cin >> n >> m;

        for(ll i = 1; i <= n; i++)
        {
            ans[i] = -1;

            cin >> in;

            if(in & 1) v1.push_back({in,i});
            else v2.push_back({in,i});
        }

        for(ll i = 1; i <= n; i++) cin >> str[i];

        solve(v1, m);
        solve(v2, m);

        for(ll i = 1; i <= n; i++) cout << ans[i] << " ";

        cout << "\n";
    }


}

