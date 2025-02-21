#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cr = PTHREAD_COND_INITIALIZER;
pthread_cond_t cw = PTHREAD_COND_INITIALIZER;

int nr = 0; // Number of readers currently reading
int w = 0;     // 1 if a writer is currently writing, 0 otherwise

void writer() {
    pthread_mutex_lock(&m);
    while (w || nr > 0) {
        pthread_cond_wait(&cw, &m);
    }
    w = 1;
    pthread_mutex_unlock(&m);

    printf("Writer starts writing.\n");
    sleep(2);
    printf("Writer finishes writing.\n");

    pthread_mutex_lock(&m);
    w = 0;
    pthread_cond_broadcast(&cr);
    pthread_cond_signal(&cw);
    pthread_mutex_unlock(&m);
}

void reader() {
    pthread_mutex_lock(&m);
    while (w) {
        pthread_cond_wait(&cr, &m);
    }
    nr++;
    pthread_mutex_unlock(&m);

    printf("Reader starts reading.\n");
    sleep(1);
    printf("Reader finishes reading.\n");

    pthread_mutex_lock(&m);
    nr--;
    if (nr == 0) {
        pthread_cond_signal(&cw);
    }
    pthread_mutex_unlock(&m);
}

int main() {
    int c;
        printf("-----READERS WRITERS PROBLEM-----");
        printf("\n1. Start Writer\n");
        printf("2. Start Reader\n");
        printf("3. Exit\n");
    while (1) {

        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                writer();
                break;
            case 2:
                reader();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
