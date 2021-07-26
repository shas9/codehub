/*
    Array: 9, 4, 6, 7, 5, 3, 8
    Descending Sorted Array: 9, 8, 7, 6, 5, 4, 3
    Ascending Sorted Array: 3, 4, 5, 6, 7, 8, 9

    Let n = 2^37
    n*n = n^2

    2^x * 2^y = 2^(x + y)

    1. Bubble Sort => O(n^2) => 2^37 * 2^37 = 2^74
    2. Selection Sort => O(n^2) => 2^37 * 2^37 = 2^74
    3. Merge Sort => O(nlog2basedn) => 2^37 * 37 = 2^37 * 2^5.623123 = 2^42.623123
    4. Quick Sort => O(nlog2basedn) => 2^42.623123
    5. Frequency Sort => O(maxofarrayelement) / O(n) => 2^37(Depends)

    O(nsqrt(n)) = 2^37 * sqrt(2^37) = 2^37 * 2 ^ (37 / 2) = 2^37 * 2^18.5 = 2^52.5

    sqrt(9) = 3;
    sqrt(n) = n^0.5
    36 = 2 * 18 = 2 * 2 * 9 = 2 * 2 * 3 * 3 = 2^2 * 3^2
    sqrt(36) = 6
    sqrt(2^2 * 3^2) = (2^2 * 3^2) ^ 0.5 = 2^1 * 3^1 = 2 * 3 = 6

    6 = 2*3
    8 = 2 * 4 = 2 * 2 * 2 = 2^3
    10 = 2 * 5

    log2(1) = 0
    log2(2) = 1;
    log2(3) = 1.sadasda;
    log2(4) = 2;
    log2(5) = 2.23123;
    log2(6) = 2.21312312;
    log2(7) = 2.23123123;
    log2(8) = 3;
    log2(9) = 3.adsda;
    log2(10) = 3.sadasd;
    log2(11) = 3.asdas;
    log2(12) = 3.asdasd;
    log2(13) = 3.asdasda;
    log2(14) = 3.asdead;
    log2(15) = 3.aedasdass;
    log2(16) = 4;

    log2(node) = x.weqweqe
    node is in xth depth

    log(130) =

    2^3 = 8;
    2^4 = 16;


    x^y != y^x

    log10(10^38) = 38
    log15(15^68) = 68
    log2(2^37) = 37;

    n / 1 + n / 2 + n /4 + n / 8 + n / 16.... nlog2(n)

    (n / 2^0) + ( n / 2^1) + (n / 2^2) + (n / 2^3) + (n / 2^4) = nlog2(n)

    (n / 3^0) + (n / 3^1) + (n / 3^2) + (n / 3^3) + .... = nlog3based(n)

    (n / 6^0) + (n / 6^1) + (n / 6^2) + (n / 6^3) + .... = nlog6based(n)

    (n / x^0) + (n / x^1) + (n / x^2) + (n / x^3) ..... = nlogx(n)

    1 + 2 + 3 + 4 + 5 + .... + n = n * (n + 1) / 2;


    Suppose a tree has node 350. And the tree is 8-rary tree.
    What is the complexity to search in this tree: O(nlog8(n)) = O(350*log8(350));
    Time needed: 350*log8(350) / 10^8 10^15

    2, 3, 5, 7, 11, 13, 17, 19
*/

#include<stdio.h>

int arr[1000];
int val[1000];

int main()
{
    int i, n;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    val[1] = arr[sz];

    for(i = 2; i <= n; i++)
    {
        val[i] = arr[i];

        int cursor = i;

        while(cursor != 1)
        {
            int par = cursor / 2;

            if(val[par] < val[cursor])
            {
                int temp = val[par];
                val[par] = val[cursor];
                val[cursor] = temp;
            }
            else break;

            cursor = par;
        }
    }

    for(i = 1; i <= n; i++)
    {
        printf("Node value is: %d, child value is %d, %d\n", val[i], val[i * 2], val[i * 2 + 1]);
    }

}

