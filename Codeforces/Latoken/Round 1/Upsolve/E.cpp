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

ll dist[505];
ll par[505];


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
        for(ll i = 0; i <= n; i++) dist[i] = -1;

        dist[0] = 0;
        queue < ll > q;
        q.push(0);
        par[0] = -1;

        while(!q.empty())
        {
            ll top = q.front();
            q.pop();

            for(ll i = 0; i <= min(top,k); i++)
            {
                if((n - top) < (k - i)) continue;

                ll ntop = top - i + (k - i);

                if(ntop <= n && dist[ntop] == -1)
                {
                    dist[ntop] = dist[top] + 1;
                    par[ntop] = top;
                    q.push(ntop);
                }
            }
        }

        if(dist[n] == -1)
        {
            cout << "-1\n";
            continue;
        }

        vector < ll > path;

        for(ll i = n; i >= 0; i = par[i])
        {
            path.push_back(i);
        }

        vector < ll > sel, notsel;

        for(ll i = 1; i <= n; i++) notsel.push_back(i);

        ll ans = 0;

        while(path.size() >= 2)
        {
            ll last = path.back();
            path.pop_back();
            ll seclast = path.back();

//            for(auto it: sel) cout << it << " & ";
//            cout << "\n";
//
//            for(auto it: notsel) cout << it << " ! ";
//            cout << "\n";

            vector < ll > newsel, newnonsel;

            ll x = (last - seclast + k) / 2;

//            cout << x << " ++ \n";

            for(ll i = 1; i <= x; i++)
            {
                newnonsel.push_back(sel.back());
                sel.pop_back();
            }

            for(ll i = 1; i <= (k - x); i++)
            {
                newsel.push_back(notsel.back());
                notsel.pop_back();
            }

            cout << "? ";

            for(auto it: newnonsel) cout << it << " ";
            for(auto it: newsel) cout << it << " ";
            cout << endl;

            cin >> in;

            ans ^= in;

            for(auto it: newnonsel) notsel.push_back(it);
            for(auto it: newsel) sel.push_back(it);

        }

        cout << "! " << ans << endl;

        return 0;
    }

}

