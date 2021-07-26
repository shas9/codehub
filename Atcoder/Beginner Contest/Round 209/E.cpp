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

vector < vector < ll > > g1, g2;
vector < pll > v;
string s[200005];
ll poss[200005];


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        map < string, ll > mp;

        for(ll i = 1; i <= n; i++)
        {
            cin >> s[i];

            string f = "", b = "";

            for(ll j = 0; j < 3; j++) f += s[i][j];
            for(ll j = s[i].size() - 1; j >= s[i].size() - 3; j--) b += s[i][j];
            reverse(b.begin(), b.end());

            mp[f] = 0;
            mp[b] = 0;
        }

        ll cnt = 1;

        for(auto it: mp)
        {
            it.second = cnt++;
        }

        g1.assign(cnt,{});
        g2.assign(cnt,{});
        v.resize(n + 1);

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 0; j < 3; j++) f += s[i][j];
            for(ll j = s[i].size() - 1; j >= s[i].size() - 3; j--) b += s[i][j];
            reverse(b.begin(), b.end());

            ll x = mp[f];
            ll y = mp[b];

            v[i] = {x,y};

            g1[x].push_back(i);
            g2[y].push_back(i);

        }

        memset(poss, -1, sizeof pos);

        queue < ll > q;

        for(ll i = 1; i <= n; i++)
        {
            if(g2[v[i].second].empty())
            {
                poss[v[i].first] = 2;
                q.push(v[i].first);
            }

            if(v[i].first == v[i].second)
            {
                poss[v[i].first] = max(poss[v[i].first], 1LL);
            }
        }

        while(!q.empty())
        {
            ll top = q.front();
            q.pop();


        }
    }


}


