// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

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

const ll MAX_N = 2e5+10, mod = 20009377, base1 = 20002261, base2 = 20002553;
char str[MAX_N];  // 1-indexed
//ll pw1[MAX_N];
ll pw2[MAX_N];
//ll mpw1[MAX_N];
ll mpw2[MAX_N];

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*1LL*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*1LL*x) % p;
    }
    return res;
}

void precalc()
{
//    pw1[0] = 1;
    pw2[0] = 1;
    for(int i = 1; i < MAX_N; i++)
    {
//        pw1[i] = (pw1[i-1] *1LL* base1) % mod;
        pw2[i] = (pw2[i-1] *1LL* base2) % mod;
    }

//    mpw1[MAX_N - 1] = power(pw1[MAX_N - 1], mod - 2, mod);
    mpw2[MAX_N - 1] = power(pw2[MAX_N - 1], mod - 2, mod);

    for(ll i = MAX_N - 2; i >= 0; i--)
    {
//        mpw1[i] = (mpw1[i + 1] *1LL* base1) % mod;
        mpw2[i] = (mpw2[i + 1] *1LL* base2) % mod;
    }
    return;
}

ll cnttt;

struct segtree
{

    ll n;
//    vector < ll > tree1;
    vector < ll > tree2;
    bool on;


    void init(ll _n, bool _on)
    {
        n = _n;
        on = _on;
//        tree1.assign(4 * n,0);
        tree2.assign(4 * n,0);
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {

        ++cnttt;

        assert(cnttt <= 600000000);

        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            if(on)
            {
//                tree1[node] = (val * 1LL * pw1[n - b + 1]) % mod;
                tree2[node] = (val * 1LL * pw2[n - b + 1]) % mod;
            }
            else
            {
//                tree1[node] = (val * 1LL * pw1[b]) % mod;
                tree2[node] = (val * 1LL * pw2[b]) % mod;
            }
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        if(b <= i && i <= mid) treeupdate(left, b, mid, i, val);
        if(mid + 1 <= i && i <= e) treeupdate(right, mid + 1, e, i, val);

//        tree1[node] = (tree1[left] + tree1[right]);
//        if(tree1[node] >= mod) tree1[node] -= mod;

        tree2[node] = (tree2[left] + tree2[right]);
        if(tree2[node] >= mod) tree2[node] -= mod;
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

//    ll treequery1(ll node, ll b, ll e, ll i, ll j)
//    {
//        if(i > e || j < b)
//        {
//            return 0;
//        }
//
//        if(b >= i && e <= j)
//        {
//            return tree1[node];
//        }
//
//        ll left = node * 2;
//        ll right = (node * 2) + 1;
//        ll mid = (b + e) / 2;
//
//        ll p1 = treequery1(left, b, mid, i, j);
//        ll p2 = treequery1(right, mid + 1, e,i, j);
//
//        ll ret = (p1 + p2);
//        if(ret >= mod) ret -= mod;
//        return ret;
//    }

    ll treequery2(ll node, ll b, ll e, ll i, ll j)
    {

        ++cnttt;

        assert(cnttt <= 600000000);

        if(i > e || j < b)
        {
            return 0;
        }

        if(b >= i && e <= j)
        {
            return tree2[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        ll p1 = 0;

        if(!(b > j || mid < i)) p1 = treequery2(left, b, mid, i, j);

        ll p2 = 0;

        if(!(mid + 1 > j || e < i)) p2 = treequery2(right, mid + 1, e,i, j);

        ll ret = (p1 + p2);
        if(ret >= mod) ret -= mod;
        return ret;
    }

    ll query(ll x, ll y)
    {
        if(x > y) return 0;

//        ll h1 = treequery1(1,1,n,x,y);
        ll h2 = treequery2(1,1,n,x,y);

        if(on)
        {
//            h1 = (h1 * 1LL * mpw1[n - y]) % mod;
            h2 = (h2 * 1LL * mpw2[n - y]) % mod;
        }
        else
        {
//            h1 = (h1 * 1LL * mpw1[x - 1]) % mod;
            h2 = (h2 * 1LL * mpw2[x - 1]) % mod;
        }



//        return ((long long)h1 << 32) | h2;

        return h2;
    }
};

segtree seg1, seg2;

ll solve1(ll l, ll r)
{
//    cout << seg1.query(l,r) << " " << seg2.query(l,r) << "\n";

    if(seg1.query(l,r) == seg2.query(l,r)) return 0;

    ll lo = l;
    ll hi = (r + l) / 2;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll fhash = seg1.query(l, mid - 1);
        ll rhash = seg2.query(r - (mid - l) + 1, r);

//        cout << mid << " == " << fhash << " " << rhash << "\n";

        if(fhash == rhash)
        {
            ll ffhash = seg1.query(mid + 1, (r - (mid - l)));
            ll rrhash = seg2.query(mid + 1, (r - (mid - l)));

//            cout << "Entered: " << ffhash << " " << rrhash << "\n";

            if(ffhash == rrhash)
            {
                ret = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            hi = mid - 1;
        }
    }

//    ll fhash = seg1.query(ret + 1, (r - (ret - l)));
//    ll rhash = seg2.query(ret + 1, (r - (ret - l)));
//
////    cout << ret << " " << fhash << " " << rhash << " ++ " << ret + 1 << " " << (r - (ret - l)) << "\n";
//
//    if(fhash == rhash) return ret;

    return ret;
}

ll solve2(ll l, ll r)
{
    ll lo = ((r + l) / 2) + 1;
    ll hi = r;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll fhash = seg1.query(mid + 1, r);
        ll rhash = seg2.query(l, l + (r - mid) - 1);

        if(fhash == rhash)
        {
            ll ffhash = seg1.query(l + (r - mid), mid - 1);
            ll rrhash = seg2.query(l + (r - mid), mid - 1);

            if(ffhash == rrhash)
            {
                ret = mid;
            }

            hi = mid - 1;

        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out2.txt", "w", stdout);

    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cnttt = 0;
    precalc();
    slld(testcase);

    ll ccnt = 0;
    ll ccnt1 = 0;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        scanf("%s", str + 1);

        ll n = strlen(str + 1);

        ccnt += n;

        assert(ccnt <= 2e5);

//        cout << n << "\n";

        seg1.init(n,0);
        seg2.init(n,1); // Reverse

        for(ll i = 1; i <= n; i++)
        {
            seg1.update(i,str[i] - 'a' + 1);
            seg2.update(i,str[i] - 'a' + 1);
        }

        scanf("%d", &q);

        ccnt1 += q;
        assert(ccnt1 <= 2e5);

        printf("Case %d:\n", cs);

        for(ll i = 1; i <= q; i++)
        {
            ll t;

            slld(t);

            if(t == 2)
            {
                ll x;
                char c;

                slld(x);
                scanf(" %c", &c);

                seg1.update(x,c - 'a' + 1);
                seg2.update(x,c - 'a' + 1);
            }
            else
            {
                slld(l);
                slld(r);

                ans = solve1(l,r);

                if(ans != -1) printf("%d\n", ans);
                else
                {
                    ans = solve2(l,r);
                    printf("%d\n", ans);
                }
            }
        }
    }


}


