#include <stdio.h>

int main() {
    int packet_arrival_times[] = {1, 2, 3, 5, 6, 8, 11, 12, 15, 16, 19};
    int n = sizeof(packet_arrival_times) / sizeof(packet_arrival_times[0]);
    int packet_size = 4;
    int bucket_size = 10;
    int outgoing_rate = 1;    
    int current_time = 0;
    int bucket_content = 0;
    int conforming_count = 0;
    int nonconforming_count = 0;    
    printf("LEAKY BUCKET CONGESTION CONTROL SIMULATION\n");
    printf("==========================================\n");
    printf("Bucket Size: %d bytes\n", bucket_size);
    printf("Packet Size: %d bytes each\n", packet_size);
    printf("Outgoing Rate: %d byte/second\n\n", outgoing_rate);    
    printf("Time\tPacket\tBucket Before\tConforming\tBucket After\tStatus\n");
    printf("----\t------\t-------------\t----------\t------------\t------\n");    
    for (int i = 0; i < n; i++) {
        int t = packet_arrival_times[i];        
        int leak_time = t - current_time;
        bucket_content -= leak_time * outgoing_rate;
        if (bucket_content < 0){
            bucket_content = 0;        
        }
        current_time = t;
        int bucket_before = bucket_content;        
        int conforming = 0;
        char status[20];        
        if (bucket_content + packet_size <= bucket_size) {
            bucket_content += packet_size;
            conforming = 1;
            conforming_count++;
            strcpy(status, "ACCEPTED");
        } else {
            nonconforming_count++;
            strcpy(status, "DROPPED");
        }        
        printf("%d\t%d\t%d\t\t%s\t\t%d\t\t%s\n", 
               t, packet_size, bucket_before, 
               conforming ? "Yes" : "No", bucket_content, status);
    }    
    printf("\n==========================================\n");
    printf("SIMULATION SUMMARY:\n");
    printf("Total Packets: %d\n", n);
    printf("Conforming Packets: %d\n", conforming_count);
    printf("Nonconforming Packets: %d\n", nonconforming_count);
    printf("Acceptance Rate: %.2f%%\n", (float)conforming_count/n * 100);    
    return 0;
}
