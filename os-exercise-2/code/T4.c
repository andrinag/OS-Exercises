#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
struct process{
	int process_id;
	int arrival_time;
	int execution_time;
	int start_time;
};

void init_processes(struct process *);
void display(struct process *);
void display_average_waiting_time(struct process *);
void schedule_FCFS(struct process *);
void schedule_SJF(struct process *);
void schedule_LSF(struct process *);
void set_arrival_zero(struct process *);

int main()
{
	// PRE
	struct process processes[SIZE];
	init_processes(processes);

	printf("Orignial input (processes)\n");
	display(processes);

	// FCFS
	schedule_FCFS(processes);
	printf("Execution according to FCFS policy\n");
	display(processes);
	display_average_waiting_time(processes);

	// set arrival times to 0 as stated in exercise
	set_arrival_zero(processes);

	// SJF
	schedule_SJF(processes);
        printf("Execution according to SJF policy\n");
        display(processes);
        display_average_waiting_time(processes);

	// LSF
	schedule_LSF(processes);
        printf("Execution according to LSF policy\n");
        display(processes);
        display_average_waiting_time(processes);

}
void init_processes(struct process * input)
{
	srand(100);
	for(int i=0;i<SIZE;i++)
	{
		input[i].arrival_time = rand()%10;
		input[i].execution_time = rand()%10;
		input[i].process_id= i;
		input[i].start_time=-1;
	}
}

void display(struct process * input){
	printf("process<id, arr, exe, start>:");
	for(int i=0;i<SIZE;i++)
	{
		printf("<%d,%d,%d,%d> ",  input[i].process_id,
		 input[i].arrival_time,  input[i].execution_time, input[i].start_time);	
	}
	printf("\n");
}

// swaps two processes in an array
void swap_processes(struct process *xp, struct process *yp)
{
        struct process temp = *xp;
        *xp = *yp;
        *yp = temp;
}

// sorts processes by arrival time
void sort_by_arrival(struct process *arr, int size)
{
        int i, j;
        for (i = 0; i < (size-1); i++) {
                for (j = 0; j < size-i-1; j++){
                        if (arr[j].arrival_time > arr[j+1].arrival_time){
                                swap_processes(&arr[j], &arr[j+1]);
			}
		}
	}
}

// sorts processes by ascending execution time
void sort_by_exec_asc(struct process *arr, int size)
{
        int i, j;
        for (i = 0; i < (size-1); i++) {
                for (j = 0; j < size-i-1; j++){
                        if (arr[j].execution_time > arr[j+1].execution_time){
                                swap_processes(&arr[j], &arr[j+1]);
                        }
                }
        }
}

// sorts processes by decending execution time
void sort_by_exec_desc(struct process *arr, int size)
{
        int i, j;
        for (i = 0; i < (size-1); i++) {
                for (j = 0; j < size-i-1; j++){
                        if (arr[j].execution_time < arr[j+1].execution_time){
                                swap_processes(&arr[j], &arr[j+1]);
                        }
                }
        }
}

// sets the arrival time of all processes to zero
void set_arrival_zero (struct process *arr) {
	for (int i = 0; i < SIZE; i++) {
                arr[i].arrival_time = 0;
        }
}


// returns the larger one of two numbers
int max(int first, int second) {
	return (first > second ) ? first : second;
}

void schedule_FCFS(struct process * arr)
{
	// sort by arrival time
	sort_by_arrival(arr, SIZE);
	// calculate start times
	arr[0].start_time = arr[0].arrival_time;
	for (int i = 1; i < SIZE; i++) {
		int after_exec_time = arr[i-1].start_time + arr[i-1].execution_time;
		arr[i].start_time = max(arr[i].arrival_time, after_exec_time);
	}
}

void schedule_SJF(struct process * arr)
{
        // sort by arrival time
        sort_by_exec_asc(arr, SIZE);
        // calculate start times
        arr[0].start_time = arr[0].arrival_time;
        for (int i = 1; i < SIZE; i++) {
                arr[i].start_time = arr[i-1].start_time + arr[i-1].execution_time;
        }
}

void schedule_LSF(struct process * arr)
{
        // sort by arrival time
        sort_by_exec_desc(arr, SIZE);
        // calculate start times
        arr[0].start_time = arr[0].arrival_time;
        for (int i = 1; i < SIZE; i++) {
                arr[i].start_time = arr[i-1].start_time + arr[i-1].execution_time;
        }
}

void display_average_waiting_time(struct process * arr)
{
	float wait_time = 0;
	for (int i = 0; i < SIZE; i++) {
                wait_time += arr[i].start_time - arr[i].arrival_time;
        }
	wait_time /= SIZE;
	printf("Processes wait an average time of %f\n", wait_time);
}
