#include <stdio.h>
#include <time.h>

int main() {

    time_t seconds_start;
    time_t seconds_end;

    //take a time
    time(&seconds_start);
    printf("\nStart Timestamp: %ld\n", seconds_start);

    printf("\nNow running long for loop.\n");

    for (long i = 1; i <= 100000000000; i++){
    }

    //take a time
    time(&seconds_end);
    printf("\nEnd Timestamp: %ld\n", seconds_end);
    printf("\nElapsed Seconds: %ld\n\n", seconds_end - seconds_start);

    return 0;
}