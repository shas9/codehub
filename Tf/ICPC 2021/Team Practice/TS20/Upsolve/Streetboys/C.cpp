#include <bits/stdc++.h>
using namespace std;

int main ()
{
    //input
    int limit,ans=0,total=0,counter=0;
    cin>>limit;
    int month[12];
    for (int i=0; i<12; i++){
        cin>>month[i];
    }

    //code
    sort(month,month + 12);
    if(limit!=0){
        for (int i=11; i>=0; i--){
//        cout<<i<<' ';
//        cout<<month[i]<<' ';
//        cout<<total<<' ';
//        cout<<counter<<endl;
        counter++;
        total= total+month[i];
        if(total>=limit){
            break;
//            cout<<"break does not work"<<endl;
        }


//        cout<<"break does not work"<<endl;

    }
    }


    //output
    ans=counter;

    if(total < limit) ans = -1;

    cout << ans << endl;

    return 0;
}
