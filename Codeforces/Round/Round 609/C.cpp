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

string str1, str2;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
        cin >> str1;

        str2 = str1;


        for(i = 0; i < k; i++)
        {
            for(j = i + k; j < n; j += k)
            {
                str2[j] = str2[i];
            }
        }

        if(str2 >= str1)
        {
            cout << str2.size() << endl << str2 << endl;
        }
        else
        {
            ll hand = 0;

            ll st = k - 1;

//            for(i = 0; i < k; i++)
//            {
//                if(str2[i] - '0' == 9)
//                {
//                    st = i;
//                    break;
//                }
//            }

//            cout << st << endl;

            for(i = st; i >= 0; i--)
            {
                ll tmp = str2[i] - '0';

                tmp++;

                str2[i] = (tmp % 10) + '0';

                if(tmp <= 9)
                {
                    break;
                }
            }

            if(i < 0) str2.insert(str2.begin(),'1');

            n = str2.size();

            for(i = 0; i < k; i++)
            {
                for(j = i + k; j < n; j += k)
                {
                    str2[j] = str2[i];
                }
            }

            cout << n << endl << str2 << endl;
        }




    }


}



