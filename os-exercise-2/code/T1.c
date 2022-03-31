#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include <errno.h>
#include <string.h>

#define SIZE 10000

void swap(int *xp, int *yp);
void sort(int arr[], int size);

int main ()
{
	int arr[SIZE];         
	for(int i=SIZE-1;i>=0;i--)
		if(i%2==0)
			arr[(SIZE-1)-i]=0;
		else
			arr[(SIZE-1)-i]=1;
	sort(arr, SIZE);

	// create shared memory
	errno = 0;
	int file_desc = shm_open("/reg", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (file_desc < 0) {
		return errno;
	}

	// truncate to length of one float
	if (ftruncate(file_desc, sizeof(float)) < 0) {
		return -1;
	}

	// map memory
	void *reg_ptr = mmap(NULL, sizeof(float), PROT_READ | PROT_WRITE, MAP_SHARED, file_desc, 0);
	if (reg_ptr = MAP_FAILED) {
		printf("check\n");
		return -1;
	}

	// fork another process here
	int pid = fork();
	if (pid < 0) {
		return -1;
	}

	// parent calculates the mean, the child calculates the median
	float mean = 0;
	if (fork == 0) {
		// child
		// calculate median value
		reg_ptr = (int *) &arr[(SIZE-1)/2];

		// one process should communicate its value to the other process

	} else {
		// parent
		// calculate mean value
		for (int i = 0; i < SIZE-1; i++) {
			mean += arr[i];
		}
		mean /= SIZE;
	}

	// The other process should print both calculated results
	printf("The child with id %d calculated a median of %f", pid, *(int *) reg_ptr);
	printf("The parent calculated a mean of %f", mean);

	// unmap memory
	munmap(reg_ptr, sizeof(float));

	return 0;
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


