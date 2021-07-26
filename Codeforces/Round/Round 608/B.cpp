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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
        vector < ll > b, w;

        for(i = 0; i < n; i++)
        {
            if(str[i] == 'B') b.push_back(i);
            else w.push_back(i);
        }

        ll odd = 0;
        bool no = 0;

        ll prv = -1;

        for(auto it:b)
        {
            if(prv == -1) prv = it;
            else
            {
                if((it - prv) % 2 == 0)
                {
                    odd = 1;
                    break;
                }
                prv = it;
            }
        }

        prv = -1;

        for(auto it:w)
        {
            if(prv == -1) prv = it;
            else
            {
                if((it - prv) % 2 == 0 && odd)
                {
                    no = 1;
                    break;
                }
                else if((it - prv) % 2 == 0)
                {
                    odd = 2;
                    break;
                }

                prv = it;

            }
        }


        if(no)
        {
            cout << -1 << endl;
        }
        else if(b.size() == 0 || w.size() == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            vector < ll > tmp;

            prv = -1;
            if(odd == 1)
            {
                for(auto it: b)
                {
                    if(prv == -1) prv = it;
                    else
                    {
                        for(j = prv; j < it; j++) tmp.push_back(j);
                        prv = it;
                    }
                }
            }
            else if(odd == 2)
            {
                for(auto it: w)
                {
                    if(prv == -1) prv = it;
                    else
                    {
                        for(j = prv; j < it; j++) tmp.push_back(j);
                        prv = it;
                    }
                }
            }
            else
            {
                for(auto it: )
            }

            cout << tmp.size() << "\n";

            for(auto it: tmp) cout << it << " ";

            cout << "\n";

            for(auto it: tmp)
            {
                if(str[it] == 'B') str[it] = 'W';
                else str[it] = 'B';

                if(str[it + 1] == 'B') str[it + 1] = 'W';
                else str[it + 1] = 'B';
            }

            cout << str << "\n";
        }
    }


}


