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
ll tree[mx*3];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = 1;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];


}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] + tree[right];
}

ll sum(ll node, ll b, ll e, ll val)
{
    //cout << node << " " << b << " " << e << " " << val << " " <<tree[node] << endl;

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    if(b == e)
    {
        return e;
    }

    if(tree[left] >= val)
    {
        return sum(left,b,mid,val);
    }
    else
    {
        return sum(right,mid + 1,e,val - tree[left]);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    while(1)
    {
        init(1,1,100000);
        i = 0;
        j = 0;
        while(1)
        {
            if(scanf("%lld", &n) == EOF) return 0;
            if(n == 0) break;
            if(n == -1)
            {
                ll med = i - j;

                if(med % 2)
                {
                    med /= 2;
                    med++;
                }
                else
                {
                    med /= 2;
                }

                //cout << i - j << " : " << med << endl;

                //cout << med << endl;

                ll ind = sum(1,1,100000,med);

                //cout << ind << endl;

                plld(arr[ind]);

                update(1,1,100000,ind,0);
                j++;


            }
            else arr[++i] = n;
        }

        printf("\n");


    }

}




