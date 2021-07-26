 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

const ll maxn  = 200000;
vector < ll > primes;
ll primeidx[maxn + 10];
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.push_back(i);

    }

    for(ll i = 0; i < primes.size(); i++)
    {
        primeidx[primes[i]] = i;
    }

}



ll arr[200005];
ll sqsum[500];
pll sqblock[500][18000];
ll sqlazy[500];
ll n;

void process()
{
    ll sqsz = sqrt(n) + 3;

    for(ll i = 0; i < 500; i++)
    {
        for(ll j = 0; j < 18000; j++)
        {
            sqblock[i][j] = {mnlld, mxlld};
        }

        sqsum[i] = 0;
        sqlazy[i] = 1;
    }

    for(ll i = 1; i <= n; i++)
    {
        ll block = (i / sqsz);

        ll x = arr[i];

        sqsum[block] += x;

        for(auto it: primes)
        {
            if(it * it > x) break;

            ll cnt = 0;

            while(x  % it == 0)
            {
                cnt++;
                x /= it;
            }

            sqblock[block][primeidx[it]].first = max(sqblock[block][primeidx[it]].first, cnt);
            sqblock[block][primeidx[it]].second = min(sqblock[block][primeidx[it]].second, cnt);
        }

        if(x > 1)
        {
            sqblock[block][primeidx[x]].first = max(sqblock[block][primeidx[x]].first, 1LL);
            sqblock[block][primeidx[x]].second = min(sqblock[block][primeidx[x]].second, 1LL);
        }
    }

    for(ll i = 0; i < 500; i++)
    {
        for(ll j = 0; j < 18000; j++)
        {
            if(sqblock[i][j].first == mnlld) sqblock[i][j] = {0,0};
        }
    }

    return;

}

ll ask(ll l, ll r)
{
    ll sqsz = sqrt(n) + 3;

    ll sql = (l / sqsz);

    if(sqlazy[sql] != 1)
    {
        for(ll i = max(1LL, sql * sqsz); i < ((sql + 1) * sqsz); i++)
        {
            arr[i] /= sqlazy[sql];
        }

        sqlazy[sql] = 1;
    }

    ll sqr = (r / sqsz);

    if(sqlazy[sqr] != 1)
    {
        for(ll i = max(1LL, sqr * sqsz); i < ((sqr + 1) * sqsz); i++)
        {
            arr[i] /= sqlazy[sqr];
        }

        sqlazy[sqr] = 1;
    }

    ll ret = 0;

    if(sql == sqr)
    {
        for(ll i = l; i <= r; i++)
        {
            ret += arr[i];
        }

        return ret;
    }

    for(ll i = l; i < ((sql + 1) * sqsz); i++)
    {
        ret += arr[i];
    }

    for(ll i = (sqr * sqsz); i <= r; i++)
    {
        ret += arr[i];
    }

    for(ll i = sql + 1; i < sqr; i++)
    {
        ret += sqsum[i];
    }

    return ret;
}

ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x);

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x);
    }
    return res;
}

