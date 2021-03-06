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

string str[5000];

map < string, bool > mp;

vector < ll > ans;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(i = 1;  i <= n; i++)
    {
        cin >> str[i];

        mp[str[i]] = 1;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(str[j].size() >= str[i].size()) continue;

            string tmp = "";

            for(k = 0; k < str[i].size(); k++)
            {
                if(k < str[j].size())
                {
                    if(str[i][k] != str[j][k]) break;
                }
                else
                {
                    tmp += str[i][k];
                }
            }

            if(tmp.size() == 0) continue;
            else if(mp.find(tmp) != mp.end())
            {
                ans.push_back(i);
                break;
            }
        }
    }

    for(i = 0; i < ans.size(); i++)
    {
        if(i) cout << " ";

        cout << str[ans[i]];
    }

    if(ans.size() == 0)
    {
        cout << "No solution" << endl;
    }

    cout << endl;


}


