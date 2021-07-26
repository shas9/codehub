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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

using namespace std;

deque < ll > dq;
ll arr[1000006];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);
    slld(testcase);

    string in;
    string in2;

    dq.clear();

    ll mx = 0, mn = mxlld;

    ll num = 0;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> in >> in2;

        if(in == "Insert")
        {
            slld(num);

            if(in2 == "Back")
            {
                dq.push_back(num);
            }
            else
            {
                dq.push_front(num);
            }

            mx = max(mx,num);
            mn = min(mn,num);

            arr[num]++;
        }
        else if(in == "Erase")
        {

            if(in2 == "Back")
            {
                num = dq[dq.size() - 1];
                dq.pop_back();
            }
            else
            {
                num =  dq[0];
                dq.pop_front();
            }

            arr[num]--;

            //cout << dq.size() << " -- " <<  endl;
            if(arr[mx] == 0)
            {
                if(dq.size() == 0)
                {
                    mx = 0;
                }
                else
                while(arr[mx]==0)
                {
                    mx--;
                    if(mx == 0)
                    {
                        break;
                    }
                }
            }
            if(arr[mn] == 0)
            {
                if(dq.size() == 0)
                {
                    mn = 0;
                }
                else
                while(arr[mn]==0)
                {
                    mn++;

                    if(mn == 1000000)
                    {
                        break;
                    }
                }
            }

            //cout << arr[8] << " ++ " <<  endl;
        }
        else if(in == "Get")
        {
            if(in2 == "Front")
            {
                cout << dq[0] << endl;
            }
            else if(in2 == "Back")
            {
                cout << dq[dq.size() - 1] << endl;
            }
            else if(in2 == "Max")
            {
                cout << mx << endl;
            }
            else
            {
                cout << mn << endl;
            }
        }
    }


}

