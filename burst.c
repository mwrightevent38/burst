#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

typedef struct{
int maxsize;
int numSessions;
int splitSize;
int threadnum;
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
		if (ch== '\n'){
		lines++;
		}
		if (lines >= low && lines < high){
		chars++;
		}
		}
		while( ch != EOF);

printf("%d\n",chars);
numberSessions(lines, tData.splitSize);
return chars;

}


void numberSessions(int Lines, int split){
int t = (int)((lines/split)+1);
tData.numSessions = t;

}



void *burst(void *argv[]){
int fd;
char c[100];
sprintf(c,argv[1]);
printf("%d\n",tData.threadnum);	

sprintf(c,"%d",tData.threadnum);	


	fd = open(argv[1], O_RDONLY);

int size = tData.high - tData.low;
 
//printf("%d\n",size);

char buf[size];

pread(fd, buf, size, tData.low);


		if (fd == -1){
		printf("problem");
		exit(1);
		}


//printf("this many %d\n", i);
close(fd);


fd = open(c, O_CREAT | O_WRONLY, 0600);
if (fd == -1){
printf("failed");
}
write(fd, buf, size);

}

void createThreads(char *argv[])
{int prev =0;
 int n = 0;	
pthread_t * thread = malloc(sizeof(pthread_t)*10);

	for (int i = 0; i < tData.numSessions; i++){
tData.threadnum = i;
prev = n;
tData.low = prev;	
printf("prev%d\n", prev);
n = countLines( argv,(i*tData.splitSize) ,((i+1) *tData.splitSize));
n = n+prev;
tData.high = n;



	int ret = pthread_create((&thread[i]), NULL, *burst, argv); 
		pthread_join(thread[i],NULL);

			if(ret = 0){
				printf("error");
				exit(1);
				}

		}

}

int main(int argc, char *argv[]){

if(argc == 2){
tData.splitSize = strtol("500",NULL,0);
printf("argc = %d\n", argc);

}
if (argc <= 3){
tData.filename = argv[1];
}
if (argc == 3){
tData.splitSize = strtol(argv[2], NULL, 0);
printf("equal 2");

}
countLines(argv ,0,1);

	createThreads( argv);
	return 0;
};





