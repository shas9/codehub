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

string str;
vector < pll > sw;

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
        cin >> n >> k >> str;

        ll mn = 0;

        ll prv = -1;

        string tmp = "";

        ll sum = 0;

        sw.clear();

        for(i = 0; i < n; i++)
        {
            if(str[i] == ')') sum--;
            else sum++;

            if(sum == 0)
            {
                if(mn < 0)
                {
                    for(j = i; j > prv; j--) tmp += str[j];
                    sw.push_back({prv + 2, i + 1});
                }
                else for(j = prv + 1; j <= i; j++) tmp += str[j];


                mn = 0;
                prv = i;
                sum = 0;

            }

            mn = min(mn,sum);
        }

        str = tmp;

//        cout << str << endl;

        tmp = "";

        for(i = 0; i < n; i++)
        {
            if(str[i] == ')')
            {
                tmp = str;

                for(j = i; j < n; j++)
                {
                    if(str[j] == '(') break;
                }

                if(j == n) j--;

                if(i != j)sw.push_back({i + 1, j + 1});
                for(ll jj = i; j >= i; j--, jj++)
                {
                    tmp[jj] = str[j];
                }

                str = tmp;
            }
        }

//        cout << str << endl;

        k--;
        tmp = "";
        bool on = 0;

        for(i = 0; k; i++)
        {
            if(str[i] == '(')
            {
				if(on == 0)
				{
					on = 1;
					continue;
				}

				on = 0;
                k--;
                for(j = i + 1; j < n; j++)
                {
                    if(str[j] == ')') break;
                }

//                cout << i <<  " " << j << " ";

                if(i != j) sw.push_back({i + 1,j + 1});

                tmp = str;

                for(m = i; j >= i; j--, m++)
                {
                    tmp[m] = str[j];
                }

                str = tmp;

//                cout << tmp << endl;
            }
        }

//        cout << str << endl;

        cout << sw.size() << "\n";

		for(auto it: sw) cout << it.first<< " " << it.second << "\n";

    }


}



