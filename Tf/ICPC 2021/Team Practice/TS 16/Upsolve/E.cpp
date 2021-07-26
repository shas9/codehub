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

map < string, ll > mp;

struct node
{
    string beg = "";
    string en = "";

    ll cnt = 0;
    ll len = 0;
} v[80];

ll cnt(string s)
{
    ll ret = 0;

    for(ll i = 0; i + 3 < s.size(); i++)
    {
        if(s[i] == 'h' && s[i + 1] == 'a' && s[i + 2] == 'h' && s[i + 3] == 'a') ret++;
    }

    return ret;
}

void assign(ll idx, string s)
{
    v[idx].cnt = cnt(s);

    v[idx].beg = s;

    while(v[idx].beg.size() > 3) v[idx].beg.pop_back();

    reverse(s.begin(), s.end());

    v[idx].en = s;

    while(v[idx].en.size() > 3) v[idx].en.pop_back();

    reverse(v[idx].en.begin(), v[idx].en.end());

    v[idx].len = s.size();

    return;
}

void add(ll a, ll b, ll c)
{
    node x;

    x.cnt = v[b].cnt + v[c].cnt;
    x.len = v[b].len + v[c].len;

    string t = v[b].en + v[c].beg;

    x.cnt += cnt(t);

    if(v[b].len <= 3 && v[c].len <= 3) t = v[b].beg + v[c].en;
    else if(v[b].len <= 3) t = v[b].beg + v[c].beg + v[c].en;
    else if(v[c].len <= 3) t = v[b].beg + v[b].en + v[c].beg;
    else t = v[b].beg + v[c].en;

    x.beg = t;

    while(x.beg.size() > 3) x.beg.pop_back();

    reverse(t.begin(), t.end());

    x.en = t;

    while(x.en.size() > 3) x.en.pop_back();

    reverse(x.en.begin(), x.en.end());

    v[a] = x;

    return;
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
        mp.clear();
        ll last = -1;
        ll cnt = 0;

        cin >> n;

        for(ll i = 1; i <= n; i++)
        {
            string var;
            string op;

            cin >> var >> op;

            if(mp.find(var) == mp.end()) mp[var] = ++cnt;

            last = mp[var];

            if(op.size() == 2)
            {
                cin >> var;

                assign(last, var);
            }
            else
            {
                string a, b;
                cin >> a >> var >> b;
                add(last, mp[a], mp[b]);
            }

//            cout << v[last].beg << " " << v[last].en << " " << v[last].cnt << "\n";
        }

        cout << v[last].cnt << "\n";

    }


}
