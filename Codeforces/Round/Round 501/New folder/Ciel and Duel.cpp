#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

vector < ll > atk, def, cel;
ll dp[105][105];
ll n, m;
ll mapp[10000];
ll sza;

bool comp(ll a, ll b)
{
    return a > b;
}

ll solve(ll posc, ll posj)
{
    if(posj == atk.size()) return 0;
    if(posc == cel.size()) return 0;

    ll &res = dp[posc][posj];

    if(res != -1) return res;

    res = 0;
    res = max(solve(posc + 1, posj), solve(posc, posj + 1));

    if(cel[posc] >= atk[posj])
    {
        res = max(res, cel[posc] - atk[posj] + solve(posc + 1, posj + 1));
    }

    return res;

}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    string x;

    slld(n);
    slld(m);

    for(i = 0; i < n; i++)
    {
        cin >> x;
        slld(input);

        if(x[0] == 'A') atk.push_back(input);
        else def.push_back(input);
    }

    for(i = 0; i < m; i++)
    {
        slld(input);

        cel.push_back(input);

        mapp[input]++;
    }

    sort(atk.begin(),atk.end(), comp);
//    sort(def.begin(), def.end(), comp);
    sort(cel.begin(),cel.end(), comp);

    ll sz = def.size();
    ll flag1 = 1;
    for(i = 0; i < sz; i++)
    {
        flag = 0;
        for(j = def[i] + 1; j <= 8000; j++)
        {
            if(mapp[j])
            {
                flag = 1;
                mapp[j]--;
                break;
            }
        }

        if(flag == 0)
        {
            flag1 = 0;
            break;
        }
    }

    ll sum = 0;
    if(flag1)
    {
        for(i  = 0; i <= 8000; i++) sum += mapp[i] * i;

        sz = atk.size();

        for(i = 0; i < sz; i++)
        {
            sum -= atk[i];
            flag = 0;
            for(j = atk[i]; j <= 8000; j++)
            {
                if(mapp[j])
                {
                    mapp[j]--;
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                flag1 = 0;
                break;
            }
        }
    }

    if(flag1 == 0) sum = 0;

    memset(dp,-1,sizeof dp);

    ll sza = atk.size();

    sum = max(sum,solve(0,0));

    plld(sum);

}


