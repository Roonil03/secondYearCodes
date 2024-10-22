#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ar[5];
    int i,j,n=sizeof(ar)/sizeof(ar[0]);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d of array: ",i);
        scanf("%d",&ar[i]);
    }
    printf("\nSorting Array. . .\n\n");

    //Selection Sort
    int min,indexOfMin;
    for(i=0;i<n-1;i++)
    {
        min = ar[i];
        indexOfMin=i;
        for(j=i;j<n;j++)
        {
            if(min>ar[j]){
                min = ar[j];
                indexOfMin = j;
            }
        }
        int temp;
        temp = ar[i];
        ar[i] = ar[indexOfMin];
        ar[indexOfMin] = temp;
        //ar[i] = ar[i] + ar[indexOfMin];
        //ar[indexOfMin] = ar[i] - ar[indexOfMin];
        //ar[i] = ar[i] - ar[indexOfMin];
    }

    //Printing Sorted Array
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    return EXIT_SUCCESS;
}
