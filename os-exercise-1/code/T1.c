#include<stdlib.h>
#include<stdio.h>

int get_frequency(int *, int, int);
void display_results(int param1);

int main(int argc, char *argv[]) {
	int total_size=1000;
	int search_size=1000;
	int target=5;
	// allocation
	int * input_data = (int *) malloc(total_size * sizeof(int));

	// initialization
	for (int i = 0; i < total_size; i++)
		input_data[i]=1;

	// usage 1
	printf("Search for target %d\n",5);
	int res = get_frequency(input_data, 10, 5);
	display_results(res); // could not find target

	// usage 2
	printf("Search for target %d\n",1);
	res = get_frequency(input_data, 1000, 1);
	display_results(res); // target has been found 1000
	free(input_data); 

	return 0;
}

int get_frequency(int * input, int length, int target) {
	int frequency = 0;
	for (int * pointer = input; pointer < input + length; ++pointer) {
		if (*pointer == target) {
			frequency++;
		}
	}
	if (!frequency) {
		frequency--;
	}
	return frequency;
}

void display_results(int param1){
	switch(param1) {
		case -1:
			printf("could not find target\n");
			break;
		default:
			printf("target has been found %d\n", param1);
	}
}
