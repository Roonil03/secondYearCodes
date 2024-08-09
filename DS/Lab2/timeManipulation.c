#include <stdio.h>
#include <stdlib.h>

struct Time {
    int hour;
    int min;
    int sec;
};
typedef struct Time Time;

Time readTime() {
    struct Time t;
    printf("Enter hour, minute, and second: ");
    scanf("%d %d %d", &t.hour, &t.min, &t.sec);
    return t;
}

void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;

    result.sec %= 60;
    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;

    result.hour %= 24;
    return result;
}

struct Time findDifference(struct Time t1, struct Time t2) {
    struct Time result;
    if (t2.sec > t1.sec) {
        t1.min--;
        t1.sec += 60;
    }
    result.sec = t1.sec - t2.sec;
    if (t2.min > t1.min) {
        t1.hour--;
        t1.min += 60;
    }
    result.min = t1.min - t2.min;
    result.hour = (t1.hour - t2.hour + 24) % 24; 
    return result;
}

int main() {
    struct Time t1, t2, sum, diff;

    printf("Enter first time:\n");
    t1 = readTime();

    printf("Enter second time:\n");
    t2 = readTime();

    sum = addTime(t1, t2);
    printf("Sum of times: ");
    displayTime(sum);

    diff = findDifference(t1, t2);
    printf("Difference between times: ");
    displayTime(diff);

    return EXIT_SUCCESS;
}