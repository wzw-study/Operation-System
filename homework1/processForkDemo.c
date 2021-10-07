#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() { printf("Hello world(pid: %d)\n", (int)getpid());
  int rc = fock();
  if (rc<0){
      //fock faied
      fprintf(stderr, "fock failed\n");
      exit(1);
  }
  else if(rc == 0){
    printf("hello I am child(pid: %d)\n", (int)getpid());
  }
  else{
    printf("hello I am parent of %d, my pid: %d\n", rc,(int)getpid());
  }
}