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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

vector < string > arr;
string in;

bool comp(string a, string b)
{
    return a.size() < b.size();
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> in;

        arr.pb(in);
    }

    //bug;

    sort(arr.begin(),arr.end(),comp);

    bool on = 1;

    for(i = 1; i < arr.size(); i++)
    {
        string x = arr[i];
        string z = arr[i - 1];

        bool d = 0;
        for(j = 0; j < (x.size() - z.size() + 1); j++)
        {
            bool temp = 1;

//            cout << j << endl;
//            cout << x << " " << y << endl;
            for(k = j, l = 0; l < z.size(); l++, k++)
            {
                if(x[k] != z[l])
                {
                    temp = 0;
                    break;
                }

            }

            if(temp) d = 1;

//            cout << on << endl;
        }

        if(d == 0) on = 0;
    }

    if(on == 0) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;

        for(i = 0; i < arr.size(); i++) cout << arr[i] << endl;
    }

    return 0;




}


