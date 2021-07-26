/*

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/

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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(l);
        slld(r);

        ll pos = 0;
        i = 1;

        while(1)
        {
            if(pos + ((n - i) * 2) <= l) pos += ((n - i) * 2);
            else break;

//            cout << pos << endl;

            i++;

            if(i == n) break;
        }

        ll diff = l - pos;

        ll hand = 1;

        hand = diff / 2;

        if(diff % 2) hand++;

        hand += i;

        if(diff == 0) hand = n, i--;

        if(i == n) i = 1;

        if(diff % 2) j = i;
        else j = hand;

//        cout << hand << " " << i << endl;

        for(k = l; k <= r; k++)
        {
            printf("%lld ", j);

            if(j == hand)
            {
                hand++;
                if(hand > n)
                {
                    i++;
                    hand = i + 1;
                }

                if(i == n) i = 1;

                j = i;
            }
            else
            {
                if(i == n) hand = 1;
                j = hand;
            }
        }

        printf("\n");


    }


}

