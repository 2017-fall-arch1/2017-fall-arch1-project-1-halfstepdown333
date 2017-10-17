#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "BST.h"

char* printFile(char* c){
  
  FILE* f;
  f=fopen(c,"r");
static char readLine[150];

  while(!feof(f)){
    fgets(readLine,150,f);
    printf("%s\n",readLine);
  }
  fclose(f);
}


struct Node* addUser(char* c,char* u){
  FILE* f;
  f=fopen(c,"a");
  fputs(u,f);
  fputs("\n",f);
  fclose(f);
  
}

void main(){
  char* file;
  int input;
  static char users[30];
  struct Node* root=NULL;
  
  file=("ACME.txt");


  printf("What Action Would You Like To Take?\n1=ADD USER\n2=PRINT FILE\n");
  scanf("%d",&input);
  
  switch(input){

  case 1:
    printf("NAME OF USER TO ADD?");
    scanf("%s",users);
    addUser(file,users);
    root=Insert(root,users);
    break;
  case 2:
    printFile(file);
    break;

  }
  
  inOrder(root);
}
