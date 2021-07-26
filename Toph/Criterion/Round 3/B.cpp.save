
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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009
#define mx 300005
using namespace std;

ll tree[mx];
vector < char > col[300005];
set < ll > st;

struct node{
    ll t, x;
    char c;
};

node qq[300005];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(qq[cs].t);

        slld(qq[cs].x);

        st.insert(qq[cs].x);

        if(qq[cs].t == 2)
        {
            getchar();
            sc(qq[cs].c);
        }
    }

    ll cnt = st.size();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        node pp = qq[cs];

        set < ll > :: iterator it = st.find(pp.x);


        pp.x = it - st.begin();

        if(pp.t == 1)
        {
            if(col[pp.x].size() == 0)
            {
                printf("0\n");
                continue;
            }

            sort(col[pp.x].begin(), col[pp.x].end());

            for(i = 0; i < col[pp.x].size(); i++)
            {
                printf("%c", col[pp.x][i]);
            }

            printf("\n");

            continue;
        }

        if(pp.t == 2)
        {

            for(i = 0; i < col[pp.x].size(); i++)
            {
                if(col[pp.x][i] == pp.c) break;
            }

            if(i == col[pp.x].size())
            {
                col[pp.x].push_back(pp.c);

                if(col[pp.x].size() == 1) update(pp.x,1,cnt);
            }

            continue;
        }

        if(pp.t == 3)
        {
            ll sum = query(pp.x);
            ll sum2 = query(cnt);

            if(sum == sum2)
            {
                printf("0\n");
            }
            else
            {
                ll lo = pp.x + 1;
                ll hi = cnt;
                ll pos = -1;

                sum += 1;

                while(lo <= hi)
                {
                    ll mid = (lo + hi) / 2;

                    ll zz = query(mid);

                    if(sum <= zz)
                    {
                        pos = mid;
                        hi = mid - 1;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }

                printf("%lld\n",mp2[pos]);
            }
        }

        if(pp.t == 4)
        {
            ll sum = 0;

            if(pp.x > 1)
                sum = query(pp.x - 1);

            if(sum == 0)
            {
                printf("0\n");
            }
            else
            {
                ll lo = 1;
                ll hi = pp.x - 1;
                ll pos = -1;


                while(lo <= hi)
                {
                    ll mid = (lo + hi) / 2;

                    ll zz = query(mid);

                    if(sum == zz)
                    {
                        pos = mid;
                        hi = mid - 1;
                    }
                    else if(sum < zz)
                    {
                        hi = mid - 1;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }

                printf("%lld\n",mp2[pos]);
            }
        }
    }



}



