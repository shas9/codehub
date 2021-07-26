// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

deque < char > dq;
string str;

vector < ll > g[100000];
ll idx;
bool vis[100000];
map < pair < ll, string >, ll > mp;

void ins(ll now)
{
    string s = "";

    while(!dq.empty() && dq.front() != 92)
    {
        s.pb(dq.front());
        dq.pop_front();
    }
    if(!dq.empty())dq.pop_front();

    ll nxt = -1;

    if(mp.find({now,s}) == mp.end())
    {
        mp[{now,s}] = ++idx;
		nxt = mp[{now,s}];
		g[now].pb(nxt);
    }

    nxt = mp[{now,s}];


    if(!dq.empty()) ins(nxt);
}

ll getfolder(ll node)
{
//	cout << node << " ~ ";
    ll ret = 0;

    for(auto it: g[node])
    {
        ret += getfolder(it);
    }

    ret += (g[node].empty() == 0);

    return ret;
}

ll getfile(ll node)
{
    ll ret = 0;

    for(auto it: g[node])
    {
        ret += getfile(it);
    }

    ret += (g[node].empty() == 1);

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    idx = 5;

    while(cin >> str)
    {
        dq.clear();

        for(auto it: str) dq.push_back(it);

        ll root = dq.front() - 'B';

        while(!dq.empty() && dq.front() != 92)
        {
            dq.pop_front();
        }
        if(dq.empty() == 0) dq.pop_front();

        ins(root);

//        pll ans = {0,0};
//
//        cout << endl;
//        for(ll i = 1; i <= 5; i++)
//        {
//            for(auto it: g[i])
//            {
//                ans.first = max(ans.first, getfolder(it));
//                ans.second = max(ans.second, getfile(it));
//            }
//        }
//
//        cout << endl << ans.first - 1 << " " << ans.second << '\n';
    }

    pll ans = {0,0};

    for(ll i = 1; i <= 5; i++)
    {
        for(auto it: g[i])
        {
            ans.first = max(ans.first, getfolder(it));
            ans.second = max(ans.second, getfile(it));
        }
    }

    cout << ans.first - 1 << " " << ans.second << '\n';


}

