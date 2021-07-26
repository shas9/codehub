#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pair < long long, long long >

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

bool vis[200005];
bool vis2[200005];
ll arr[200005];
ll tarr[200005];
set < ll > st;

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
        }

        sort(arr + 1, arr + 1 + n);

        memset(vis,0,sizeof vis);
        memset(vis2,0,sizeof vis2);

        st.clear();

        for(i = 1; i <= n; i++)
        {
            vis[arr[i]] = 1;

            tarr[i] = arr[i];
        }

        for(i = 1; i <= n; i++)
        {
            if(vis2[tarr[i]]) continue;

            if(vis[tarr[i] - 1])
            {
                vis[tarr[i]] = 0;
                tarr[i] -= 1;
            }
            else if(vis[tarr[i] + 2] || vis[tarr[i] + 1])
            {
                vis[tarr[i]] = 0;
                vis[tarr[i] + 1] = 1;
                tarr[i] += 1;
            }

            vis2[tarr[i]] = 1;
        }

//        for(i = 1; i <= n; i++)
//        {
//            cout << tarr[i] << " ";
//        }
//
//        cout << endl;

        for(i = 1; i <= n; i++)
        {
//            cout << tarr[i] << " ";
            st.insert(tarr[i]);
        }

//        cout << endl;

        cout << st.size() << " ";

        memset(vis,0,sizeof vis);
        st.clear();

        for(i = 1; i <= n; i++)
        {
            tarr[i] = arr[i];
        }

        for(i = 1; i <= n; i++)
        {
            if(vis[tarr[i] - 1] == 0)
            {
                tarr[i]--;
            }
            else if(vis[tarr[i]] == 0);
            else tarr[i]++;

            vis[tarr[i]] = 1;
        }



        for(i = 1; i <= n; i++)
        {
//            cout << tarr[i] << " ";
            st.insert(tarr[i]);
        }

//        cout << endl;

        cout << st.size() << endl;
    }


}


