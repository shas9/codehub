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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        string str1, str2, str3;

        cin >> str1 >> str2;

        bool yes = 0;

        sort(str1.begin(),str1.end());
        for(i = 0; i < str2.size(); i++)
        {
            str3 = "";

            ll sz = str2.size();
            ll lim = i + str1.size();
            for(j = i; j < min(sz,lim); j++)
            {
                str3 += str2[j];
            }

//            cout << str3 << endl;

            sort(str3.begin(),str3.end());

            if(str3 == str1)
                yes = 1;
        }

        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}


