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

vector < ll > a, b, c;

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
        a.clear();
        b.clear();
        c.clear();

        cin >> k >> n >> m;

        a.resize(n);
        b.resize(m);

        for(auto &it: a) cin >> it;
        for(auto &it: b) cin >> it;

        ll p1 = 0;
        ll p2 = 0;

        while(p1 < n || p2 < m)
        {
            if(p1 == n)
            {
                if(b[p2] == 0)
                {
                    c.push_back(0);
                    k++;
                    p2++;
                    continue;
                }

                if(b[p2] > k)
                {
                    c.clear();
                    c.push_back(-1);
                    break;
                }

                c.push_back(b[p2]);

                p2++;
            }
            else if(p2 == m)
            {
                if(a[p1] == 0)
                {
                    c.push_back(0);
                    k++;
                    p1++;
                    continue;
                }

                if(a[p1] > k)
                {
                    c.clear();
                    c.push_back(-1);
                    break;
                }

                c.push_back(a[p1]);

                p1++;
            }
            else
            {
                if(a[p1] < b[p2])
                {
                    if(a[p1] == 0)
                    {
                        c.push_back(0);
                        k++;
                        p1++;
                        continue;
                    }

                    if(a[p1] > k)
                    {
                        c.clear();
                        c.push_back(-1);
                        break;
                    }

                    c.push_back(a[p1]);

                    p1++;
                }
                else
                {
                    if(b[p2] == 0)
                    {
                        c.push_back(0);
                        k++;
                        p2++;
                        continue;
                    }

                    if(b[p2] > k)
                    {
                        c.clear();
                        c.push_back(-1);
                        break;
                    }

                    c.push_back(b[p2]);

                    p2++;
                }
            }
        }

        for(auto it: c) cout << it << " ";
        cout << "\n";
    }


}



