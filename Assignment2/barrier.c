#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common_threads.h"

// If done correctly, each child should print their "before" message
// before either prints their "after" message. Test by adding sleep(1)
// calls in various locations.

// You likely need two semaphores to do this correctly, and some
// other integers to track things.

typedef struct __barrier_t {
    // add semaphores and other information here
    sem_t s1, countS;
    int count;
    int numT;

} barrier_t;


// the single barrier we are using for this program
barrier_t b;

void barrier_init(barrier_t *b, int num_threads) {
    // initialization code goes here
    sem_init(&b->s1, 0, 0);
    sem_init(&b->countS, 0, 1);
    b->count = 0;
    b->numT = num_threads;
}

void barrier(barrier_t *b) {
    // barrier code goes here
    sem_wait(&b->countS); // Only let 1 thread access this portion at a time.
    
    b->count++;

    // Check if all threads have entered the barrier.
    if(b->count == b->numT) 
    {
        sem_post(&b->countS);
    }
    else
    {
        sem_post(&b->countS);
        sem_wait(&b->s1);
    }

    // Start the next portion, once all threads have entered the barrier.
    sem_wait(&b->countS);
    b->count--;
    sem_post(&b->countS);

    for(int i = 0; i < b->count; i++)
    {
        sem_post(&b->s1);
    } 
}

//
// XXX: don't change below here (just run it!)
//
typedef struct __tinfo_t {
    int thread_id;
} tinfo_t;

void *child(void *arg) {
    tinfo_t *t = (tinfo_t *) arg;
    printf("child %d: before\n", t->thread_id);
    barrier(&b);
    printf("child %d: after\n", t->thread_id);
    return NULL;
}


// run with a single argument indicating the number of 
// threads you wish to create (1 or more)
int main(int argc, char *argv[]) {
    assert(argc == 2);
    int num_threads = atoi(argv[1]);
    assert(num_threads > 0);

    pthread_t p[num_threads];
    tinfo_t t[num_threads];

    printf("parent: begin\n");
    barrier_init(&b, num_threads);
    
    int i;
    for (i = 0; i < num_threads; i++) {
	t[i].thread_id = i;
	Pthread_create(&p[i], NULL, child, &t[i]);
    }

    for (i = 0; i < num_threads; i++) 
	Pthread_join(p[i], NULL);

    printf("parent: end\n");
    return 0;
}

