#include<stdio.h>

int a[200009];
int ans=0;
void Merge(int leftSTART,int leftEND,int rightSTART,int rightEND)
{
    int i;
    int pos = 0;
    int pp = leftSTART;
    int temp[rightEND-leftSTART+3];
    while(leftSTART<=leftEND&&rightSTART<=rightEND)
    {
        if(a[leftSTART]<=a[rightSTART])
        {
            temp[pos]=a[leftSTART];
            pos++;
            leftSTART++;
        }
        else
        {
            ans=ans+(leftEND-leftSTART+1);
            temp[pos++]=a[rightSTART++];
        }
    }
    while(leftSTART<=leftEND)
    {
        temp[pos++]=a[leftSTART++];
    }
    while(rightSTART<=rightEND)
    {
        temp[pos++]=a[rightSTART++];
    }
    for(i=0;i<pos;i++)
    {
        a[pp+i]=temp[i];
    }
    return;
}

void MergeSort(int left,int right)
{
    int mid = (left + right)>>1;
    if(left < right)
    {
        MergeSort(left,mid);
        MergeSort(mid+1,right);
        Merge(left,mid,mid+1,right);
    }
}

int main()
{
   int i,j,k,n,m,d;

        ans=0;
        printf("Enter n: ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("Enter elements no %d: ", i + 1);
            scanf("%d",&a[i]);
        }
        MergeSort(0,n-1);
        printf("Total inversions : %d\n", ans);

    return 0;
}
