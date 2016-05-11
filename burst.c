#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

typedef struct{
int maxsize;
int numSessions;
int splitSize;
int low;
int high;
char filename;
}threadData;
int chars;
int lines;
threadData tData;


int countLines(char *argv[], int low, int high){
	FILE *fp = fopen(argv[1],"r");
	int ch;
	lines = 0;
	chars = 0;

		do{
		ch = fgetc(fp);
		if(lines >= low && lines < high){
		chars++;
		}
		if (ch== '\n'){
		lines++;
		}
		if (lines > low && lines < high){
		chars++;
		}
		}
		while( ch != EOF);

printf("this many %d\n",chars);

return chars;

}


double numberSessions(int Lines, int split){
tData.numSessions = (Lines/split);
}


void *burst(void *args){
int fd;
	int i = (int) args;
	fd = open("this", O_RDONLY);
int size = tData.high - tData.low;
 
printf("%d\n",size);

char buf[size];

//	pthread_id_np_t tid;
//	tid = pthread_getthreadid_np();	
	
//	read(tid*i, i*tid+1)

		if (fd == -1){
		printf("problem");
		exit(1);
		}


//printf("this many %d\n", i);


close(fd);
}

void createThreads(char *argv[])
{int prev =0;
 int n = 0;	
pthread_t * thread = malloc(sizeof(pthread_t)*10);

	for (int i = 0; i < 5; i++){
prev = n;
tData.low = prev;	
printf("prev%d\n", prev);
n = countLines( argv,(i*tData.splitSize) ,((i+1) *tData.splitSize));
n = n+prev;
tData.high = n;
printf("n%d\n", tData.high);


	int ret = pthread_create((&thread[i]), NULL, *burst, n); 
		pthread_join(thread[i],NULL);

			if(ret = 0){
				printf("error");
				exit(1);
				}

		}

}

int main(int argc, char *argv[]){
	int fd;
	fd = open( argv[1], O_RDONLY);

	if (fd == -1){
	printf("Failed to open.\n");
}

printf("%s\n",argv[1]);
tData.splitSize = strtol(argv[2], NULL, 0);
printf("%d\n",tData.splitSize);

//printf("%d\n",countLines((argv[1]),2,0));
	close(fd);
	createThreads( argv);
	return 0;
};





/*
//function to add file number on end of split file
char* addstr(const char* a, const char* b){
size_t len = strlen(a) + strlen(b);
char *ret = (char*)malloc(len * sizeof(char) +1;
*ret = '\0';

return strcat(strcat(ret,a), b);

}
*/
