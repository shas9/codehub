#include <bits/stdc++.h>

#define bug cout << "Bug" << endl;
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    int r1,r2,r3,c1,c2,c3;
    int i,j,k,sum = 0;

    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);



    int A[r1][c1],B[r2][c2];

    //condition check
    if(c1!=r2)
    {
        printf("Error");
        return 0;
    }

    //input for 1st matrix
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    //input for 2nd matrix
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    int C[r1][c2];

    //multiplication
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            for(k=0; k<r2; k++)
            {
                sum = sum + A[i][k]*B[k][j];
            }
            C[i][j] = sum;
            sum = 0;
        }

    }

    bug;
    //printing 1st matrix
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    //printing 2nd matrix
    for(i=0; i<r2; i++)
    {
        for(j=0; j<c2; j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }


    //printing product
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

