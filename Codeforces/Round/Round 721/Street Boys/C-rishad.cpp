#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;

    cin >> tc;

    for(int i = 1; i <= tc; i++)
    {
        int a,b=0,c=0,d,e,f,g;
        int n;
        cin>>n;

        d = n;

        while(n>0)
        {
            a=n%10;
            b=b*10+a;
            n=n/10;
        }

        if(b==d)
        {
            cout<<"Case "<<i<<": Yes"<<endl;

        }
        else
        {
            cout<<"Case "<<i<<": No"<<endl;
        }

    }
    return 0;
}
