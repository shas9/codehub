#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x=0;
    char str[20];
    while(n--)
    {
        cin>>str;
        if(str[1]=='+')
            x++;
        else
            x--;
    }
    cout<<x<<endl;
}
