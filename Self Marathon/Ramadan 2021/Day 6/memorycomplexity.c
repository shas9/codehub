#include<stdio.h>

/* Memory allocation

    int a; -> 4 byte
    double b; -> 8 byte
    char c; -> 1 byte
    float d; -> 4 byte


    1 byte = 8 bit;


    int a; -> 32 bit
    double b; -> 64 bit
    char c; -> 8 bit
    float d; -> 32 bit

    int total combination = 2^32 combination;
    2^31 negetive
    2^31 positive
    2^31 + 2^31 = 2^32

    double total combination = 2^64 combination (Less presicion error)

    2^63 negetive
     2^62 bit for before dot (doshomik)
     2^62 bit for after dot

    2^63 positive
     2^62 bit for before dot (doshomik)
     2^62 bit for after dot

    float total combination = 2^32 combination (More precision error)

    2^31 negetive
        2^30 bit for before dot
        2^30 bit for after dot
    2^31 postive
        2^30 bit for before dot
        2^30 bit for after dot

    char bit combination = 2^8
    2^8 = 256

    2^7 bit

    1 byte

    8, 16, 32, 64, 128
    7 bit X
*/


/*

    a + a = 2 * a

    2^2 = 4;

    4 + 4 = 8 = 2^3

    2^2 + 2^2 = 2 * 2^2 = 2 * 2 * 2 = 2^3

    2^3 + 2^3 = 2 * 2^3 = 2 * 2 * 2 * 2 = 2^4

    2^4 + 2^4 = 2 * 2^4 = 2 * (2 * 2 * 2 * 2) = 2 * 2 * 2 * 2 * 2 = 2^5
    2^5 + 2^5 = 2^6
    2^6 + 2^6 = 2^7
    2^14 + 2^14 = 2^15

    2^n + 2^n = 2 * 2^(n) = 2^(n + 1)


    with 3 bit, we can make combination of 2^3 numbers
    with n bit, we can make combination of 2^n numbers

    000 -> 0
    001 -> 1
    010 -> 2
    011 -> 3
    100 -> 4
    101 -> 5
    110 -> 6
    111 -> 7

    2^2 = 4
    00
    01
    10
    11

*/


int main()
{
    int a;
    double b;
    char c;
    float d;


    int arr[n];
    double arr[m];
    float arr[o];
    char arr[p];


    //memory complexity: O(20 * 4 + 40 * 8);

    // memory accurate complexity: O(n * 4 + m * 8 + o * 4 + p * 1);
    // memory general complexity: O(n + m + o + p);

    int array[n];
    double array[n];
    float array[n];
    char array[n];

    /* memory accurate complexity:
        O(n * 4 + n * 8 + n * 4 + n * 1)
        O(4n + 8n + 4n + n)
        O(17n)

        memory general complexity:
        O(n)

    */
}
