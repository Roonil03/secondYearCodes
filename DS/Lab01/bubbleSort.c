#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar[3];
    int i, n = sizeof(ar)/sizeof(ar[0]),j;
    for(i=0;i<n;i++)
    {
        printf("Enter element %d of array: ",i);
        scanf("%d",&ar[i]);
    }
    printf("\nSorting Array. . .\n\n");

    //Bubble Sorting Array
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                ar[j] =ar[j]+ar[j+1];
                ar[j+1] = ar[j]-ar[j+1];
                ar[j] = ar[j] - ar[j+1];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    return EXIT_SUCCESS;
}
