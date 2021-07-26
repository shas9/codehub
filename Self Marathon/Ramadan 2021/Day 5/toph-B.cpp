 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

vector < vector < ll > > conf[42];
ll n;

void gen()
{
    for(ll i = 0; i <= n * 4; i++) conf[i].clear();

    for(ll i = 0; i <= n; i++)
    {
        for(ll j = 0; j <= n; j++)
        {
            for(ll k = 0; k <= n; k++)
            {
                for(ll m = 0; m <= n; m++)
                {
                    ll sum = i + j + k + m;

                    conf[sum].push_back({});
                    conf[sum].back().push_back(i);
                    conf[sum].back().push_back(j);
                    conf[sum].back().push_back(k);
                    conf[sum].back().push_back(m);
                }
            }
        }
    }

    return;
}

ll solve()
{
    ll ret = 0;

    for(ll i = 0; i <= n * 4; i++)
    {
        for(vector < ll > &it: conf[i])
        {
            for(vector < ll > &jt: conf[i])
            {
                ll upor_nich = 0, bam_dan = 0;

                for(ll j = 0; j <= n; j++)
                {
                    ll b = i - (it[0] + jt[0] + j);
                    ll c = i - (it[2] + jt[1] + b);
                    ll d1 = i - (it[3] + jt[3] + c);
                    ll d2 = i - (it[1] + jt[2] + j);

                    if(0 <= b && b <= n)
                    {
                        if(0 <= c && c <= n)
                        {
                            if(0 <= d1 && d1 <= n)
                            {
                                if(d1 == d2) upor_nich++;
                            }
                        }
                    }
                }

                for(ll j = 0; j <= n; j++)
                {
                    ll b = i - (it[1] + jt[1] + j);
                    ll c = i - (it[3] + jt[0] + b);
                    ll d1 = i - (it[2] + jt[2] + c);
                    ll d2 = i - (it[0] + jt[3] + j);

                    if(0 <= b && b <= n)
                    {
                        if(0 <= c && c <= n)
                        {
                            if(0 <= d1 && d1 <= n)
                            {
                                if(d1 == d2) bam_dan++;
                            }
                        }
                    }
                }

                ret = (ret + (upor_nich * bam_dan));
            }
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        gen();
        ans = solve();

        cout << ans << "\n";
    }


}

