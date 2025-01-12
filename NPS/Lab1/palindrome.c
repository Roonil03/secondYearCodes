#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[128];
    printf("Enter string: ");
    scanf("%s", buffer);
    int i = 0;
    int len = strlen(buffer);
    while(i <len/2){
        if(buffer[i] != buffer[len - i - 1])
        {
            printf("Not a palindrome\n");
            return EXIT_SUCCESS;
        }
        i++;
    }
    printf("Is a Palindrome...\n");
    return EXIT_SUCCESS;
}
