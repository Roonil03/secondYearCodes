#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar[5];
    int i,j,n = sizeof(ar)/sizeof(ar[0]);

    for(i=0;i<n;i++)
    {
        printf("Enter element %d of array: ",i);
        scanf("%d",&ar[i]);
    }
    printf("\nSorting Array. . .\n\n");

    //Insertion Sort
    for(i=1;i<n;i++)
    {
        j=i;
        while(ar[j]<ar[j-1]|| j == -1)
        {
            int temp;
            temp = ar[j];
            ar[j] = ar[j-1];
            ar[j-1] = temp;
            j--;
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    return EXIT_SUCCESS;
}