void update(ll l, ll r, ll gcd)
{
    ll sqsz = (sqrt(n) + 3);

    for(auto it: primes)
    {
        if(it * it > gcd) break;

        ll sql = l / sqsz;
        ll sqr = r / sqsz;
        ll idx = primeidx[it];
        ll cnt = 0;

        while(gcd % it == 0)
        {
            cnt++;
            gcd /= it;
        }

        if(cnt == 0) continue;

        for(ll i = sql + 1; i < sqr; i++)
        {
            ll biyog = min(cnt, sqblock[i][idx].second);
            sqblock[i][idx].first -= biyog;
            sqblock[i][idx].second -= biyog;

            sqlazy[i] *= power(it, biyog);
            sqsum[i] /= power(it,biyog);

            biyog = (cnt - biyog);

            if(sqblock[i][idx].first == 0) continue;

            if(biyog)
            {
                sqblock[i][idx].first = -1;

                for(ll j = max(1LL, (i * sqsz)); j < ((i + 1) * sqsz); j++)
                {
                    arr[j] /= sqlazy[i];
                }

                sqlazy[i] = 1;

                for(ll j = max(1LL, (i * sqsz)); j < ((i + 1) * sqsz); j++)
                {
                    ll poss = 0;
                    ll x = arr[j];

                    while(x % it == 0)
                    {
                        x /= it;
                        poss++;
                    }

                    ll vag = min(poss, biyog);

                    sqsum[i] -= arr[j];

                    arr[j] /= power(it,vag);

                    sqsum[i] += arr[j];

                    poss -= vag;

                    sqblock[i][idx].first = max(sqblock[i][idx].first, poss);
                }
            }
        }

        if(sqlazy[sql] != 1)
        {
            for(ll i = max(1LL, sql * sqsz); i < ((sql + 1) * sqsz) && i <= n; i++)
            {
                arr[i] /= sqlazy[sql];
            }

            sqlazy[sql] = 1;
        }

        if(sqlazy[sqr] != 1)
        {
            for(ll i = max(1LL, sqr * sqsz); i < ((sqr + 1) * sqsz) && i <= n; i++)
            {
                arr[i] /= sqlazy[sqr];
            }

            sqlazy[sqr] = 1;
        }

        sqblock[sql][idx] = {-100,100};

        for(ll i = max(1LL, sql * sqsz); i < (sql + 1) * sqsz && i <= n; i++)
        {
            ll x = arr[i];
            ll cnt1 = 0;
            sqsum[sql] -= arr[i];

            while(x % it == 0)
            {
                x /= it;
                cnt1++;
            }

            if(l <= i && i <= r)
            {
                ll vag = min(cnt1, cnt);
                cnt1 -= vag;

                arr[i] /= power(it, vag);
            }

            sqsum[sql] += arr[i];

            sqblock[sql][idx].first = max(sqblock[sql][idx].first, cnt1);
            sqblock[sql][idx].second = min(sqblock[sql][idx].second, cnt1);
        }

        if(sql == sqr) continue;

        sqblock[sqr][idx] = {-100,100};


        for(ll i = max(1LL, sqr * sqsz); i < (sqr + 1) * sqsz && i <= n; i++)
        {
            ll x = arr[i];
            ll cnt1 = 0;
            sqsum[sqr] -= arr[i];

            while(x % it == 0)
            {
                x /= it;
                cnt1++;
            }

            if(l <= i && i <= r)
            {
                ll vag = min(cnt1, cnt);
                cnt1 -= vag;

                arr[i] /= power(it, vag);
            }

            sqsum[sqr] += arr[i];

            sqblock[sqr][idx].first = max(sqblock[sqr][idx].first, cnt1);
            sqblock[sqr][idx].second = min(sqblock[sqr][idx].second, cnt1);
        }
    }

    ll it = gcd;

    if(it == 1) return;

        ll sql = l / sqsz;
        ll sqr = r / sqsz;
        ll idx = primeidx[it];
        ll cnt = 1;

        for(ll i = sql + 1; i < sqr; i++)
        {
            ll biyog = min(cnt, sqblock[i][idx].second);
            sqblock[i][idx].first -= biyog;
            sqblock[i][idx].second -= biyog;

            sqlazy[i] *= power(it, biyog);
            sqsum[i] /= power(it,biyog);

            biyog = (cnt - biyog);

            if(sqblock[i][idx].first == 0) continue;

            if(biyog)
            {
                sqblock[i][idx].first = -1;

                for(ll j = max(1LL, (i * sqsz)); j < ((i + 1) * sqsz) && j <= n; j++)
                {
                    arr[j] /= sqlazy[i];
                }

                sqlazy[i] = 1;

                for(ll j = max(1LL, (i * sqsz)); j < ((i + 1) * sqsz) && j <= n; j++)
                {
                    ll poss = 0;
                    ll x = arr[j];

                    while(x % it == 0)
                    {
                        x /= it;
                        poss++;
                    }

                    ll vag = min(poss, biyog);

                    sqsum[i] -= arr[j];

                    arr[j] /= power(it,vag);

                    sqsum[i] += arr[j];

                    poss -= vag;

                    sqblock[i][idx].first = max(sqblock[i][idx].first, poss);
                }
            }
        }



        if(sqlazy[sql] != 1)
        {
            for(ll i = max(1LL, sql * sqsz); i < ((sql + 1) * sqsz) && i <= n; i++)
            {
                arr[i] /= sqlazy[sql];
            }

            sqlazy[sql] = 1;
        }

        if(sqlazy[sqr] != 1)
        {
            for(ll i = max(1LL, sqr * sqsz); i < ((sqr + 1) * sqsz) && i <= n; i++)
            {
                arr[i] /= sqlazy[sqr];
            }

            sqlazy[sqr] = 1;
        }

        sqblock[sql][idx] = {-100,100};

        for(ll i = max(1LL, sql * sqsz); i < (sql + 1) * sqsz && i <= n; i++)
        {
            ll x = arr[i];
            ll cnt1 = 0;
            sqsum[sql] -= arr[i];

            while(x % it == 0)
            {
                x /= it;
                cnt1++;
            }

            if(l <= i && i <= r)
            {
                ll vag = min(cnt1, cnt);
                cnt1 -= vag;

                arr[i] /= power(it, vag);
            }

            sqsum[sql] += arr[i];

            sqblock[sql][idx].first = max(sqblock[sql][idx].first, cnt1);
            sqblock[sql][idx].second = min(sqblock[sql][idx].second, cnt1);
        }

        if(sql == sqr) return;

        sqblock[sqr][idx] = {-100,100};

        for(ll i = max(1LL, sqr * sqsz); i < (sqr + 1) * sqsz && i <= n; i++)
        {
            ll x = arr[i];
            ll cnt1 = 0;
            sqsum[sqr] -= arr[i];

            while(x % it == 0)
            {
                x /= it;
                cnt1++;
            }

            if(l <= i && i <= r)
            {
                ll vag = min(cnt1, cnt);
                cnt1 -= vag;

                arr[i] /= power(it, vag);
            }

            sqsum[sqr] += arr[i];

            sqblock[sqr][idx].first = max(sqblock[sqr][idx].first, cnt1);
            sqblock[sqr][idx].second = min(sqblock[sqr][idx].second, cnt1);
        }




    return;
}


int main()
{
    ll i, j, k, l, m, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();
    slld(n);
    slld(m);

    for(ll i = 1; i <= n; i++) slld(arr[i]);

    process();

    for(ll i = 1; i <= m; i++)
    {
        ll t;

        slld(t);
        slld(l);
        slld(r);

        if(t == 1)
        {
            ans = ask(l,r);
            printf("%lld\n", ans);
        }
        else
        {
            ll g;
            slld(g);
            update(l,r,g);
        }

//        bug(i);
    }



}


