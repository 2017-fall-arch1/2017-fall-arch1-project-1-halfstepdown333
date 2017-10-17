#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "BST.h"

char* printFile(char* c){ //Prints Text File
  
  FILE* f;
  f=fopen(c,"r");
static char readLine[150];

  while(!feof(f)){
    fgets(readLine,150,f);
    printf("%s\n",readLine);
  }
  fclose(f);
}


struct Node* addUser(char* c,char* u){    //adds test to txt file
  FILE* f;
  f=fopen(c,"a");
  fputs(u,f);
  fputs("\n",f);
  fclose(f);
 }
struct Node* addToTree(struct Node*r,char* x){ //adds to tree
  FILE* f;
  static char read[150];
  f=fopen(x,"r+");
  
  while(fgets(read,150,f)){
    r=Insert(r,read);
    printf("%s\n",read);
  }
  
  fclose(f);
}  

int main(){
  
  char* file="ACME.txt";
  int input;
  char* users;
  struct Node* root=NULL;


  while(1){    //switch cases for user input
  printf("What Action Would You Like To Take?\n1=ADD USER\n2=PRINT FILE\n0=Exit and display Tree\n");
  scanf("%d",&input);
  
  switch(input){
  case 0: goto endwhile;
  case 1:
    printf("NAME OF USER TO ADD?");
    scanf("%s",users);
    addUser(file,users);
    break;
  case 2:
    printFile(file);
   break;
  default:;
  }
  }
 endwhile:;
  root=addToTree(root,file); //Creates Binary tree with text lines on file
  printBST(root,0);
  return 0;


  //root=Insert(root,"Brittany");
  //root=Insert(root,"Gustavo")
  //inOrder(root);     print
  //printBST(root,0);  print
  //root=Remove(root,"Gustavo");
  //printBST(root,0);
}
