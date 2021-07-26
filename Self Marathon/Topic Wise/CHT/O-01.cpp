// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

struct Line
{
    ll m;
    long long c;
};

struct nodes
{
    Line line;
    ll lft, rgt;
};

nodes trees[30000007];
ll nroot[1000006];
vector < ll > pnt[1000006];
ll idx;

struct DynamicLichao
{
    ll n;
    ll type;
    ll lft, rgt;
    ll nd;

    void init(ll _t, ll _nd, bool on = 1)
    {
        nd = _nd;

        if(on)
        {

            vector < ll > &v1 = pnt[nd];
            vector < ll > &v2 = pnt[nd * 2];
            vector < ll > &v3 = pnt[nd * 2 + 1];
            vector < ll > vec;
            vec.clear();

            ll id1 = 0, id2 = 0, id3 = 0;

            while(1)
            {
                if(id1 < v1.size() && id2 < v2.size() && id3 < v3.size())
                {
                    ll mn = min(v1[id1], min(v2[id2], v3[id3]));
                    vec.push_back(mn);

                    if(mn == v1[id1]) id1++;
                    if(mn == v2[id2]) id2++;
                    if(mn == v3[id3]) id3++;
                }
                else if(id1 < v1.size() && id2 < v2.size())
                {
                    ll mn = min(v2[id2], v1[id1]);
                    vec.push_back(mn);

                    if(mn == v1[id1]) id1++;
                    if(mn == v2[id2]) id2++;
                }
                else if(id2 < v2.size() && id3 < v3.size())
                {
                    ll mn = min(v2[id2], v3[id3]);
                    vec.push_back(mn);

                    if(mn == v2[id2]) id2++;
                    if(mn == v3[id3]) id3++;
                }
                else if(id1 < v1.size() && id3 < v3.size())
                {
                    ll mn = min(v1[id1], v3[id3]);
                    vec.push_back(mn);

                    if(mn == v1[id1]) id1++;
                    if(mn == v3[id3]) id3++;
                }
                else if(id1 < v1.size())
                {
                    if(id1 && v1[id1] != v1[id1 - 1]) vec.push_back(v1[id1]);
                    id1++;
                }
                else if(id2 < v2.size())
                {
                    if(id2 && v2[id2] != v2[id2 - 1]) vec.push_back(v2[id2]);
                    id2++;
                }
                else if(id3 < v3.size())
                {
                    if(id3 && v3[id3] != v3[id3 - 1]) vec.push_back(v3[id3]);
                    id3++;
                }
                else break;
            }

            pnt[nd] = vec;
        }
        else
        {
            sort(pnt[nd].begin(),pnt[nd].end());
            pnt[nd].erase(unique(pnt[nd].begin(),pnt[nd].end()), pnt[nd].end());
        }

        lft = 0;
        rgt = pnt[nd].size() - 1;

//        cout << nd << " " << rgt << " @@ " << endl;

        type = _t; // 1 = maximum, 0 = minimum
    }

    inline long long f(Line &line, ll &x)
    {
        return line.m*1LL*x + line.c;
    }

    void add(ll lo, ll hi, Line line, ll node)
    {
        if(lo > hi) return;
        if(lo == hi)
        {
            if(type & 1)
            {
                if(f(line, pnt[nd][lo]) > f(trees[node].line, pnt[nd][lo]))
                    trees[node].line = line;
            }
            else
            {
                if(f(line, pnt[nd][lo]) < f(trees[node].line, pnt[nd][lo]))
                    trees[node].line = line;
            }

            return;
        }

        ll mid = lo+hi >> 1;

        bool left, m;

        if(type & 1)
        {
            left = f(line, pnt[nd][lo]) > f(trees[node].line, pnt[nd][lo]);
            m = f(line, pnt[nd][mid]) > f(trees[node].line, pnt[nd][mid]);
        }
        else
        {
            left = f(line, pnt[nd][lo]) < f(trees[node].line, pnt[nd][lo]);
            m = f(line, pnt[nd][mid]) < f(trees[node].line, pnt[nd][mid]);
        }

        if(m) swap(line, trees[node].line);

        if(left != m)
        {
            if(trees[node].lft == -1)
            {
                trees[node].lft = ++idx;
                trees[idx] = {0,mxlld,-1,-1};
            }

            ll left = trees[node].lft;

            add(lo, mid, line, left);
        }
        else
        {
            if(trees[node].rgt == -1)
            {
                trees[node].rgt = ++idx;
                trees[idx] = {0,mxlld,-1,-1};
            }

            ll right = trees[node].rgt;

            add(mid+1, hi, line, right);
        }
    }

