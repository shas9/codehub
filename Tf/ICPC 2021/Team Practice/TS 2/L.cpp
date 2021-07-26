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

struct info
{
    ll first, second, id;
};

vector < info > w1, w2;

bool comp(info a, info b)
{
    double x = (a.second * 1.0) / a.first;
    double y = (b.second * 1.0) / b.first;

    return x > y;
}

bool comp2(info a, info b)
{
    return a.first > b.first;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        w1.clear();
        w2.clear();

        for(ll i = 0; i < n; i++)
        {
            ll u, v;

            cin >> u >> v;

            if(u > (m / 2)) w1.push_back({u,v, i + 1});
            else w2.push_back({u,v, i + 1});
        }

        sort(w1.begin(),w1.end(), comp2);
        sort(w2.begin(),w2.end(), comp);


//        for(auto it: w1) cout << it.first << " " << it.second << " " << it.id << "\n";
//        for(auto it: w2) cout << it.first << " " << it.second << " " << it.id << "\n";

        ans = 0;

        ll ptr1 = 0, ptr2 = 0;

        ll tw = 0, tc = 0;

        m += (m / 2);

//        cout << n << endl;

        pll pos = {-1,-1};

        for(auto it: w1)
        {
            if(ans < tc + it.second && tw + it.first <= m)
            {
                ans = tc + it.second;

                pos = {ptr1 - 1, ptr2};
            }

            while(ptr1 < w2.size())
            {
                if(tw + w2[ptr1].first + it.first <= m)
                {
                    tw += w2[ptr1].first;
                    tc += w2[ptr1].second;

                    if(ans < tc + it.second)
                    {
                        ans = tc + it.second;

                        pos = {ptr1, ptr2};
                    }
                }
                else break;

                ptr1++;
            }
            ptr2++;
        }

        while(ptr1 < w2.size())
        {
            if(tw + w2[ptr1].first <= m)
            {
                tw += w2[ptr1].first;
                tc += w2[ptr1].second;

                if(ans < tc)
                {
                    ans = tc;

                    pos = {ptr1, -1};
                }
            }
            else break;

            ptr1++;
        }

        ans = pos.first + 1;

        if(pos.second != -1) ans++;

        cout << ans << "\n";

        for(ll i = 0; i <= pos.first; i++)
        {
			cout << w2[i].id << " ";
        }

        if(pos.second != -1) cout << w1[pos.second].id << " ";

        cout << "\n";

//		cout << ans << "\n";
    }


}


