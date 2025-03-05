#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* thread_id) {
    long tid = (long)thread_id;
    printf("Thread ID: %ld\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int rc;
    long t;

    for (t = 0; t < 5; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_message, (void*)t);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (t = 0; t < 5; t++) {
        pthread_join(threads[t], NULL);
    }

    return 0;
}