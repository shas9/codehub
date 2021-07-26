#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf(" %c", &letter)
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
ll vec[mx];

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

ll sum(ll node, ll b, ll e)
{

    if(b == e)
    {
        return b;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    if(tree[right]) return sum(right, mid + 1, e);
    else return sum(left, b, mid);


}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);

        slld(n);

        ll last = 0;

        printcase(cs);
        for(i = 1; i <= n; i++)
        {
            char c;

            sc(c);

            if(c == 'Q')
            {
                if(last == 0)
                {
                    printf("Empty\n");
                }
                else
                {
                    ans = sum(1,1,100000);
                    printf("%lld\n", ans);
                }
            }
            else if(c == 'R')
            {
                if(last > 0)
                {
                    input = vec[last];
                    arr[input]--;

                    if(arr[input] == 0) update(1,1,100000,input,0);

                    last--;
                }
            }
            else
            {
                slld(input);

                last++;

                vec[last] = input;

                arr[input]++;

                if(arr[input] == 1) update(1,1,100000,input,1);
            }

//            for(j = 1; j <= last; j++) cout << vec[j] << " ";
//
//            cout << endl;
        }

    }


}



