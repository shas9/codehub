#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}



int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> k)
    {
        queue < ll > qq;

        for(i = 1; i <= 9; i++) qq.push(i);

//        k = j;
        while(k--)
        {
            ans = qq.front();
            qq.pop();

            ll x = ans % 10;

//            cout << ans << endl;
            if(qq.size() > k) continue;

            if(ans % 10 != 0)
            {
                qq.push((ans * 10) + x - 1);
//                cout << (ans * 10) + x - 1 << " ";
            }

            qq.push((ans * 10) + x);

//            cout << (ans * 10) + x << " ";

            if(ans % 10 != 9)
            {
                qq.push((ans * 10) + x + 1);
//                cout << (ans * 10) + x + 1;
            }

//            cout << endl;
        }

        cout << ans << endl;
    }


}


