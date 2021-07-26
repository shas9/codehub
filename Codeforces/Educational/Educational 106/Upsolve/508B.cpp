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

    string s;

    while(cin >> s)
    {
        bool on = 0;

        if((s.back() - '0') & 1)
        {
            for(ll i = 0; i + 1 < s.size(); i++)
            {
                ll x = (s[i] - '0');

                ll y = s.back() - '0';

                if(x < y && x % 2 == 0)
                {
                    swap(s[i], s.back());
                    on = 1;
                    break;
                }
            }


            if(on == 0)
            {
//                bug(1);
                for(ll i = s.size() - 2; i >= 0; i--)
                {
                    ll x = (s[i] - '0');

                    ll y = s.back();

                    if(x % 2 == 0)
                    {
                        swap(s[i], s.back());
                        on = 1;
                        break;
                    }
                }
            }
        }
        else
        {
            string t = s, v;

            map < ll, ll > st;

            ll mx = 0;

            for(ll i = 0; i + 1 < s.size(); i++) st[s[i]]++, mx = max(mx, (long long)s[i]);

            for(ll i = 0; i + 1 < s.size(); i++)
            {
                if(mx > s[i])
                {
                    for(ll j = s.size() - 2; j > i; j--)
                    {
                        if(s[j] == mx)
                        {
                            swap(s[i], s[j]);
                            on = 1;
                            break;
                        }
                    }

                    assert(on);
                    break;
                }

                st[mx]--;

                while(st[mx] == 0)
                {
                    mx--;
                }
            }

            v = s;

            for(ll i = 0; i + 1 < s.size(); i++)
            {
                ll x = (s[i] - '0');

                ll y = s.back() - '0';

                if(x < y && x % 2 == 0)
                {
                    swap(s[i], s.back());
                    on = 1;
                    break;
                }
            }

            if(on == 0)
            {
                for(ll i = s.size() - 2; i >= 0; i--)
                {
                    ll x = (s[i] - '0');

                    ll y = s.back();

                    if(x % 2 == 0)
                    {
                        swap(s[i], s.back());
                        on = 1;
                        break;
                    }
                }
            }

            if(v > s) s = v;
        }

        if(on) cout << s << "\n";
        else cout << -1 << "\n";
    }


}

