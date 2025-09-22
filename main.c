#include <stdio.h>
#include <pthread.h>    // for pthread_t, pthread_create
#include <sys/types.h>  // for pid_t
#include <unistd.h>

void* identify(void* arg) {
    pid_t pid = getpid();
    printf ("My pid is %d\n", pid);
    return NULL;
}
int main () {
    pthread_t thread;
    pthread_create(&thread, NULL, &identify, NULL);
    identify(NULL);
    return 0;
}