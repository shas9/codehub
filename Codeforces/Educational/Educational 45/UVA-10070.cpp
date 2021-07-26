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

char num[100005];
ll len;
bool five()
{
    if(num[len] == '5' || num[len] == '0') return 1;
    else return 0;
}

bool four()
{
    ll flag;

    flag = ((num[len - 1] - '0') * 10) + (num[len] - '0');

    //cout << flag << endl;

    if(flag % 4 == 0) return 1;
    else return 0;
}

bool three()
{
    ll flag = 0;

    for(ll i = 1; i <= len; i++)
        flag += num[i] - '0';

    if(flag % 3 == 0) return 1;
    else return 0;
}

bool hunder()
{
    if(num[len] == '0' && num[len - 1] == '0') return 1;
    else return 0;
}

bool eleven()
{
    ll flag = 0;

    for(ll i = 1; i <= len; i++)
    {
        if(i % 2 == 1) flag += num[i] - '0';
        else flag -= num[i] - '0';
    }

    if(flag % 11 == 0) return 1;
    else return 0;
}

bool fourhund()
{
    if(hunder() == 0) return 0;

    ll flag;

    flag = ((num[len - 3] - '0') * 10) + (num[len - 2] - '0');

    if(flag % 4 == 0) return 1;
    else return 0;
}

bool leap()
{
    if(fourhund() == 1) return 1;

    if(hunder()) return 0;


    if(four()) return 1;

    return 0;
}

bool Huluculu()
{
    if(three() && five()) return 1;
    else return 0;
}

bool Bulukulu()
{
    if(five() && eleven()) return 1;
    else return 0;
}



int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    tag = 1;

    while(scanf("%s", num + 1) != EOF)
    {
        len = strlen(num + 1);
        bool on = 1;

        if(tag == 0) cout << endl;

        tag = 0;

        if(leap())
        {
            cout << "This is leap year." << endl;


            on = 0;
        }

        if(Huluculu())
        {
            cout << "This is huluculu festival year." << endl;

            on = 0;
        }

        if(Bulukulu() && leap())
        {
            cout << "This is bulukulu festival year." << endl;

            on = 0;
        }


        if(on)
        {
            cout << "This is an ordinary year." << endl;
        }



    }

}


