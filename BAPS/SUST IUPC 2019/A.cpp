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

string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    cin.ignore();
    for(ll cs = 1; cs <= testcase; cs++)
    {
        bool cse = 0, eee = 0, swe = 0, other = 0;

        getline(cin,str);

//        cout << str << endl;
        ll sz = str.size();
        i = 0;

        if(str[i] == 'C' && str[i + 1] == 'S' && str[i + 2] == 'E' && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) cse = 1;

        else if(str[i] == 'E' && str[i + 1] == 'E' && str[i + 2] == 'E' && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) eee = 1;

        else if(str[i] == 'S' && str[i + 1] == 'W' && str[i + 2] == 'E' && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) swe = 1;

        else if(isupper(str[i]) && isupper(str[i + 1]) && isupper(str[i + 1]) && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) other = 1;

        for(i = 1; i < sz - 3; i++)
        {
            if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && str[i] == 'C' && str[i + 1] == 'S' && str[i + 2] == 'E' && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) cse = 1;

            else if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && str[i] == 'E' && str[i + 1] == 'E' && str[i + 2] == 'E' && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) eee = 1;

            else if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && str[i] == 'S' && str[i + 1] == 'W' && str[i + 2] == 'E' && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) swe = 1;

            else if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && isupper(str[i]) && isupper(str[i + 1]) && isupper(str[i + 1]) && (str[i + 3] == '.' || str[i + 3] == ' ' || str[i + 3] == ',')) other = 1;
        }

        i = sz - 3;
        if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && str[i] == 'C' && str[i + 1] == 'S' && str[i + 2] == 'E' ) cse = 1;

        else if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && str[i] == 'E' && str[i + 1] == 'E' && str[i + 2] == 'E') eee = 1;

        else if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && str[i] == 'S' && str[i + 1] == 'W' && str[i + 2] == 'E') swe = 1;

        else if((str[i - 1] == '.' || str[i - 1] == ' ' || str[i - 1] == ',') && isupper(str[i]) && isupper(str[i + 1]) && isupper(str[i + 1])) other = 1;

        cout << "Case " << cs << ": ";

        if(cse && eee && swe) cout << "SUST Tech Fest" << endl;
        else if(cse && !eee && !swe && !other) cout << "SUST CSE Carnival" << endl;
        else cout << "Festival of SUST" << endl;

    }

}


