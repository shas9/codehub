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
#define mx 100005
using namespace std;

ll arr[mx];
ll tree[mx*4];
vector < ll > divv[mx];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = __gcd(tree[left], tree[right]);
}


ll gcd(ll node, ll b, ll e, ll i, ll j)
{
//    bug;
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
//        cout << tree[node] << " && " << endl;
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

//    cout << b << " && " << mid << endl;
    ll p1 = gcd(left, b, mid, i, j);
    ll p2 = gcd(right, mid + 1, e,i, j);

    return __gcd(p1,p2);


}

ll bsf(ll x, ll lim)
{
    ll lo = 0;
    ll hi = divv[x].size() - 1;
    ll ans = 0;

    if(divv[x].size() == 0) return 0;

//    for(int i = 0; i < hi; i++) cout << divv[x][i] << " ";
//    cout << endl;

    while(lo <= hi)
    {
//        bug;
        ll mid = (lo + hi) / 2;

//        cout << lo << " & " << hi << " & " << mid << endl;
        if(divv[x][mid] <= lim)
        {
            lo = mid + 1;
            ans = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }

    }

    return ans;


}

int main()
{
    ll i, j, k, l, m, n, o, q, r;
    ll testcase;
    ll input, flag, tag, ans;
    flag = 0;

//     freopen("in.txt", "r", stdin);

//    slld(testcase);
//    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(q);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

//            cout << arr[i] << " ";

            flag = max(flag,arr[i]);

            ll sqq = int(sqrt(arr[i]));

            for(j = 1; j <= sqq; j++)
            {
               if(arr[i] % j == 0)
               {
                   divv[j].push_back(i);
                   ll num2 = arr[i]/j;

                   if(j != num2) divv[num2].push_back(i);
               }
            }
        }

//        cout << endl;

        init(1,1,n);

        for(i = 1; i <= flag; i++)
        {
            if(divv[i].size()) sort(divv[i].begin(),divv[i].end());
        }

        for(i = 1; i <= q; i++)
        {

            slld(l);
            slld(r);
            slld(input);

//            cout << l << " -- " << r << " " << input << endl;
            ll gc = gcd(1,1,n,l,r);

//            cout << gc << endl;

            if(gc == input) cout << 0 << endl;
            else
            {
                ll _r = 0;
                ll _l = 0;

                if(input <= flag)
                {
                    _r = bsf(input, r);
                    if(l > 1)_l = bsf(input, l - 1);
                }

//                cout << _r << endl;
                ll cnt = _r - _l;

                cout << (r - l + 1) - cnt << endl;

            }
        }


    }


}




