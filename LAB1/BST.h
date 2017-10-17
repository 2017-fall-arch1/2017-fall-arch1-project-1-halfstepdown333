#ifndef searchTree
#include<string.h>
#define searchTree

struct Node{
  char* data;
  struct Node* left;
  struct Node* right;
  struct Node* value;
  
};

struct Node* Bnode(char* data);
struct Node* Insert(struct Node* x, char* data);
struct Node* Remove(struct Node* r, char* data);
_Bool find(struct Node* r, char* data);
char findMax(struct Node* r);
void printBST(struct Node* r,int s);
void inOrder(struct Node* r);

#endif
