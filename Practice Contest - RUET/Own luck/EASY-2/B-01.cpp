#include <bits/stdc++.h>
#define ll long long
#define S 1000003
using namespace std;

double cuS[S];

void cumulativeSum()
{
    cuS[1] = log((double)1);
    for(double i = 2; i < S; i++){
        cuS[i] = cuS[i-1] + log((double)i);

        //cout << i << " " << log((double)i) <<  " " << log(i) << endl;
    }
}

int main(){
    int  t, cs = 0, n, base;
    cumulativeSum();
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &base);
        double value = cuS[n];
        value /= log((double)base);
        ll ans = value;
        ans += 1;
        printf("Case %d: %lld\n", ++cs, ans);
    }
    return 0;
}
