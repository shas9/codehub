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

    set < char > st;
    string s;

    while(cin >> s)
    {
        st.clear();

        for(auto it: s) st.insert(it);

        if(st.size() == 1)
        {
            cout << "-1\n";
        }
        else
        {
            ans = mxlld;
            for(ll i = 0; i < s.size(); i++)
            {
                string t = "";

                for(ll j = i; j < s.size(); j++)
                {
                    t += s[j];

                    string u = t;
                    reverse(u.begin(), u.end());

                    if(t != u)
                    {
                        ans = min(ans, j - i + 1);
                    }
                }
            }

            if(ans == mxlld) ans = -1;

            cout << ans << "\n";
        }
    }


}
