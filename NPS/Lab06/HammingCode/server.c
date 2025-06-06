#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int detectError(char *received) {
    int len = strlen(received);
    int parity = (int)ceil(log2(len));
    int syndrome = 0;    
    for(int i = 0; i < parity; i++) {
        int parPos = (1 << i);
        int parVal = 0;        
        for(int j = 1; j <= len; j++) {
            if(j & parPos) {
                parVal ^= (received[len-j] - '0');
            }
        }        
        if(parVal != 0) {
            syndrome += parPos;
        }
    }    
    return syndrome;
}

void correctError(char *received, int errPos) {
    int len = strlen(received);
    int pos = len - errPos;    
    if(received[pos] == '0') {
        received[pos] = '1';
    } else {
        received[pos] = '0';
    }
}

void extractData(char *encoded, char *data) {
    int len = strlen(encoded);
    int pos = 0;    
    for(int i = 1; i <= len; i++) {
        if((i & (i-1)) != 0) {
            data[pos++] = encoded[len-i];
        }
    }
    data[pos] = '\0';
}

int main() {
    char received[200], corrected[200], original[100];
    int errPos;    
    printf("Enter received Hamming code: ");
    scanf("%s", received);
    strcpy(corrected, received);    
    printf("Received: %s\n", received);    
    errPos = detectError(corrected);    
    if(errPos == 0) {
        printf("No error detected\n");
    } else {
        printf("Error detected at position: %d\n", errPos);
        correctError(corrected, errPos);
        printf("Corrected code: %s\n", corrected);
    }    
    extractData(corrected, original);
    printf("Original data: %s\n", original);    
    return 0;
}
