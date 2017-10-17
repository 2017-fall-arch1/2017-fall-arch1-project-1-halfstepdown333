#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "searchTree.h"

char* printFile(char* c){
  
  FILE* f;
  f=fopen("c","r");
  char readLine[150];

  while(!feof(f)){
    fgets(readLine,150,f);
    printf("%s\n",readLine);
  }
  fclose(f);
}

int main(){

 
  
  return 0;
}
