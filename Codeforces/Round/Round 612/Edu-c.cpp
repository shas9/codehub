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

ll arr[100005];

string str;
stack < ll > q;
int main()
{
    ll i, j, k, l, m, n, o, r;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
        ll len = str.size();

        arr[len] = mxlld;

        for(i = len - 1; i >= 0; i--)
        {
            arr[i] = str[i] - 'a';

            arr[i] = min(arr[i],arr[i + 1]);
        }

        while(!q.empty()) q.pop();

        ll ind = 0;

        string ansstr = "";

        while(ind < len)
        {
            while(!q.empty())
            {
                ll top = q.top();

                if(top > arr[ind]) break;

                ansstr += top + 'a';

                q.pop();
            }
            ll xx = str[ind] - 'a';

            if(arr[ind] == xx)
            {
                ansstr += str[ind];
            }
            else
            {
                q.push(xx);
            }

            ind++;
        }

        while(!q.empty())
        {
            ll top = q.top();

            ansstr += top + 'a';

            q.pop();
        }

        cout << ansstr << endl;
    }


}

