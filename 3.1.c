#include <stdio.h>
#include <pthread.h>

void *helper(void *arg) {
    printf("HELPER\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, &helper, NULL);
    pthread_self();
    printf("MAIN\n");
    return 0;
}
