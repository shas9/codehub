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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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

bool vis[1004];

string str;

ll col[5];
ll arr[1004];

vector < ll > p1, p2, p3;

bool solve(ll n1, ll n2, ll n3)
{
        memset(col,0,sizeof col);

//        cout << n1 << " " << n2 << " " << n3 << endl;

        ll i;

        for(i = 0; i < str.size(); i++)
        {
            if(str[i]=='R')col[1]++, arr[i] = 1;
            if(str[i]=='G')col[2]++, arr[i] = 2;
            if(str[i]=='B')col[3]++, arr[i] = 3;
        }

        p1.clear();
        p2.clear();
        p3.clear();

        if(str.size() <= 2)
        {
            return 1;
        }

        for(i = 0; i < str.size(); i++)
        {
            if(arr[i] == n1)
            {
                p1.push_back(arr[i]);

            }
            else if(arr[i] == n2 && col[n1] == 0)
            {
                p1.push_back(arr[i]);
            }
            else if(arr[i] == n2)
            {
                p2.push_back(arr[i]);
            }
            else
            {
                p2.push_back(arr[i]);
            }

            col[arr[i]]--;
        }

        for(i = 0; i < p1.size(); i++)
        {
            p3.push_back(p1[i]);
        }

        for(i = 0; i < p2.size(); i++)
        {
            p3.push_back(p2[i]);
        }

        col[1] = col[2] = col[3] = 1;

        col[p3[0]] = 0;


        for(i = 1; i < p3.size(); i++)
        {
            if(p3[i] == p3[i - 1]) continue;

            if(col[p3[i]] == 0) return 0;

            col[p3[i]] = 0;
        }

        return 1;


}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
        for(i = 1; i <= 3; i++)
        {
            for(j = 1; j <= 3; j++)
            {
                for(k = 1; k <= 3; k++)
                {
                    if(i == j || j == k || i == k) continue;

                    if(solve(i,j,k))
                    {
                        cout << "YES" << endl;
                        break;
                    }
                }

                if(k <= 3) break;
            }

            if(j <= 3) break;
        }

        if(i <= 3) continue;

        cout << "NO" << endl;
    }


}


