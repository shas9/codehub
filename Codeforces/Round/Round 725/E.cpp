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

struct var
{
    string beg = "";
    string en = "";

    bool same = 0;

    ll bcnt = 0;
    ll ecnt = 0;

    ll cnt = 0;
} v[60];

map < string, ll > mp;

void process(ll a)
{
    ll sz = v[a].beg.size();
    ll streak = v[a].bcnt;

    while(sz > 2)
    {
        if(v[a].beg[sz - 1] == 'a' && v[a].beg[sz - 2] == 'h')
        {
            streak++;

            v[a].beg.pop_back();
            v[a].beg.pop_back();
            sz -= 2;
        }
        else
        {
            if(streak) v[a].cnt = (streak - 1);
            streak = 0;
            v[a].bcnt = 0;

            v[a].beg.pop_back();
            sz -= 1;
        }
    }

    v[a].bcnt += streak;

    if(v[a].same)
    {
        v[a].en = v[a].beg;
        v[a].ecnt = v[a].bcnt;
    }
    else
    {
                                                                                 1
    }


}

void add(ll a, ll b)
{

}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;[

    .ku  /]

    for(ll cs = 1; cs <= testcase; cs++)
    {
        mp.clear();
        ll cnt = 0;

.        cin >> n;

        ll last = -1;

        for(ll i = 1; i <= n; i++)
        {
            string s;
            cin >> s;

            ll a;

            if(mp.find(s) == mp.end()) mp[s] = ++cnt;

            a = mp[s];

            last = a;

            cin >> s;

            if(s.size() == 2)
            {
                cin >> v[a].beg;
                v[a].en = v[a].beg;
                v[a].same = 1;
                process(a);
            }
            else
            {
                ll b, c;
                cin >> s;
                b = mp[s];
                cin >> s;
                cin >> s;
                c = mp[s];

                add(b,c);
            }
        }

        ans = v[last].cnt;

        cout << ans - 1 << "\n";
    }


}

