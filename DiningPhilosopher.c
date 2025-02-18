#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_PHILOSOPHERS 5

sem_t chops[NUM_PHILOSOPHERS];

void think(int id) {
    printf("Philosopher %d is thinking\n", id);
    sleep(1); // Simulate thinking time
}

void eat(int id) {
    printf("Philosopher %d is eating\n", id);
    sleep(2); // Simulate eating time
}

void *philosopher(void *arg) {
    int id = (int)arg;

    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        think(id);

        if (id % 2 == 0) {
            sem_wait(&chops[left]);
            sem_wait(&chops[right]);
        } else {
            sem_wait(&chops[right]);
            sem_wait(&chops[left]);
        }

        eat(id);

        sem_post(&chops[left]);
        sem_post(&chops[right]);
    }
}

int main() {
    pthread_t threads[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&chops[i], 0, 1);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&threads[i], NULL, philosopher, (void *)i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&chops[i]);
    }

    return 0;
}
