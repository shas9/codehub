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
        set < ll > st;
        ll now = mnlld;

        bool on = 1;

        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> in;

            if(i == 1)
            {
                now = in;
                st.insert(in);
            }
            else if(now < in)
            {
                auto it = st.upper_bound(now);

                if(it == st.end())
                {
                    st.insert(in);
                    now = in;
                }
                else
                {
                    now = in;
                    if(now > *it) on = 0;
                    st.insert(in);
                }
            }
            else if(now > in)
            {
                auto it = st.lower_bound(now);

                if(it == st.begin())
                {
                    st.insert(in);
                    now = in;
                }
                else
                {
                    it--;

                    now = in;
                    if(now < *it) on = 0;
                    st.insert(in);
                }
            }

//            cout << i << " " << on << "\n";
        }

        if(on) cout << "YES\n";
        else cout << "NO\n";
    }


}


