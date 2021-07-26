// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        string str;

        ll ptr1 = 0, ptr2 = 0;

        cin >> str;

        ans = 0;

        ll n = str.size();

        ll last = -1;
        ll pos = -1;

        while(ptr1 < n)
        {
            while(ptr2 < n)
            {
                bool on = 0;

                if(str[ptr2] != '?')
                {
                    if(last == -1)
                    {
                        last = str[ptr2] - '0';
                        pos = ptr2;
                    }
                    else
                    {
                        if(last != (str[ptr2] - '0'))
                        {
                            if((ptr2 - pos) % 2 == 0) on =
                        }
                    }
                }
            }
        }
    }


}

