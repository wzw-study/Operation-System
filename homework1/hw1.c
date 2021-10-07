#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>


void generateData(void** array, int n, int m, int flag){
    /* generate random data
   the array size is n
   the number range size is M
   flag is the data type 1 is integers 0 strings
   */
  srand((unsigned)time(NULL));
  if (flag){
    *array = malloc(sizeof(int)*n);
    int *head = (int*) *array;
    for (int i = 0; i< n; i++){
      int num = rand() % m + 1;
      *head = num;
      head ++;
    }}else{
    *array = malloc(sizeof(char) * n);
    char* head = (char*) *array;
    for (int i = 0; i < n;i++){
      int num = rand() % 26;
      *head = (char)'A'+num;
      head++;
    }
    }
}

void calculate(int element, int target[], int length){
  /*
  Single process calculation of execution time
  */

    struct timeval start, end;
    int count = 0;
    gettimeofday(&start, NULL);
    for (int i = 0; i< length; i++){
        if (target[i] == element){
          count += 1;
        }
    }
    gettimeofday(&end, NULL);
    unsigned long duringTime = (end.tv_sec-start.tv_sec) * 1000000 + (end.tv_usec-start.tv_usec);
    printf("the elemet number is: %d\nthe time using is: %ld microsecond\n", count, duringTime);
}
int main()
{
    void *num;
    int n = 100000;
    int m = 500;
    generateData(&num, n, m, 1);
    calculate(105, (int *)num, n);
    free(num);
    return 0;
}
