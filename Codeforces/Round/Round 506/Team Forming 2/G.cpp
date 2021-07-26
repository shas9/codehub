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

#define maxn 300000
using namespace std;

pair < ll , ll > result[maxn];

char s[maxn];

vector < ll > cnt[40];

char xx[30];

void yes()
{
    printf("YES\n");
}

void no()
{
    printf("NO\n");
}

ll bs(ll id, ll last)
{

    if(cnt[id].size() == 0) return -1;

    ll low = 0;
    ll high = cnt[id].size() - 1;
    ll ans = cnt[id].size();

    while(low <= high)
    {
        ll mid = (low + high) / 2;

        if(cnt[id][mid] > last)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(ans == cnt[id].size()) return -1;

    return cnt[id][ans] ;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);

    scanf("%s", s+1);

    for(i = 0; i < 30; i++) cnt[i].clear();

    ll sz = strlen(s + 1);
    for(i = 1; i <= sz; i++)
    {
        ll id = s[i] - 'a';
        cnt[id].push_back(i);
    }

    ll last = 0;

    slld(q);

    ll curr = 0;

    result[0] = make_pair(1,0);

    for(i = 1; i <= q; i++)
    {
        scanf("%s", xx);
        ll len = strlen(xx);

        if(len == 3)
        {
            curr--;

            if(result[curr].first == 1)
            {
                yes();
            }
            else
            {
                no();
            }

            last = result[curr].second;
        }
        else
        {
            char c;
            scanf(" %c", &c);

            ll res = 0;

            if(result[curr].first == 0)
            {
                res = 0;
                last = sz;
            }
            else
            {
                ll id = c - 'a';

                ans = bs(id,last);

                if(ans == -1)
                {
                    res = 0;
                    last = sz;
                }
                else
                {
                    res = 1;
                    last = ans;
                }
            }

            curr++;
            result[curr] = make_pair(res,last);

            if(res == 1) yes();
            else no();
        }
    }




}



