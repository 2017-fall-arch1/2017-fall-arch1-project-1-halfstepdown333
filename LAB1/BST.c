#define space 10
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "searchTree.h"


struct Node* BNode(char* data){

  struct Node* node=(struct Node*)malloc(sizeof(node));
  node->data=data;
  node->left=node->right=NULL;
  return node;
}

struct Node* Insert(struct Node* x,char* data){
  if(x == NULL){              
    x = BNode(data);
  }
  else if(strcmp(x->data,data)<0){
    x ->left= Insert(x -> left,data);
  }
  else{
    x->right= Insert(x->right,data);
  }
  return x;
}

struct Node* Remove(struct Node* r,char* data){
  if(r==NULL)
    return NULL;

  if (strcmp(r->data,data)<0){
    r->left=Remove(r->left,data);
  }
  else if(strcmp(r->data,data)>0){
    r->right=Remove(r->right,data);
  }
  else{
    if(r->left==NULL && r->right==NULL){
      remove(r);
      r=NULL;
    }
    else if(r->left ==NULL){
      struct Node* temp=r;
      r=r->right;
      free(temp);
    }
    else if(r->right==NULL){
      struct Node* temp=r;
      r=r->left;
      free(temp);
    }
    else{
      struct Node* temp= findMax(r->right);
      r->data=temp->data;
      r->right=Remove(r->right,temp->data);
    }
  }
  return r;
}

_Bool find(struct Node* r,char* data){
  if(r == NULL){
    return false;
  }
    else if(r->data==data){
      return true;
    }
    else if(strcmp(r->data,data)<0){
      return find(r->left,data);
    }
    else
      return find(r->right,data); 
}

char findMax(struct Node* r){
  if(r->right != NULL)
    return findMax(r->right);
  return r->value;
  
}

void inOrder(struct Node*r){
  if(r==NULL)
    return;
  
    inOrder(r->right);
    printf("%s\n",r->data);
    inOrder(r->left);
  
}

void printBST(struct Node* r,int s){
  if(r==NULL){
    return;
  }

  s+=space;
  printBST(r->right, s);
  printf("\n");
  for(int i=space;i<s;i++){
    printf(" ");
  }
  printf("%s\n",r->data);
  printBST(r->left,s);
}
