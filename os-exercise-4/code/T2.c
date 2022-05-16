#include <stdio.h>
#include <stdlib.h>

int readLinesCount(const char * str) {
	//TODO implement readlinesCount which returns the total number of lines within the input file
	FILE *fp = fopen(str, "r");
	int ch = 0;
	int lines = 0;
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n') {
			lines++;
		}
	}
	fclose(fp);
	return lines;
}
void writeLinesCount(const char * str, int count_line) {
	//TODO implement writeLinesCount which writes a new line in file str has count_line
	FILE *fp = fopen(str, "a");
	char str_count[10];
	sprintf(str_count, "%d\n", count_line);
	fprintf(fp, str_count);
	fclose(fp);
}
int main(int argc, char * argv[])
{
	
	int files_count=atoi(argv[1]);
	int i=0;
	while(i<files_count){
		int num_lines=readLinesCount(argv[2+i]);
		writeLinesCount("output.txt", num_lines);
		i++;
	}

}