    void update(Line x, ll nowroot)
    {
        add(lft,rgt,x,nowroot);
    }

    long long query(ll lo, ll hi, ll pos, ll node)
    {
        if(lo > hi) return mxlld;
        if(lo == hi)
            return f(trees[node].line, pnt[nd][pos]);

        ll mid = (lo+hi) >> 1;
        long long ret = f(trees[node].line, pnt[nd][pos]);

        if(pos <= mid)
        {
            ll left = trees[node].lft;

            if(left == -1) return ret;

            if(type & 1)
            {
                return max(ret, query(lo, mid, pos, left));
            }
            else
            {
                return min(ret, query(lo, mid, pos, left));
            }
        }
        else
        {
            ll right = trees[node].rgt;

            if(right == -1) return ret;

            if(type & 1)
            {
                return max(ret, query(mid + 1, hi, pos, right));
            }
            else
            {
                return min(ret, query(mid + 1, hi, pos, right));
            }
        }
    }

    long long ask(ll x, ll nowroot)
    {
        x = lower_bound(pnt[nd].begin(),pnt[nd].end(), x) - pnt[nd].begin();
        return query(lft,rgt,x,nowroot);
    }
};

DynamicLichao tree[1000006];

void update(ll node, ll b, ll e, ll i, Line val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node].update(val, nroot[node]);

        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node].update(val, nroot[node]);
}

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        if(nroot[node] == -1)
        {
            tree[node].init(0,node,0);
            nroot[node] = ++idx;
            trees[idx] = {0,mxlld,-1,-1};
        }

        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    if(nroot[node] == -1)
    {
        tree[node].init(0,node);
        nroot[node] = ++idx;
        trees[idx] = {0,mxlld,-1,-1};
    }
}
void plot(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        pnt[node].push_back(x);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    plot(left, b, mid, i, j, x);
    plot(right, mid + 1, e,i, j, x);
    return;
}



long long sum(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if(nroot[node] == -1) return mxlld;

    if(i > e || j < b)
    {
        return mxlld;
    }

    if(b >= i && e <= j)
    {
//		cout << tree[node].rgt << endl;
        return tree[node].ask(x,nroot[node]);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    long long p1 = sum(left, b, mid, i, j, x);
    long long p2 = sum(right, mid + 1, e,i, j, x);

    return min(p1,p2);
}

vector < ll > vec;

struct pizza
{
    ll c, p;
} a1[200005];

struct customer
{
    ll c;
    vector < ll > vec;
} a2[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);
    slld(m);

    idx = 0;

    for(ll i = 1; i <= n; i++)
    {
        slld(a1[i].c);
        slld(a1[i].p);
    }

    for(ll i = 1; i <= m; i++)
    {
        slld(a2[i].c);

        slld(k);

        a2[i].vec.clear();

        while(k--)
        {
            slld(input);
            a2[i].vec.push_back(input);
        }

        sort(a2[i].vec.begin(), a2[i].vec.end());
    }

    for(ll i = 1; i <= m; i++)
    {
        ll prv = 1;

        a2[i].vec.push_back(n + 1);

        for(auto it: a2[i].vec)
        {
            if(prv < it)
            {
                plot(1,1,n,prv,it - 1, a2[i].c);
            }

            prv = it + 1;
        }
    }

    memset(nroot,-1,sizeof nroot);


    init(1,1,n);

    for(ll i = 1; i <= n; i++)
    {
        update(1,1,n,i, {-2*a1[i].c, a1[i].c * 1LL * a1[i].c + a1[i].p});
    }


    for(ll i = 1; i <= m; i++)
    {
        ll prv = 1;

        a2[i].vec.push_back(n + 1);

        long long mn = mxlld;

        for(auto it: a2[i].vec)
        {
            if(prv < it)
            {
                mn = min(mn, sum(1,1,n,prv,it - 1, a2[i].c));
            }

            prv = it + 1;
        }

        mn += (a2[i].c * 1LL * a2[i].c);
        printf("%lld\n", mn);
    }
}


/*

4 1
1000000000 1000000000
1 1000000000
500000000 1000000000
999999999 1000000000
1 3 2 3 4

*/




