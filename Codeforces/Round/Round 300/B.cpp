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

vector < ll > vec, ans;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("in.txt", "r", stdin);

    vec.clear();

    for(i = 1; i <= 130; i++)
    {
        input = 0;

        for(j = 10; j >= 0; j--)
        {
            input *= 10;
            if(check(i,j)) input += 1;
        }

        vec.push_back(input);
    }

    while(cin >> n)
    {
//        cout << "NUMBER: " << n << endl;
        ans.clear();
        ll sz = vec.size();
        sz--;

        ll st, mn = mxlld;

        for(i = 0; i < vec.size(); i++)
        {
            flag = n;
            ll cnt = 0;

            j = i;
            while(flag >= 1)
            {
                while(flag >= vec[j])
                {
                    cnt++;
                    flag -= vec[j];
                }
                j--;
            }

            cout << vec[i] << " " << cnt << endl;

            if(cnt < mn)
            {
                mn = cnt;
                st = i;
            }
        }

        sz = st;
        while(n >= 1)
        {
            while(n >= vec[sz])
            {
                n -= vec[sz];
                ans.push_back(vec[sz]);
            }
            sz--;
        }

        sort(ans.begin(),ans.end());
        cout << ans.size() << endl;

        for(i = 0; i < ans.size(); i++) cout << ans[i] << " ";

        cout << endl;
    }

}


