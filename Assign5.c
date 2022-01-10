//Nicholas Wade
//COSC 4302 Assignment 5

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *thread1();

void *thread2();

int counter=0;

sem_t semaphore;

int main() {

     pthread_t t1;
     pthread_t t2;

     sem_init(&semaphore, 0, 1);

     pthread_create(&t1, NULL, thread1, NULL);
     pthread_create(&t2, NULL, thread2, NULL);


     pthread_join(t1, NULL);  
     pthread_join(t2, NULL);


     sem_destroy(&semaphore);
}

void *thread1() {

     while(1) {   

          sem_wait(&semaphore);

          counter++;

          printf("\nCurrent counter value in thread1: %d\n", counter);

          sem_post(&semaphore);

          sleep(1);

     }
}

void *thread2() {

     while(1) {

          sem_wait(&semaphore);

          counter--;

          printf("\nCurrent counter value in thread2: %d\n", counter);

          sem_post(&semaphore);

          sleep(1);

     }   
}

