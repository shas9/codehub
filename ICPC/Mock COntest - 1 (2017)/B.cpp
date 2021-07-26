#include<bits/stdc++.h>
using namespace std;
int main(){
   int nDay = 101;
   printf("%d\n", nDay);
   printf("198");

   for(int i = 2; i <= 101; i++) {
        if(i % 2 == 1)
            printf(" %d", 198);
        else
            printf(" %d", i);
   }

   printf("\n");
   return 0;
}
