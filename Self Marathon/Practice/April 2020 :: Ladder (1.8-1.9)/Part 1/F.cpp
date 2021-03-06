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

vector < ll > vec;
ll dp[1001][10][10];
string mask;
ll m;

bool solve(ll pos, ll diff, ll last)
{
    if(pos > m)
    {
//        bug;
        return 1;
    }

    bool ret = 0;
    for(ll i = 0; i < mask.size(); i++)
    {
        if(i + 1 == last) continue;
        if(mask[i] == '0') continue;

        ll num = i + 1;

        if(num <= diff) continue;

       ret |= solve(pos + 1, num - diff, i + 1);

       if(ret)
       {
           vec.push_back(i + 1);

           return 1;
       }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> mask >> m)
    {
        vec.clear();

        if(solve(1,0,0) == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for(i = m - 1; i >= 0; i--)
            {
                cout << vec[i] << " ";
            }

            cout << endl;
        }
    }


}


