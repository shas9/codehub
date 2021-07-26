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

string str, str1, str2;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(1)
    {
        cin >> str;

        n = str.size();

        for(i = 0; i < n; i++)
        {
            if(str)
            if(i)
            {
                if(abs(str[i - 1] - str[i]) == 1 && str[i - 1] != 'a')
                {
                    j = i - 2;
                    while(j >= 0 && str[j] == str[i - 1])
                    {
                        str[j] = 'X';
                        j--;
                    }
                }

            }

            if(i < (n - 1))
            {
                if(abs(str[i + 1] - str[i]) == 1 && str[i + 1] != 'a')
                {
                    j = i + 2;
                    while(j < n && str[j] == str[i + 1])
                    {
                        str[j] = 'X';
                        j++;
                    }
                }
            }
        }

        str1 = "";
        for(i = 0; i < n; i++)
        {
            if(str[i] == 'X') continue;

            str1 += str[i];
        }

        cout << str1 << endl;
    }


}



