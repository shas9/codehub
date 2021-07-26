#include<stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);

    char name[100];
    char phone[20];
    char email[30];

    scanf("%[^\n]s", name);
    scanf("%s", phone);
    scanf("%s", email);

//    printf("%s is your name.\n", name);
//    printf("%s is your phone number.\n", phone);
//    printf("%s is your email.\n", email);
//

    printf("%s\n", name);
    printf("%s\n", phone);
    printf("%s\n", email);
}
