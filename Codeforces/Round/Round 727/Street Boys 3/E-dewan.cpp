#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int i, counter=0;
    string str1, str2 ;
    cin >> str1 ;
    for(i=0; i<str1.length(); i++) if(str1[i]>=65 && str1[i]<=90) str1[i]+=32;
    while(1)
    {
        getline(cin, str2);

        cout << "Taken input: " << str2 << "\n";

        if(str2=="END_OF_TEXT") break ;
        else
        {
            for(i=0; i<str2.length(); i++) if(str2[i]>=65 && str2[i]<=90) str2[i]+=32;
            if(str2==str1) counter++ ;

            cout << "Input after processed: " << str2 << "\n";
        }
    }
    cout << counter << endl ;

}
