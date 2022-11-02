#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/time.h>
#include "assignment7.h"


char *getNextWord(FILE *fd);

int main(int argc, char **argv) {
	FILE *fp = fopen(argv[1], "r");
	assert(fp != NULL);
	char *arr[10000];

	struct timeval start, end;
	char *newWord;
	int index = 0;
	while ( ((newWord = getNextWord(fp)) != NULL) && index < 10000) {
		arr[index] = calloc(1,strlen(newWord)+1);
		strcpy(arr[index], newWord);
		index++;
	}
	setSortThreads(2);

	gettimeofday(&start, NULL);
	sortThreaded(arr, index);
	gettimeofday(&end, NULL);

	int elapsed = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
	printf("Time taken to sort: %dms\n", elapsed);
}
