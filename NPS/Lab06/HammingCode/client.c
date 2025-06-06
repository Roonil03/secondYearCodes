#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calcParity(char *data, char *encoded) {
    int dlen = strlen(data);
    int parity = (int)ceil(log2(dlen + ceil(log2(dlen)) + 1));
    int elen = dlen + parity;
    int pos = 0;    
    for(int i = 0; i < elen; i++) {
        encoded[i] = '0';
    }    
    for(int i = 1; i <= elen; i++) {
        if((i & (i-1)) != 0) {
            encoded[elen-i] = data[pos++];
        }
    }    
    for(int i = 0; i < parity; i++) {
        int parPos = (1 << i);
        int parVal = 0;
        
        for(int j = 1; j <= elen; j++) {
            if(j & parPos) {
                parVal ^= (encoded[elen-j] - '0');
            }
        }
        encoded[elen-parPos] = '0' + parVal;
    }    
    encoded[elen] = '\0';
}

int main() {
    char data[100], encoded[200];    
    printf("Enter binary data: ");
    scanf("%s", data);    
    calcParity(data, encoded);    
    printf("Original data: %s\n", data);
    printf("Encoded with Hamming: %s\n", encoded);
    printf("Total bits: %d (Data: %d, Parity: %d)\n", 
           (int)strlen(encoded), (int)strlen(data), 
           (int)strlen(encoded) - (int)strlen(data));    
    return 0;
}
