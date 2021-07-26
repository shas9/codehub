#include<stdio.h>

#define ll long long int
int main(){
    ll P, Q, Y;
    scanf("%lld %lld %lld", &P, &Q, &Y);

    ll sum;

    sum = (P * 52 * 5) + (Q * 52 * 2);
    sum = sum * Y;

    printf("%lld\n", sum);
    return 0;
}
