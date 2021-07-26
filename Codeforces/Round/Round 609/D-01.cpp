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

vector < ll > booked[300005];
ll arr[300005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
            booked[i].clear();
        }

        ans = 0;

        for(i = 1; i <= n; i++)
        {
            if(booked[i].size() == 0)
            {
                if(arr[i] % 2 == 0)
                {
                    ans += arr[i] / 2;
                }
                else
                {
                    ans += (arr[i] / 2) + 1;
                    booked[i + 1].push_back(1);
                }
            }
            else if(booked[i].size() == 1)
            {
                if((arr[i] - booked[i][0]) % 2 == 0) ans += (arr[i] - booked[i][0]) / 2;
                else
                {
                    ans += (arr[i] - booked[i][0]) / 2;

                    if(arr[i + 1] > booked[i][0])
                    {
                        ans++;
                        booked[i + 1].push_back(booked[i][0] + 1)
                    }
                }

                if(booked[i][0] > 1)
                {
                    if((booked[i][0] - 1) % 2 == 0) ans += (arr[i] - booked[i][0]) / 2;
                    else
                    {
                        ans += (arr[i] - booked[i][0]) / 2;

                        if(arr[i + 1] > booked[i][0])
                        {
                            ans++;
                            booked[i + 1].push_back(1)
                        }
                    }
                }
            }
            else
            {
                ans += ((arr[i] - booked[i][0]) / 2) + ((booked[i][0] - booked[i][1]) / 2) + ((booked[i][1] - 1)/2);

                if((arr[i] - booked[i][0]) % 2)
            }
        }
    }


}


