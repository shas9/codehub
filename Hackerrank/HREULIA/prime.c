#include <stdio.h>

int main()
{
    long long  number;

    int testcase, i;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
    //printf("Enter a number to know its largest prime factor: ");
    scanf("%lld",&number);
    long long div=2, ans = 0, maxFact;
    while(number!=0){
        if(number % div !=0)
            div = div + 1;
        else{
            maxFact  = number;
            number = number / div;

            if(number == 1){

                //ans = 1;
                break;
            }
        }
    }
    printf("%d\n",maxFact);
    }
    return 0;
}
