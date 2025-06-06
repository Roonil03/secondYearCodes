#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char crc12[] = "1100000001111";
char crc16[] = "11000000000000101";
char ccitt[] = "10001000000100001";

void calcCRC(char *data, char *poly, char *result) {
    int dlen = strlen(data);
    int plen = strlen(poly);
    int i, j;    
    strcpy(result, data);    
    for(i = 0; i < plen - 1; i++) {
        strcat(result, "0");
    }    
    for(i = 0; i <= strlen(result) - plen; i++) {
        if(result[i] == '1') {
            for(j = 0; j < plen; j++) {
                if(result[i + j] == poly[j]) {
                    result[i + j] = '0';
                } else {
                    result[i + j] = '1';
                }
            }
        }
    }
}

void charToBin(char *input, char *binary) {
    int i, j;
    binary[0] = '\0';    
    for(i = 0; i < strlen(input); i++) {
        char temp[9];
        int ascii = (int)input[i];        
        for(j = 7; j >= 0; j--) {
            temp[7-j] = ((ascii >> j) & 1) ? '1' : '0';
        }
        temp[8] = '\0';
        strcat(binary, temp);
    }
}

int main() {
    char input[100], binary[1000], result[1000];
    char *polys[] = {crc12, crc16, ccitt};
    char *names[] = {"CRC-12", "CRC-16", "CRC-CCITT"};
    int choice, i;    
    printf("Enter message: ");
    scanf("%s", input);    
    printf("Select CRC:\n1. CRC-12\n2. CRC-16\n3. CRC-CCITT\n");
    scanf("%d", &choice);    
    if(choice < 1 || choice > 3) {
        printf("Invalid choice\n");
        return 1;
    }    
    charToBin(input, binary);
    printf("Binary data: %s\n", binary);    
    calcCRC(binary, polys[choice-1], result);    
    int plen = strlen(polys[choice-1]);
    int dlen = strlen(binary);    
    printf("CRC remainder: ");
    for(i = dlen; i < dlen + plen - 1; i++) {
        printf("%c", result[i]);
    }
    printf("\n");    
    printf("Transmitted frame: %s", binary);
    for(i = dlen; i < dlen + plen - 1; i++) {
        printf("%c", result[i]);
    }
    printf("\n");    
    printf("Using %s polynomial: %s\n", names[choice-1], polys[choice-1]);    
    return 0;
}
