#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char crc12[] = "1100000001111";
char crc16[] = "11000000000000101";
char ccitt[] = "10001000000100001";

int verifyCRC(char *data, char *poly) {
    char temp[1000];
    int dlen = strlen(data);
    int plen = strlen(poly);
    int i, j;    
    strcpy(temp, data);    
    for(i = 0; i <= dlen - plen; i++) {
        if(temp[i] == '1') {
            for(j = 0; j < plen; j++) {
                if(temp[i + j] == poly[j]) {
                    temp[i + j] = '0';
                } else {
                    temp[i + j] = '1';
                }
            }
        }
    }    
    for(i = 0; i < dlen; i++) {
        if(temp[i] == '1') {
            return 0;
        }
    }
    return 1;
}

void binToChar(char *binary, char *output) {
    int len = strlen(binary);
    int i, j = 0;    
    for(i = 0; i < len; i += 8) {
        int ascii = 0;
        for(int k = 0; k < 8; k++) {
            if(binary[i + k] == '1') {
                ascii += (1 << (7 - k));
            }
        }
        output[j++] = (char)ascii;
    }
    output[j] = '\0';
}

int main() {
    char frame[1000], message[100];
    char *polys[] = {crc12, crc16, ccitt};
    char *names[] = {"CRC-12", "CRC-16", "CRC-CCITT"};
    int choice;    
    printf("Enter received frame: ");
    scanf("%s", frame);    
    printf("Select CRC used:\n1. CRC-12\n2. CRC-16\n3. CRC-CCITT\n");
    scanf("%d", &choice);    
    if(choice < 1 || choice > 3) {
        printf("Invalid choice\n");
        return 1;
    }    
    printf("Using %s polynomial: %s\n", names[choice-1], polys[choice-1]);    
    if(verifyCRC(frame, polys[choice-1])) {
        printf("No error detected - Data is correct\n");        
        int plen = strlen(polys[choice-1]);
        int flen = strlen(frame);
        int dlen = flen - plen + 1;        
        char data[1000];
        strncpy(data, frame, dlen);
        data[dlen] = '\0';        
        printf("Original data: %s\n", data);        
        if(dlen % 8 == 0) {
            binToChar(data, message);
            printf("Decoded message: %s\n", message);
        }
    } else {
        printf("Error detected - Data is corrupted\n");
    }    
    return 0;
}
