#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pi 2*acos(0.0)
#define PI 3.1415926535897932
#define lim 1234567
using namespace std;

int _I(){int x; scanf("%d",&x); return x;}
ll _L(){ll x; scanf("%lld",&x); return x;}


int main()
{
        int n = _I();
        int A[n + 5];

        int dis = 0;
        for(int i = 1; i <= n; i++)
        {
                A[i] = _I();
        }

        int flag = 1;
        int x = 1000000000, y = 0;
        int temp = 1;
        for(int i = 1; i < n; i++)
        {
                int sub = abs(A[i + 1] - A[i]);
                if(sub == 0)
                        flag = 0;
                if(sub != 1)
                {
                        temp = 0;
                        if(dis == 0)
                                dis = sub;
                        else if(sub != dis)
                        {
                                flag = 0;
                                break;
                        }

                }
        }

        if( !flag )
        {
                cout << "NO";
                return 0;
        }

        if( temp )
        {
                cout << "YES\n" <<"1000000000 1000000000";
                return 0;
        }

        y = dis;

        for(int i = 1; i < n; i++)
        {
                if(A[i] % y == 0 && A[i + 1] % y == 1)
                        flag = 0;
                if(A[i] % y == 1 && A[i + 1] % y == 0)
                        flag = 0;
        }

        if( !flag )
        {
                cout << "NO";
                return 0;
        }

        cout << "YES\n" << x << " " << y;

        return 0;
}
