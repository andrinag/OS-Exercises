#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define SIZE 10000

void swap(int *xp, int *yp);
void sort(int arr[], int size);

// function to run in thread
void* calc_mean(void* arg) {
	// convert void pointer to int pointer
	int* arr = (int *) arg;
	// malloc variable for result
	float* mean = malloc(sizeof(mean));
	// calculate mean
	for (int i = 0; i < SIZE-1; i++) {
		*mean += arr[i];
	}
	*mean /= SIZE;
	return mean;
}

// main function
int main (){
        int arr[SIZE];
        for(int i=SIZE-1;i>=0;i--)
                if(i%2==0)
                        arr[(SIZE-1)-i]=0;
                else
                        arr[(SIZE-1)-i]=1;
	sort(arr, SIZE);

	// calculate mean in new thread
	float* mean = NULL;
	pthread_t tid;
	pthread_create(&tid, NULL, calc_mean,&arr);
	pthread_join(tid, (void**)&mean);

	// calculate median in min thread
	int median = arr[(SIZE-1)/2];

	// One thread should display the result (mean, median)
	printf("The thread with TID %u calculated a mean on %f.\n", tid, *mean);
	free(mean);
	printf("The main thread calculated a median of %d.\n", median);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int *arr, int size)
{
   int i, j;
   for (i = 0; i < size-1; i++)    
  
       // Last i elements are already in place   
       for (j = 0; j < size-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
