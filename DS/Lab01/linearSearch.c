#include <stdlib.h>
#include <stdio.h>

int main()
{
    //Linear Searching
    int ar[] = {4,2,55,2,9,3,60,6,77,56,877};
    int i,m;
    printf("Number to find: ");
    scanf("%d",&m);
    for(i=0;i<(sizeof(ar)/sizeof(ar[0]));i++)
    {
        if(m == ar[i])
        {
            printf("Element found at %d",i);
            break;
        }
    }
    return EXIT_SUCCESS;
}
