#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

void *worker(void *arg) {
    int *data = (int *)arg;
    *data = *data + 1;
    printf("Data is %d\n", *data);
    return (void *)42;  // return value
}

int data;

int main() {
    int status;
    data = 0;
    pthread_t thread;
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        pthread_create(&thread, NULL, &worker, &data);
        pthread_join(thread, NULL);
    } else {
        // Parent process
        pthread_create(&thread, NULL, &worker, &data);
        pthread_join(thread, NULL);

        pthread_create(&thread, NULL, &worker, &data);
        pthread_join(thread, NULL);

        wait(&status);  // wait for child to finish
    }

    return 0;
}
