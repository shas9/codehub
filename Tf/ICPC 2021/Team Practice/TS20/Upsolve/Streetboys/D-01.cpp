#include<iostream>
using namespace std;
int main()
{
   int n;
   cin>>n;

   long long int a[n];

   for(int i=0; i<n; i++)
   {
       cin>>a[i];
   }

   for(int i=0; i<n; i++)
   {
       long long int s=a[i],ct=0;
        for(int i=1; i<100; i++)
            {
                if(s>=i)
                {
                    s=s-i;
                    ct++;
                }
            }
            cout<<ct<<endl;
   }
}
