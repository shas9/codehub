#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define ll long long

#define mx 200005
using namespace std;

ll tree[mx], last[mx];

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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    ll r;

//    ll prev = 0;
    for(i = 1; i <= n; i++)
    {
        slld(l);
        slld(r);

        flag = query(r);
        ll flag2 = query(l);

//        cout << flag << " " <<  flag2 << endl;

        ans = flag + flag2;

        ans -= (last[l] + last[r]);

//        ans -= prev;
        update(l + 1, 1, 100000);
        update(r, -1, 100000);

        last[l] = flag2;
        last[r] = flag;

//        prev = ans;

        plld(ans);
    }


}


