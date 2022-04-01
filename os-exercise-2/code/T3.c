#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define SIZE 10000
#define NUM_THREADS 5
int result;
pthread_mutex_t lock;

struct args
{
	int* arr;
	int start;
	int end;
};

void * accumulate(void * in)
{
	struct args* targs = (struct args *) in;
	int sum = 0;
	for (int i = targs->start; i < targs->end; i++) {
		sum += targs->arr[i];
	}
	printf("i'm a thread and got %i\n", sum);
	while(pthread_mutex_trylock(&lock)!=0);
	result += sum;
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main () {
	result=0;
        int arr[SIZE];
        for(int i=0;i<SIZE;i++)
		arr[i]=1;

	pthread_t threads[NUM_THREADS-1];
	struct args thread_args[NUM_THREADS-1];

	// create a team of thread, each thread must take SIZE/NUM_THREADS to accumulate
	for (int i = 1; i < NUM_THREADS; i++) {
                // set values of args struct
		thread_args[i].arr = arr;
		thread_args[i].start = (SIZE / NUM_THREADS) * i;
		thread_args[i].end = ((SIZE / NUM_THREADS) * (i+1));
		//create thread
		pthread_create(&threads[i], NULL, accumulate,&thread_args[i]);
        }

	// main thread must participate in the calculation
	int sum = 0;
	for (int i = 0; i < (SIZE / NUM_THREADS); i++) {
		sum += arr[i];
		//printf("index is %d::::: end is %f", i, SIZE / NUM_THREADS);
	}
	printf("i'm the main thread and got %i\n", sum);
	while(pthread_mutex_trylock(&lock)!=0);
        result += sum;
        pthread_mutex_unlock(&lock);

	//make sure all threads finised
	for (int i = 1; i < NUM_THREADS; i++) {
                //create thread
                pthread_join(threads[i], NULL);
        }
	printf("sum  is %d\n", result);
}

