#include<bits/stdc++.h>
using namespace std;

int a[120];

vector<int> E;

int main()
{
    int n;

    scanf("%d",&n);

    int flag = 1;

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)flag = 0;
    }

    if(flag)
    {
        return puts("0");
    }

    int count = 0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            E.push_back(count+1);
            count = 0;
        }
        else
        {
            count++;
        }
    }

    long long ans = 1;

    for(int i=1;i<E.size();i++)
    {
        ans = ans * E[i];
    }
    cout<<ans<<endl;
}
