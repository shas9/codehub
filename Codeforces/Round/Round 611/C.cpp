#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long

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

ll arr[200005];
deque < ll > dq;
bool vis[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        dq.clear();
        memset(vis,0,sizeof vis);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            vis[arr[i]] = 1;
        }

        for(i = 1; i <= n; i++)
        {
            if(vis[i]) continue;

            dq.push_back(i);
        }

        for(i = 1; i <= n; i++)
        {
            if(vis[i] == 0 && arr[i] == 0)
            {
                j = 0;
                while(dq[j] == i) j++;

                arr[i] = dq[j];
                vis[dq[j]] = 1;
                dq.erase(dq.begin() + j);
            }
        }

        for(i = 1; i <= n; i++)
        {
            if(arr[i]) continue;

            arr[i] = dq[0];
            dq.pop_front();
        }

        for(i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

}




