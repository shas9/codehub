#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int i, j, k, t, n;
    string str ;
    cin >> t ;
    for(k=1; k<=t; k++)
    {
        int checker = 97, idx1, idx2 , flag=0, ans=0;
        cin >> str ;

        cout << idx1 << " " << idx2 << "\n";
        for(i=0; i<str.length(); i++)
        {
            if(i==str.length())
            {
                flag=1;
                break;
            }
            if(int(str[i])==checker)
            {
                idx1 = i;
                idx2 = i;
                break;
            }
        }
        if(str.length()==1 && str[0]!='a')
        {
            cout << "NO" << endl ;
        }
        else if(flag==1)
        {
            cout << "NO" << endl ;
            break;
        }
        else
        {
            checker++;
            while(1)
            {
                if(int(str[idx1-1]) == checker )
                {
                    checker++;
                    idx1--;
                }
                else if(int(str[idx2+1]) == checker)
                {
                    checker++;
                    idx2++;
                }
                else break ;
            }
            if(idx1==0 && idx2==(str.length()-1)) cout << "YES" << endl ;
            else cout << "NO" << endl ;
        }

    }
}
