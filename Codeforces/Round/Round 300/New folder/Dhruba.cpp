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

string inn;
string com;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans, x;

//     freopen("in.txt", "r", stdin);

    while(cin >> inn)
    {
        slld(testcase);
        ll sz = inn.size();

        assert(1 <= sz && sz <= 100);
        assert(1 <= testcase && testcase <= 1000);
        for(i = 1; i <= testcase; i++)
        {
            cin >> com;
            slld(x);

            if(com[0] == '+')
            {
                if(com[1] == '+')
                {
                    for(j = 0; j < sz; j++)
                    {
                        ll id = inn[j] - 'a';
                        id += x;

                        id %= 26;

                        inn[j] = id + 'a';
                    }
                    cout << inn << endl;
                }
                else if(com[1] == '-')
                {
                    if(x % 2 == 0) reverse(inn.begin(),inn.end());

                    cout << inn << endl;
                }
                else
                {
                    if(x % 2)
                    {
                        string pal = inn;

                        reverse(pal.begin(),pal.end());

                        if(pal == inn)
                        {
                            cout << "YES" << endl;
                        }
                        else cout << "NO" << endl;
                    }
                    else
                    {
                        ll sum = 0;
                        for(j = 0; j < sz; j++)
                        {
                            sum += (inn[j] - 'a') + 97;
                        }

                        cout << sum << endl;
                    }
                }
            }
            else if(com[0] == '-')
            {
                if(com[1] == '+')
                {
                    if(x % 2) reverse(inn.begin(),inn.end());

                    cout << inn << endl;
                }
                else if(com[1] == '-')
                {
                    for(j = 0; j < sz; j++)
                    {
                        ll id = inn[j] - 'a';
                        id -= x;

//                        cout << id << " && ";
                        while(id < 0)
                        {
                            id += 26;
                        }

//                        cout << id << endl;

                        inn[j] = id + 'a';
                    }
                    cout << inn << endl;
                }
            }
            else
            {
                assert(1 <= x && x <= sz);
                ll id = inn[x - 1] - 'a';
                id += 97;

                string as = "";

                for(j = 30; j >= 0; j--)
                {
                    if(check(id,j)) as += '1';
                    else as += '0';
                }

                bool on = 0;

                for(j = 0; j <= 30; j++)
                {
                    ll ff = as[j] - '0';

                    if(ff) on = 1;

                    if(on) cout << as[j];
                }

                cout << endl;

            }
        }
        cout << inn << endl;
    }


}


