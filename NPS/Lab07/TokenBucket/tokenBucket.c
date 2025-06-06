#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double tokens;
    double bucket_size;
    double replenish_rate;
    double max_rate;
    double last_time;
} TokenBucket;

void init_bucket(TokenBucket *bucket, double size, double rate, double max_rate) {
    bucket->tokens = size;
    bucket->bucket_size = size;
    bucket->replenish_rate = rate;
    bucket->max_rate = max_rate;
    bucket->last_time = 0.0;
}

void update_tokens(TokenBucket *bucket, double current_time) {
    double elapsed = current_time - bucket->last_time;
    bucket->tokens += elapsed * bucket->replenish_rate;    
    if (bucket->tokens > bucket->bucket_size) {
        bucket->tokens = bucket->bucket_size;
    }
    bucket->last_time = current_time;
}

int transmit_packet(TokenBucket *bucket, double packet_size, double current_time) {
    update_tokens(bucket, current_time);    
    if (bucket->tokens >= packet_size) {
        bucket->tokens -= packet_size;
        return 1;
    }
    return 0;
}

int main() {
    TokenBucket bucket;
    double replenish_rate = 10.0;
    double bucket_size = 50.0;
    double packet_size = 15.0;
    double packet_interval = 0.5;
    double simulation_time = 5.0;    
    printf("TOKEN BUCKET CONGESTION CONTROL SIMULATION\n");
    printf("==========================================\n");
    printf("Bucket Size: %.1f KBytes\n", bucket_size);
    printf("Replenishment Rate: %.1f KBps\n", replenish_rate);
    printf("Packet Size: %.1f KBytes\n", packet_size);
    printf("Packet Interval: %.1f seconds\n\n", packet_interval);    
    init_bucket(&bucket, bucket_size, replenish_rate, 999999.0);    
    printf("Time\tTokens Before\tPacket\tTokens After\tStatus\n");
    printf("----\t-------------\t------\t------------\t------\n");    
    double queue_start_time = -1;
    double time = 0.5;
    int packet_count = 0;    
    while (time <= simulation_time) {
        double tokens_before = bucket.tokens;
        update_tokens(&bucket, time);
        tokens_before = bucket.tokens;        
        int transmitted = transmit_packet(&bucket, packet_size, time);
        packet_count++;        
        printf("%.1f\t%.1f\t\t%.1f\t%.1f\t\t%s\n", 
               time, tokens_before, packet_size, bucket.tokens,
               transmitted ? "SENT" : "QUEUED");        
        if (!transmitted && queue_start_time < 0) {
            queue_start_time = time;
        }        
        time += packet_interval;
    }    
    printf("\n==========================================\n");
    printf("ANALYSIS RESULTS:\n\n");    
    init_bucket(&bucket, bucket_size, replenish_rate, 999999.0);
    update_tokens(&bucket, 1.5);
    transmit_packet(&bucket, packet_size, 0.5);
    update_tokens(&bucket, 1.0);
    transmit_packet(&bucket, packet_size, 1.0);
    update_tokens(&bucket, 1.5);
    transmit_packet(&bucket, packet_size, 1.5);    
    printf("i. Tokens left after 1.5 seconds: %.1f KBytes\n", bucket.tokens);    
    if (queue_start_time > 0) {
        printf("ii. Packets start queuing at: %.1f seconds\n", queue_start_time);
    } else {
        printf("ii. No packets queued in simulation period\n");
    }    
    printf("iii. Maximum burst size with R=20KBps: %.1f KBytes\n", bucket_size);    
    printf("\nDETAILED CALCULATION:\n");
    printf("At t=0.5: 50K + 5K = 50K (capped), send 15K, left: 35K\n");
    printf("At t=1.0: 35K + 5K = 40K, send 15K, left: 25K\n");
    printf("At t=1.5: 25K + 5K = 30K, send 15K, left: 15K\n");
    printf("At t=2.0: 15K + 5K = 20K, send 15K, left: 5K\n");
    printf("At t=2.5: 5K + 5K = 10K, need 15K, QUEUE!\n");    
    printf("\nAdvanced Token Bucket with Maximum Rate Limiting:\n");
    TokenBucket limited_bucket;
    init_bucket(&limited_bucket, 50.0, 10.0, 20.0);    
    printf("\nWith R=20KBps limitation:\n");
    printf("- Bucket can store max 50K tokens\n");
    printf("- Max transmission rate: 20KBps\n");
    printf("- Maximum burst size: %.1f KBytes\n", bucket_size);
    printf("- Burst duration: %.2f seconds\n", bucket_size / 20.0);
    
    return 0;
}
