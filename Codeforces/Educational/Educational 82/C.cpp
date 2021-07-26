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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    string s, t;

    vector < ll > vec[30];

    for(ll cs = 1; cs <= testcase; cs++)
    {
        for(i = 0; i < 29; i++) vec[i].clear();

        cin >> s;
//        cout << s << endl;

        for(i = 0; i < s.size(); i++)
        {
            if(i)
            {
                bool ok = 1;
                for(j = 0; j < vec[s[i] - 'a'].size(); j++)
                {
                    if(vec[s[i] - 'a'][j] == (s[i - 1] - 'a')) ok = 0;
                }

                if(ok) vec[s[i] - 'a'].pb(s[i - 1] - 'a');
            }

            if(i < s.size() - 1)
            {
                bool ok = 1;
                for(j = 0; j < vec[s[i] - 'a'].size(); j++)
                {
                    if(vec[s[i] - 'a'][j] == (s[i + 1] - 'a')) ok = 0;
                }

                if(ok) vec[s[i] - 'a'].pb(s[i + 1] - 'a');
            }

        }

        t = "";

        bool vis[30];
        memset(vis,0,sizeof vis);

        bool con = 0, one = 0;
        for(i = 0; i < 27; i++)
        {
            if(vec[i].size() > 2)
            {
                con = 1;
                break;
            }

            if(vec[i].size() == 1) one = 1;
        }

        if(one == 0 || con)
        {
            cout << "NO" << endl;
            continue;
        }

        for(i = 0; i < 27; i++)
        {
            if(vec[i].size() == 1)
            {
                while(1)
                {
                    t += i + 'a';
                    vis[i] = 1;

//                    cout << i << endl;
//                    for(j = 0; j < vec[i].size(); j++)
//                    {
//                        cout << vec[i][j]<< " ";
//                    }
//                    cout << endl;

                    if(vis[vec[i][0]])
                    {
                        if(vec[i].size() == 1) break;

                        i = vec[i][1];
                    }
                    else
                    {
                        i = vec[i][0];
                    }
                }


                break;
            }
        }

        for(i = 0; i < 26; i++)
        {
            if(!vis[i]) t += i + 'a';
        }

        cout << "YES" << endl << t << endl;
    }


}



